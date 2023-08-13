PORTNAME=	mpfr
DISTVERSION=	${LINUXSRC_V_MPFR}
CATEGORIES=	math
MASTER_SITES=	GNU \
		https://www.mpfr.org/mpfr-${DISTVERSION}/
DIST_SUBDIR=	${DISTNAME}

PATCH_SITES=	https://www.mpfr.org/mpfr-${DISTVERSION}/
PATCHFILES!=	/usr/bin/jot -s " " -w patch%02d ${PATCHLEVEL} 1 ${PATCHLEVEL}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU multiple-precision floating-point lib, Linux version
WWW=		https://www.mpfr.org/

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

LINLIB_DEPENDS=	linuxsrc-gmp>0:math/linuxsrc-gmp

USES=		gmake libtool linuxsrc:tchain makeinfo tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-threadsafe
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${WRKDIR}
LDFLAGS+=	-L${WRKDIR}

PATCHLEVEL=	12

pre-configure:
		@${LN} -s ${LINUXBASE}/usr/include/gmp.h ${WRKDIR}
		@${LN} -s ${LINUXBASE}${LINUXSRC_LIBDIR}/libgmp.so ${WRKDIR}

.include <bsd.port.mk>
