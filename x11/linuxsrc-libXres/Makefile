PORTNAME=	libXres
DISTVERSION=	1.2.2
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Resource usage library, Linux version
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:xz
CPE_PRODUCT=	libxres
CPE_VENDOR=	x
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
