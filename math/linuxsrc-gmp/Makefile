PORTNAME=	gmp
DISTVERSION=	${LINUXSRC_V_GMP}
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Free library for arbitrary precision arithmetic, Linux version
WWW=		https://gmplib.org/

LICENSE=	LGPL3

USES=		cpe libtool linuxsrc:tchain makeinfo tar:xz
CPE_VENDOR=	gmplib
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cxx \
		--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
