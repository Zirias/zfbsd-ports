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

BUILD_DEPENDS=	lxcross-binutils-bootstrap>0:devel/lxcross-binutils-bootstrap

USES=		gmake libtool linuxsrc:boot

GNU_CONFIGURE=		yes
CONFIGURE_ARGS= 	--disable-gcov \
			--disable-host-shared \
			--disable-libatomic \
			--disable-libgomp \
			--disable-libquadmath \
			--disable-libssp \
			--disable-libstdcxx \
			--disable-libvtv \
			--disable-multilib \
			--disable-nls \
			--disable-plugin \
			--disable-shared \
			--disable-threads \
			--enable-default-pie \
			--enable-default-ssp \
			--enable-languages=c,c++ \
			--with-glibc-version=${LINUXSRC_V_GLIBC} \
			--with-newlib \
			--without-headers
CONFIGURE_OUTSOURCE=	yes

INSTALL_TARGET=	install-strip

# Silence compiler warnings, they are excessive when building GCC with clang
CFLAGS+=	-w

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-extract:
		@${MV} -f ${WRKDIR}/gmp-${LINUXSRC_V_GMP} ${WRKSRC}/gmp
		@${MV} -f ${WRKDIR}/mpc-${LINUXSRC_V_MPC} ${WRKSRC}/mpc
		@${MV} -f ${WRKDIR}/mpfr-${LINUXSRC_V_MPFR} ${WRKSRC}/mpfr

.include <bsd.port.mk>
