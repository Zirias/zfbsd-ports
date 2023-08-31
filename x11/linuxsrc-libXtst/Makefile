PORTNAME=	libXtst
DISTVERSION=	1.2.3
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Test extension, Linux version
WWW=		https://www.freedesktop.org/Software/xorg

LICENSE=	MIT

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:bz2
CPE_VENDOR=	x
CPE_PRODUCT=	libxtst
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xi xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-specs \
		--disable-static \
		--without-xmlto
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
