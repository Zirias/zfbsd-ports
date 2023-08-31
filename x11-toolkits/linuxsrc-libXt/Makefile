PORTNAME=	libXt
DISTVERSION=	1.2.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Toolkit library, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:bz2
CPE_VENDOR=	x
CPE_PRODUCT=	libxt
USE_LDCONFIG=	yes
USE_LINUXSRC=	libsm libice x11 xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-specs \
		--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
