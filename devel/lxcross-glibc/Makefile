PORTNAME=	glibc
DISTVERSION=	${LINUXSRC_V_GLIBC}
CATEGORIES=	devel
MASTER_SITES=	GNU/glibc

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU standard C library for Linux, cross version
WWW=		https://www.gnu.org/software/libc/

LICENSE=		GPLv2 LGPL21
LICENSE_COMB=		multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	gawk:lang/gawk \
		makeinfo:print/texinfo \
		gsed:textproc/gsed
RUN_DEPENDS=	bash:shells/bash

USES=		bison gettext-tools gmake linuxsrc:cross python:build \
		shebangfix tar:xz
SHEBANG_FILES=	debug/xtrace.sh elf/ldd.bash.in elf/sotruss.sh \
		timezone/tzselect.ksh

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	/usr
CONFIGURE_ARGS= 	--enable-kernel=${LINUXKERNEL_DEFAULT} \
			--host=${LINUXSRC_TRIPLET} \
			--with-headers=${LXCROSSBASE}/usr/include \
			ac_cv_prog_AWK=${BINARY_LINKDIR}/awk \
			ac_cv_prog_SED=${BINARY_LINKDIR}/sed \
			libc_cv_slibdir=/usr/lib
CONFIGURE_ENV=		PATH="${LXBOOTSTRAP}/bin:${PATH}"
CONFIGURE_OUTSOURCE=	yes
MAKE_ARGS=		DESTDIR=${STAGEDIR}${PREFIX}
MAKE_ENV=		${CONFIGURE_ENV}
DESTDIRNAME=		DESTDIR_DUMMY

CC=	${LINUXSRC_TRIPLET}-gcc
CPP=	${LINUXSRC_TRIPLET}-cpp
CXX=	${LINUXSRC_TRIPLET}-g++

BINARY_ALIAS=	awk=${LOCALBASE}/bin/gawk \
		python=${PYTHON_CMD} \
		sed=${LOCALBASE}/bin/gsed \
		strip=${LXBOOTSTRAP}/bin/${LINUXSRC_TRIPLET}-strip

PLIST_SUB=	LINUXINTERP=${LINUXINTERP}

LXINTERPSFX_aarch64=	-aarch64.so.1
LXINTERPSFX_amd64=	-x86-64.so.2
LXINTERPSFX_i386=	.so.2
LINUXINTERP=		ld-linux${LXINTERPSFX_${ARCH}}

.include <bsd.port.mk>
