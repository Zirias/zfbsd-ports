PORTNAME=	libxkbfile
DISTVERSION=	1.1.0
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	XKB file library, Linux version
WWW=		https://www.freedesktop.org/Software/xorg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist pkgconfig tar:bz2
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
