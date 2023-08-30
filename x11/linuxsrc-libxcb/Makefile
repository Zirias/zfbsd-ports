PORTNAME=	libxcb
DISTVERSION=	1.15
CATEGORIES=	x11
MASTER_SITES=	https://xcb.freedesktop.org/dist/
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) library, Linux version
WWW=		https://xcb.freedesktop.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:xz
CPE_VENDOR=	x
USE_LDCONFIG=	yes
USE_LINUXSRC=	xau xdmcp python:build xcbproto:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-devel-docs \
		--disable-static \
		--enable-xinput \
		--enable-xkb \
		--without-doxygen
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
