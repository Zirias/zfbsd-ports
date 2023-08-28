# Ports Linux compatibility built from source
#
# Feature:      linuxsrc
# Usage:        USES=linuxsrc[:ARGS]
# Valid ARGS:   [mode],archs,man
#
# [mode]        the mode of the default configuration for this port, one of:
#               env	-- no build configuration, just define variables
#		leaf	-- a port using Linux, but installed outside LINUXBASE
#		dist	-- a port installed in LINUXBASE
#		base	-- a port that's part of the base userland
#		dev	-- a port for one of the development tools
#		tchain	-- a port for a part of the native toolchain
#		cross	-- a port for a part of the cross toolchain
#		boot	-- a port for bootstrapping the cross toolchain
#
#		When no mode is given, it defaults to "leaf".
#		Use "leaf" or "env" for porting some Linux application.
#		Use "dist" for porting some Linux library.
#		All other modes are only needed while building the base
#		Linuxulator userland.
#
#		The "dist" and "leaf" modes also configure the port to use
#		GNU make and GNU bash from the Linuxulator userland for
#		building, as well as other build tools that might be
#		required. Configuration for the following USES is
#		automatically adjusted:
#		autoreconf, cmake, meson, ninja.
#
# archs		Also add PLIST_SUB entries for the supported architectures:
#		%%AARCH64%%, %%NO_AARCH64%%
#		%%AMD64%%, %%NO_AMD64%%
#		%%I386%%, %%NO_I386%%
#		This is implicit in the modes "boot", "cross" and "tchain"
#
# man		Update the Linux man-db on installation and removal of this
#		port. Use this when the port is installing manpages.
#
# Port variables:
# USE_LINUXSRC          List of extra Linux packages to depend on, with
#			optional ':build' and ':run' suffixes (defaults to
#			both).
#
# LINUXSRC_PREFIX	The prefix to use inside LINUXBASE (default: /usr)
# LINUXSRC_CC		The C compiler to use when building with Linux make
#			(default: gcc)
# LINUXSRC_CXX		The C++ compiler to use when building with Linux make
#			(default: g++)
# LINUXSRC_LIBDIR	Where to install libraries, relative to LINUXBASE,
#			automatically passed to GNU configure
#			(default: ${LINUXSRC_PREFIX}/${LINUXSRC_LIBDIRNAME})
# LINUXSRC_SYSCONFDIR	Where to install configuration files, relative to
#			LINUXBASE, automatically passed to GNU configure
#			(default: /etc)
# LINUXSRC_PKGCONFIGDIR	Where to look for pkg-config files
#			(default: /usr/${LINUXSRC_LIBDIRNAME}/pkgconfig)
# LXCROSSBASE		Prefix for the cross toolchain
#			(default: ${LOCALBASE}/linux-cross)
# LXBOOTSTRAP		Prefix for the cross toolchain bootstrapping tools
#			(default: ${LXCROSSBASE}/bootstrap)
#
# Additional variables defined:
# LINUXSRC_ARCH		Name of the architecture translated to Linux naming
# LINUXSRC_TRIPLET	Target triplet used for the Linux toolchain
# LINUXSRC_BUILDTRIPLET	Target triplet used for building native FreeBSD
#			components
# LINUXSRC_LIBDIRNAME	"lib" on 32bit architectures, "lib64" otherwise
# LINUXSRC_V_*		Versions of toolchain components
#
# Additional pkg-plist substitutions:
# LXARCH		Expands to ${LINUXSRC_ARCH}
# LXTRIPLET		Expands to ${LINUXSRC_TRIPLET}
# LXLIBDIRNAME		Expands to ${LINUXSRC_LIBDIRNAME}
#
# MAINTAINER: zirias@FreeBSD.org

.ifndef _INCLUDE_USES_LINUXSRC_MK
_INCLUDE_USES_LINUXSRC_MK=	yes
_USES_POST+=			linuxsrc

# toolchain versions
LINUXSRC_V_BINUTILS=	2.41
LINUXSRC_V_GCC=		13.2.0
LINUXSRC_V_GLIBC=	2.38
LINUXSRC_V_GMP=		6.3.0
LINUXSRC_V_MPC=		1.3.1
LINUXSRC_V_MPFR=	4.2.0

# optional components
_linuxsrc_expat=	textproc:expat
_linuxsrc_libarchive=	archivers:libarchive
_linuxsrc_libffi=	devel:libffi
_linuxsrc_libuuid=	devel:libuuid
_linuxsrc_ninja=	devel:ninja
_linuxsrc_pysetup=	devel:py-setuptools
_linuxsrc_python=	lang:python
_linuxsrc_sqlite=	databases:sqlite3
_linuxsrc_tcl=		lang:tcl

# standard Linux variables
LINUXSRC_ARCH=		${ARCH:S/amd64/x86_64/}
LINUXSRC_TRIPLET=	${LINUXSRC_ARCH:S/i386/i686/}-freebsd-linux-gnu
LINUXSRC_BUILDTRIPLET=	${LINUXSRC_ARCH}-portbld-${OPSYS:tl}${OSREL}
LINUXSRC_LIBDIRNAME=	lib${"${ARCH:Mi386}":?:64}

# standard Linux paths, overridable
LINUXSRC_PREFIX?=	/usr
LINUXSRC_LIBDIR?=	${LINUXSRC_PREFIX}/${LINUXSRC_LIBDIRNAME}
LINUXSRC_SYSCONFDIR?=	/etc
LINUXSRC_PKGCONFIGDIR?=	/usr/${LINUXSRC_LIBDIRNAME}/pkgconfig

# cross toolchain prefixes, overridable
LXCROSSBASE?=	${LOCALBASE}/linux-cross
LXBOOTSTRAP?=	${LXCROSSBASE}/bootstrap

IGNORE_FreeBSD_12=	the "linuxsrc" userland needs FreeBSD 13 or newer

# sanity-check architectures, default to those supported by Linuxulator
.  ifdef ONLY_FOR_ARCHS
_linuxsrc_bad_archs=	${ONLY_FOR_ARCHS:Naarch64:Namd64:Ni386}
.    if !empty(_linuxsrc_bad_archs)
IGNORE?=	USES=linuxsrc: Unsupported architecture(s):\
		${_linuxsrc_bad_archs:O:ts,}
.    endif
.  else
ONLY_FOR_ARCHS=	aarch64 amd64 i386
.  endif
ONLY_FOR_ARCHS_REASON?=	no Linuxulator support

# sanity-check requested Linux kernel ABI version
.  if ${LINUXKERNEL_DEFAULT:N4.4:N5.15}
IGNORE?=	USES=linuxsrc: unsupported Linux kernel ABI version:\
		${LINUXKERNEL_DEFAULT}
.  endif

# check arguments, determine selected configuration mode, default to "leaf"
_linuxsrc_unknown_args=	${linuxsrc_ARGS:Narchs:Nman}
_linuxsrc_given_modes=	#
_linuxsrc_modes=	base boot cross dev dist env leaf tchain
_linuxsrc_mode=		#
.  for _mode in ${_linuxsrc_modes}
.    if ${linuxsrc_ARGS:M${_mode}}
_linuxsrc_unknown_args:=	${_linuxsrc_unknown_args:N${_mode}}
_linuxsrc_given_modes+=		${_mode}
.      if empty(_linuxsrc_mode)
_linuxsrc_mode=			${_mode}
.      endif
.    endif
.  endfor
.  if empty(_linuxsrc_mode)
_linuxsrc_mode=			leaf
.  endif
.  if ${_linuxsrc_given_modes:N${_linuxsrc_mode}}
IGNORE?=	Incorrect USES=linuxsrc: multiple modes\
		(${_linuxsrc_given_modes:O:ts,})
.  elif !empty(_linuxsrc_unknown_args)
IGNORE?=	Incorrect USES=linuxsrc: unknown args\
		(${_linuxsrc_unknown_args:O:ts,})
.  endif

# add PLIST_SUB entries for archs if requested
_linuxsrc_archs_implied=	boot cross tchain
.  if ${linuxsrc_ARGS:Marchs} || ${_linuxsrc_archs_implied:M${_linuxsrc_mode}}
.    if ${ARCH} == amd64
PLIST_SUB+=	AMD64="" NO_AMD64="@comment _nonexisting/"
.    else
PLIST_SUB+=	AMD64="@comment _nonexisting/" NO_AMD64=""
.    endif
.    if ${ARCH} == aarch64
PLIST_SUB+=	AARCH64="" NO_AARCH64="@comment _nonexisting/"
.    else
PLIST_SUB+=	AARCH64="@comment _nonexisting/" NO_AARCH64=""
.    endif
.    if ${ARCH} == i386
PLIST_SUB+=	I386="" NO_I386="@comment _nonexisting/"
.    else
PLIST_SUB+=	I386="@comment _nonexisting/" NO_I386=""
.    endif
.  endif

# add a few standard variables to PLIST_SUB
PLIST_SUB+=	LXARCH=${LINUXSRC_ARCH} \
		LXTRIPLET=${LINUXSRC_TRIPLET} \
		LXLIBDIRNAME=${LINUXSRC_LIBDIRNAME}

# Anything installing to LINUXBASE conflicts with Linux-c7 packages
.  if ${_linuxsrc_mode:Nboot:Ncross:Nleaf}
CONFLICTS+=	linux_base-c7 linux-c7-*
.  endif

.  if ${_linuxsrc_mode:Nenv}

# default package name prefixes
_l_boot_pkgnameprefix=	lxcross-
_l_cross_pkgnameprefix=	lxcross-
_l_tchain_pkgnameprefix=linuxsrc-
_l_dev_pkgnameprefix=	linuxsrc-
_l_base_pkgnameprefix=	linuxsrc-
_l_dist_pkgnameprefix=	linuxsrc-
_l_leaf_pkgnameprefix=	linux-
_l_none_pkgnameprefix=	#
PKGNAMEPREFIX?=		${_l_${_linuxsrc_mode}_pkgnameprefix}
.    if ${_linuxsrc_mode:Mboot}
PKGNAMESUFFIX?=		-bootstrap
.    endif

# default installation prefixes and basic paths for make and GNU configure
_l_boot_PREFIX=		${LXBOOTSTRAP}
_l_cross_PREFIX=	${LXCROSSBASE}
_l_tchain_PREFIX=	_linuxbase_
_l_dev_PREFIX=		_linuxbase_
_l_base_PREFIX=		_linuxbase_
_l_dist_PREFIX=		_linuxbase_
_l_leaf_PREFIX=		${LOCALBASE}
.    if ${_l_${_linuxsrc_mode}_PREFIX:M_linuxbase_}
USE_LINUX_PREFIX=	yes
GNU_CONFIGURE_PREFIX=	${LINUXSRC_PREFIX}
GNU_CONFIGURE_MANPREFIX=${LINUXSRC_PREFIX}/share
MANPREFIX?=		${PREFIX}${LINUXSRC_PREFIX}/share
DO_MAKE_BUILD?=		${SETENV} ${MAKE_ENV:NPREFIX=*:NMANPREFIX=*} \
			MANPREFIX=${LINUXSRC_PREFIX}/share \
			PREFIX=${LINUXSRC_PREFIX} ${MAKE_CMD} ${MAKE_FLAGS} \
			${MAKEFILE} ${_MAKE_JOBS} \
			${MAKE_ARGS:N${DESTDIRNAME}=*}
.      if !target(do-install) && !defined(NO_INSTALL) \
	&& !${USES:Mcmake*} && !${USES:Mmeson*} && !${USES:Mninja*}
do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV:NPREFIX=*:NMANPREFIX=*} \
		MANPREFIX=${LINUXSRC_PREFIX}/share PREFIX=${LINUXSRC_PREFIX} \
		${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS:N${DESTDIRNAME}=*} \
		${DESTDIRNAME}=${STAGEDIR}${PREFIX} ${INSTALL_TARGET})
.      endif
.    else
PREFIX=			${_l_${_linuxsrc_mode}_PREFIX}
.      if ${_linuxsrc_mode:Mcross}
GNU_CONFIGURE_PREFIX?=	${PREFIX}${LINUXSRC_PREFIX}
.      endif
.    endif

# build configuration for GNU autotools and pkg-config
.    ifdef GNU_CONFIGURE
_l_boot_configargs=	--target=${LINUXSRC_TRIPLET} \
			--with-sysroot=${LXCROSSBASE}
_l_cross_configargs=	${_l_boot_configargs}
_l_tchain_configargs=	--host=${LINUXSRC_TRIPLET} \
			--with-sysroot=${PREFIX} \
			${_l_dev_configargs}
_l_dev_configargs=	--sysconfdir=${LINUXSRC_SYSCONFDIR}
.      if ${PORTNAME:Ngcc:Nglibc}
# Adding --libdir is the correct thing to do for all GNU autotools build
# systems *except* GCC and glibc. These have "multiarch" support and correctly
# pick lib vs lib64 for their shared libs. They use --libdir for other things
# (like internal headers, locale data, ...) never belonging into lib64.
_l_dev_configargs+=	--libdir=${LINUXSRC_LIBDIR}
.      endif
_l_base_configargs=	${_l_dev_configargs}
_l_dist_configargs=	${_l_dev_configargs}
_l_leaf_configargs=	#
_l_boot_configtarget=	${LINUXSRC_BUILDTRIPLET}
_l_cross_configtarget=	${LINUXSRC_BUILDTRIPLET}
_l_tchain_configtarget=	${LINUXSRC_BUILDTRIPLET}
_l_dev_configtarget=	${LINUXSRC_TRIPLET}
_l_base_configtarget=	${LINUXSRC_TRIPLET}
_l_dist_configtarget=	${LINUXSRC_TRIPLET}
_l_leaf_configtarget=	${LINUXSRC_TRIPLET}
CONFIGURE_ARGS+=	${_l_${_linuxsrc_mode}_configargs}
CONFIGURE_TARGET?=	${_l_${_linuxsrc_mode}_configtarget}
.    endif
.    if ${_linuxsrc_mode:Nboot}
CONFIG_SITE=		#
.      if ${_linuxsrc_mode:Ncross:Ntchain}
.        if empty(PKGCONFIG_PATHS)
PKGCONFIG_PATHS:=	${LINUXBASE}${LINUXSRC_PKGCONFIGDIR}
PKGCONFIG_PATHS:=	${PKGCONFIG_PATHS}:${LINUXBASE}/usr/share/pkgconfig
.        endif
.      endif
.    endif

# individual default dependencies for specific modes
_l_boot_build_deps=	#
_l_boot_lib_deps=	#
_l_cross_build_deps=	binutils:devel:boot gcc:lang:boot \
			linuxheaders${LINUXKERNEL_DEFAULT:S/.//}:devel:cross
_l_cross_lib_deps=	#
_l_tchain_build_deps=	binutils:devel:cross gcc:lang:cross
_l_tchain_lib_deps=	linuxheaders${LINUXKERNEL_DEFAULT:S/.//}:devel:none
.    if ${PORTNAME:Nglibc}
# glibc can't depend on itself
_l_tchain_lib_deps+=	glibc:devel:tchain
.    endif
_l_dev_build_deps=	gcc:lang:tchain
_l_dev_lib_deps=	gcc-libgcc:devel:tchain glibc:devel:tchain
_l_base_build_deps=	${_l_dev_build_deps}
_l_base_lib_deps=	${_l_dev_lib_deps}
_l_dist_build_deps=	devtools:devel:base
_l_dist_lib_deps=	linuxsrc_base:emulators:none
_l_leaf_build_deps=	${_l_dist_build_deps}
_l_leaf_lib_deps=	${_l_dist_lib_deps}

.    for _type in build lib
_l_${_type}_deps_add:=	#
.      for _tuple in ${_l_${_linuxsrc_mode}_${_type}_deps}
_pkg:=			${_tuple:S/:/ /g:[1]}
_category:=		${_tuple:S/:/ /g:[2]}
_mode:=			${_tuple:S/:/ /g:[3]}
_suffix:=		${_mode:Mboot:S/boot/-bootstrap/}
_pkgname:=		${_l_${_mode}_pkgnameprefix}${_pkg}${_suffix}
_l_${_type}_deps_add:=	${_l_${_type}_deps_add} \
			${_pkgname}>0:${_category}/${_pkgname}
.      endfor
.    endfor

BUILD_DEPENDS+=		${_l_build_deps_add}
LINLIB_DEPENDS+=	${_l_lib_deps_add}

.  endif # ${_linuxsrc_mode:Nenv}

# special configuration for compiling the toolchain using the cross toolchain
.  if ${_linuxsrc_mode:Mtchain}
CONFIGURE_ENV+=		PATH="${LXCROSSBASE}/usr/bin:${PATH}"
MAKE_ENV+=		PATH="${LXCROSSBASE}/usr/bin:${PATH}"
BUILDCC:=		${CC:Ucc}
BUILDCPP:=		${CPP:Ucpp}
BUILDCXX:=		${CXX:Uc++}
CC=			${LINUXSRC_TRIPLET}-gcc
CPP=			${LINUXSRC_TRIPLET}-cpp
CXX=			${LINUXSRC_TRIPLET}-g++
.  endif

# special configuration for compiling the dev tools
.  if ${_linuxsrc_mode:Mdev}
CC=	${LINUXBASE}/usr/bin/gcc
CPP=	${LINUXBASE}/usr/bin/cpp
CXX=	${LINUXBASE}/usr/bin/c++
.  endif

# configure Linux strip for modes doing native builds
# add a BINARY_ALIAS for modes needing it (before dev tools are complete)
_linuxsrc_uselinuxstrip=	tchain dev base dist leaf
_linuxsrc_needstripalias=	tchain dev
.  if ${_linuxsrc_uselinuxstrip:M${_linuxsrc_mode}}
.    if ${_linuxsrc_mode:Mtchain}
STRIP_CMD=	${LXCROSSBASE}/usr/bin/${LINUXSRC_TRIPLET}-strip
.    else
STRIP_CMD=	${LINUXBASE}/usr/bin/strip
.    endif
.    if ${_linuxsrc_needstripalias:M${_linuxsrc_mode}}
BINARY_ALIAS+=	strip=${STRIP_CMD}
.    endif
.  endif

# configure using Linux build tools for modes needing it or if requested
_linuxsrc_make_fixup_for=	#
_linuxsrc_make_implied=	base dist leaf
.  if ${_linuxsrc_make_implied:M${_linuxsrc_mode}}
LINUXSRC_CC?=	gcc
LINUXSRC_CXX?=	g++
CC=		${LINUXSRC_CC}
CXX=		${LINUXSRC_CXX}
.    if defined(CONFIGURE_OUTSOURCE)
CONFIGURE_CMD?=	${LINUXBASE}/bin/bash ${WRKSRC}/${CONFIGURE_SCRIPT}
.    else
CONFIGURE_CMD?=	${LINUXBASE}/bin/bash ./${CONFIGURE_SCRIPT}
.    endif
MAKE_CMD?=	${LINUXBASE}/usr/bin/make
MAKE_SHELL?=	/bin/bash
# Hack to avoid creating files and directories below LINUXBASE when building
# and staging as root using Linux tools.
.    if ${.MAKE.UID} == 0 && ! ${:!${STAT} -f %Sf ${LINUXBASE}!:Mschg}
.      if !defined(PACKAGE_BUILDING) || empty(.TARGETS) || make(all) || \
			make(check-sanity) || make(show*-warnings)
_l_flags_warn=	Enabling workaround to build/stage as root. Linux tools might\
		create files and directories below ${LINUXBASE}, breaking the\
		build. Attempting to avoid this by temporarily setting\
		${LINUXBASE} immutable. Please build and stage ports using\
		linuxsrc as non-root instead.
WARNING+=	"${_l_flags_warn}"
.      endif
_l_tempfreeze=	290:linuxsrc-freeze-linuxbase 980:linuxsrc-thaw-linuxbase
_USES_configure+=	${_l_tempfreeze}
_USES_build+=		${_l_tempfreeze}
_USES_install+=		${_l_tempfreeze}
linuxsrc-freeze-linuxbase:
		@-chflags schg ${LINUXBASE}
linuxsrc-thaw-linuxbase:
		@-chflags noschg ${LINUXBASE}
.    endif
# hack around poudriere currently not mouting ${LINUXBASE}/dev
# TODO: get it fixed in poudriere and remove this hack
.    if defined(POUDRIERE_NAME) && ${POUDRIERE_NAME:Mpoudriere*}
build-depends: poudriere-ensure-linux-devfs
poudriere-ensure-linux-devfs: .PHONY
		@[ -c ${LINUXBASE}/dev/null ] || ${LN} -sf /dev ${LINUXBASE}/
.    endif
.    if ${_linuxsrc_mode:Mbase}
BUILD_DEPENDS+=	linuxsrc-bash>0:shells/linuxsrc-bash \
		linuxsrc-make>0:devel/linuxsrc-make
.    else
# for "dist" and "leaf", add various fixups for some USES to use
# Linux tooling instead
.      if ${USES:Mautoreconf}
_linuxsrc_make_fixup_for+=	autoreconf
# autoreconf.mk adds dependencies in _USES_POST, so completely avoid its
# inclusion and instead do everything in our own _USES_POST
_INCLUDE_USES_AUTORECONF_POST_MK=	yes
.      endif
.      if ${USES:Mcmake*}
_linuxsrc_make_fixup_for+=	cmake
.      endif
.      if ${USES:Mmeson*}
_linuxsrc_make_fixup_for+=	meson
.      endif
.      if ${USES:Mninja*} || ${USES:Mmeson*}
_linuxsrc_make_fixup_for+=	ninja
.      endif
.    endif
.  endif
 
# handle updating man-db if available
.  if ${linuxsrc_ARGS:Mman}
_l_mandb_update_cmd=	test -x ${LINUXBASE}/usr/bin/mandb && \
			${LINUXBASE}/usr/bin/mandb -q || true
PLIST_FILES+=	"@postexec ${_l_mandb_update_cmd}" \
		"@postunexec ${_l_mandb_update_cmd}"
.  endif

# handle extra dependencies
_lc_invalid_args=	#
_lc_unknown_comps=	#
_lc_build_deps_add=	#
_lc_run_deps_add=	#
.  for _dep in ${USE_LINUXSRC}
_l_d_name:=	${_dep:S/:/ /:[1]}
_l_d_type:=	${_dep:S/:/ /:[2]}
.    if ${_l_d_type:Nbuild:Nrun}
_lc_invalid_args+=	${_dep}
.    endif
.    if empty(_l_d_type)
_l_d_type:=	build run
.    endif
.    if !defined(_linuxsrc_${_l_d_name})
_lc_unknown_comps:=	${_lc_unknown_comps} ${_l_d_name}
.    endif
.    for _pair in ${_linuxsrc_${_l_d_name}}
_l_d_category:=	${_pair:S/:/ /:[1]}
_l_d_package:=	linuxsrc-${_pair:S/:/ /:[2]}
_l_d_port:=	${_l_d_category}/${_l_d_package}
.      for _type in build run
.        if ${_l_d_type:M${_type}}
_lc_${_type}_deps_add:=	${_lc_${_type}_deps_add} ${_l_d_package}>0:${_l_d_port}
.        endif
.      endfor
.    endfor
.  endfor
.  if !empty(_lc_invalid_args)
IGNORE?=	USE_LINUXSRC: Invalid argument(s): ${_lc_invalid_args:O:ts,}
.  elif !empty(_lc_unknown_comps)
IGNORE?=	USE_LINUXSRC: Unknown package(s): ${_lc_unknown_comps:O:ts,}
.  endif

BUILD_DEPENDS+=	${_lc_build_deps_add} ${LINLIB_DEPENDS}
RUN_DEPENDS+=	${_lc_run_deps_add} ${LINLIB_DEPENDS}

.endif # ! _INCLUDE_USES_LINUXSRC_MK

.ifdef _POSTMKINCLUDED && ! _INCLUDE_USES_LINUXSRC_POST_MK
_INCLUDE_USES_LINUXSRC_POST_MK=	yes

# replicate USES=autoreconf
.  if ${_linuxsrc_make_fixup_for:Mautoreconf}
.    if !${BUILD_DEPENDS:M*/linuxsrc-autoconf}
BUILD_DEPENDS+=	linuxsrc-autoconf>0:devel/linuxsrc-autoconf
.    endif
.    if !${BUILD_DEPENDS:M*/linuxsrc-automake}
BUILD_DEPENDS+=	linuxsrc-automake>0:devel/linuxsrc-automake
.    endif
.    if ${USES:Mlibtool*} && !${BUILD_DEPENDS:M*/linuxsrc-libtool}
BUILD_DEPENDS+=	linuxsrc-libtool>0:devel/linuxsrc-libtool
.    endif
AUTORECONF:=	/usr/bin/autoreconf
_USES_configure+=	470:do-autoreconf
do-autoreconf:
.    for f in AUTHORS ChangeLog INSTALL NEWS README
# Don't modify time stamps if the files already exist
	@test -e ${AUTORECONF_WRKSRC}/${f} || ${TOUCH} ${AUTORECONF_WRKSRC}/${f}
.    endfor
	@(cd ${AUTORECONF_WRKSRC} && \
		if ! ${LINUXBASE}/bin/sh -c '${AUTORECONF} -f -i'; then \
		${ECHO_MSG} '===>  Mk/Uses/linuxsrc.mk: Error running ${AUTORECONF}'; \
		${FALSE}; fi)
.  endif

# fix up USES=cmake
.  if ${_linuxsrc_make_fixup_for:Mcmake}
.    if ${CMAKE_ARGS:M-GNinja}
_linuxsrc_make_fixup_for+=	ninja
.    endif
BUILD_DEPENDS:=	${BUILD_DEPENDS:N*devel/cmake-core}
.    if ! ${BUILD_DEPENDS:M*/linuxsrc-cmake}
BUILD_DEPENDS+=	linuxsrc-cmake>0:devel/linuxsrc-cmake
.    endif
CMAKE_BIN:=		${LINUXBASE}/usr/bin/cmake
.    if ${_linuxsrc_mode:Nleaf}
CMAKE_INSTALL_PREFIX:=	${LINUXSRC_PREFIX}
.    endif
.  endif

# fix up USES=meson
.  if ${_linuxsrc_make_fixup_for:Mmeson}
BUILD_DEPENDS:=	${BUILD_DEPENDS:N*devel/meson}
.    if ! ${BUILD_DEPENDS:M*/linuxsrc-meson}
BUILD_DEPENDS+=	linuxsrc-meson>0:devel/linuxsrc-meson
.    endif
.    if ${_linuxsrc_mode:Nleaf}
CONFIGURE_ARGS:=${CONFIGURE_ARGS:tW:C/(--prefix *)[^ ]*/\1${LINUXSRC_PREFIX}/}
CONFIGURE_ARGS:=${CONFIGURE_ARGS:tW:C/(--mandir *)[^ ]*/\1share\/man/}
.    endif
CONFIGURE_CMD:=	${LINUXBASE}/bin/sh -c 'meson setup ${CONFIGURE_ARGS}'
.  endif

# fix up USES=ninja
.  if ${_linuxsrc_make_fixup_for:Mninja}
BUILD_DEPENDS:=	${BUILD_DEPENDS:N*devel/ninja}
.    if ! ${BUILD_DEPENDS:M*/linuxsrc-ninja}
BUILD_DEPENDS+=	linuxsrc-ninja>0:devel/linuxsrc-ninja
.    endif
NINJA_CMD:=	${LINUXBASE}/usr/bin/ninja
.    if ${_linuxsrc_mode:Nleaf}
MAKE_ENV:=	${MAKE_ENV:N${DESTDIRNAME}=*}
MAKE_ENV+=	${DESTDIRNAME}=${STAGEDIR}${PREFIX}
.    endif
.  endif

.endif # _POSTMKINCLUDED && ! _INCLUDE_USES_LINUXSRC_POST_MK
