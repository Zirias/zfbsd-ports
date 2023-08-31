PORTNAME=	libXfixes
DISTVERSION=	6.0.0
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Fixes extension library, Linux version
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:bz2
CPE_VENDOR=	x
CPE_PRODUCT=	libxfixes
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
