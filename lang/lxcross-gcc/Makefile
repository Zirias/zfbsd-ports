PORTNAME=	gcc
DISTVERSION=	${LINUXSRC_V_GCC}
CATEGORIES=	lang
MASTER_SITES=	GNU/gcc/gcc-${LINUXSRC_V_GCC} \
		GNU/gmp:gmp \
		GNU/mpc:mpc \
		GNU/mpfr:mpfr
DISTFILES=	gcc-${LINUXSRC_V_GCC}.tar.xz \
		gmp-${LINUXSRC_V_GMP}.tar.xz:gmp \
		mpc-${LINUXSRC_V_MPC}.tar.gz:mpc \
		mpfr-${LINUXSRC_V_MPFR}.tar.xz:mpfr

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GCC targeting Linux
WWW=		https://gcc.gnu.org

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	lxcross-binutils>0:devel/lxcross-binutils \
		lxcross-glibc>0:devel/lxcross-glibc
RUN_DEPENDS=	${BUILD_DEPENDS}

USES=		gmake libtool linuxsrc:cross

GNU_CONFIGURE=		yes
CONFIGURE_ARGS= 	--disable-libsanitizer \
			--disable-multilib \
			--disable-plugin \
			--enable-default-pie \
			--enable-default-ssp \
			--enable-languages=c,c++
CONFIGURE_OUTSOURCE=	yes

INSTALL_TARGET=	install-strip

# Silence compiler warnings, they are excessive when building GCC with clang
CFLAGS+=	-w

DATADIR=	${PREFIX}/usr/share/${PORTNAME}-${DISTVERSION}

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		LINUX44="${"${LINUXKERNEL_DEFAULT:M4.4}":?:@comment _nonex/:}"

GCCXLIBDIR=		/usr/${LINUXSRC_TRIPLET}/${LINUXSRC_LIBDIRNAME}
GCCRMDIR_aarch64=	/usr/${LINUXSRC_TRIPLET}/lib
GCCRMDIR_amd64=		/usr/${LINUXSRC_TRIPLET}/lib
GCCRMDIR_i386=		#
GCCRMDIRS=		/usr/include ${GCCRMDIR_${ARCH}}
TARGET_STRIP=		${LXCROSSBASE}/usr/bin/${LINUXSRC_TRIPLET}-strip

post-extract:
		@${MV} -f ${WRKDIR}/gmp-${LINUXSRC_V_GMP} ${WRKSRC}/gmp
		@${MV} -f ${WRKDIR}/mpc-${LINUXSRC_V_MPC} ${WRKSRC}/mpc
		@${MV} -f ${WRKDIR}/mpfr-${LINUXSRC_V_MPFR} ${WRKSRC}/mpfr

.include <bsd.port.pre.mk>

post-install:
.for d in ${GCCRMDIRS}
		@${RMDIR} ${STAGEDIR}${PREFIX}${d}
.endfor
		${TARGET_STRIP} ${STAGEDIR}${PREFIX}${GCCXLIBDIR}/libgcc_s.so.1

.include <bsd.port.post.mk>
