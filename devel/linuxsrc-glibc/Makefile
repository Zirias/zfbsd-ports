PORTNAME=	glibc
DISTVERSION=	${LINUXSRC_V_GLIBC}
CATEGORIES=	devel
MASTER_SITES=	GNU/glibc

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU standard C library for Linux
WWW=		https://www.gnu.org/software/libc/

LICENSE=		GPLv2 LGPL21
LICENSE_COMB=		multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	gawk:lang/gawk \
		makeinfo:print/texinfo \
		gsed:textproc/gsed
RUN_DEPENDS=	linuxsrc_base-dirs>0:emulators/linuxsrc_base-dirs

USES=			bison gettext-tools gmake linuxsrc:tchain \
			python:build tar:xz

GNU_CONFIGURE=		yes
CONFIGURE_ARGS= 	--enable-kernel=${LINUXKERNEL_DEFAULT} \
			--with-headers=${LINUXBASE}/usr/include \
			ac_cv_prog_AWK=${BINARY_LINKDIR}/awk \
			ac_cv_prog_SED=${BINARY_LINKDIR}/sed
CONFIGURE_OUTSOURCE=	yes

BINARY_ALIAS=	awk=${LOCALBASE}/bin/gawk \
		python=${PYTHON_CMD} \
		sed=${LOCALBASE}/bin/gsed

PLIST_SUB=	LINUXINTERP=${LINUXINTERP} \
		LINUXINTERPDIR=${LINUXINTERPDIR}

LXINTERPSFX_aarch64=	-aarch64.so.1
LXINTERPSFX_amd64=	-x86-64.so.2
LXINTERPSFX_i386=	.so.2
LINUXINTERPDIR=		lib${"${ARCH:Mamd64}":?64:}
LINUXINTERP=		ld-linux${LXINTERPSFX_${ARCH}}

pre-configure:
		@${MKDIR} ${CONFIGURE_WRKSRC}
		@${ECHO_CMD} "rootsbindir=/usr/sbin" > \
			${CONFIGURE_WRKSRC}/configparms
		@${ECHO_CMD} "slibdir=${LINUXSRC_LIBDIR}" >> \
			${CONFIGURE_WRKSRC}/configparms

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/var/cache/ldconfig
		${MKDIR} ${STAGEDIR}${PREFIX}/usr/${LINUXINTERPDIR}
		${MV} ${STAGEDIR}${PREFIX}/${LINUXINTERPDIR}/${LINUXINTERP} \
			${STAGEDIR}${PREFIX}/usr/${LINUXINTERPDIR}
		${RMDIR} ${STAGEDIR}${PREFIX}/${LINUXINTERPDIR}

.include <bsd.port.mk>
