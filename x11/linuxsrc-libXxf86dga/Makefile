PORTNAME=	libXxf86dga
DISTVERSION=	1.1.6
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X DGA Extension, Linux version
WWW=		https://www.freedesktop.org/Software/xorg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:xz
CPE_VENDOR=	x
CPE_PRODUCT=	libxxf86dga
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
