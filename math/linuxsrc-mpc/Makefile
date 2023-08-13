PORTNAME=	mpc
DISTVERSION=	${LINUXSRC_V_MPC}
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU multi-precision lib for complex numbers, Linux version
WWW=		https://www.multiprecision.org/mpc/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LINLIB_DEPENDS=	linuxsrc-gmp>0:math/linuxsrc-gmp \
		linuxsrc-mpfr>0:math/linuxsrc-mpfr

USES=		libtool linuxsrc:tchain
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${WRKDIR}
LDFLAGS+=	-L${WRKDIR}

PLIST_FILES=	usr/include/mpc.h \
		usr/${LINUXSRC_LIBDIRNAME}/libmpc.so \
		usr/${LINUXSRC_LIBDIRNAME}/libmpc.so.3 \
		usr/${LINUXSRC_LIBDIRNAME}/libmpc.so.3.3.1 \
		usr/share/info/mpc.info

pre-configure:
.for h in gmp.h mpf2mpfr.h mpfr.h
		@${LN} -s ${LINUXBASE}/usr/include/${h} ${WRKDIR}
.endfor
		@${LN} -s ${LINUXBASE}${LINUXSRC_LIBDIR}/libgmp.so ${WRKDIR}
		@${LN} -s ${LINUXBASE}${LINUXSRC_LIBDIR}/libmpfr.so ${WRKDIR}

.include <bsd.port.mk>
