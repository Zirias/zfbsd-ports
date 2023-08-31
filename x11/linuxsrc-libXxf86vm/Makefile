PORTNAME=	libXxf86vm
DISTVERSION=	1.1.4
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Vidmode Extension, Linux version
WWW=		https://www.freedesktop.org/Software/xorg

LICENSE=	MIT

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:bz2
CPE_VENDOR=	x
CPE_PRODUCT=	libxxf86vm
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
