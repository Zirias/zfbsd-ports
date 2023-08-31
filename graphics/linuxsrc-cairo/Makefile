PORTNAME=	cairo
DISTVERSION=	1.17.4
CATEGORIES=	graphics
MASTER_SITES=	https://cairographics.org/releases/ \
		https://cairographics.org/snapshots/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Vector graphics library, Linux version
WWW=		https://www.cairographics.org/

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING-LGPL-2.1
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING-MPL-1.1

USES=		cpe libtool linuxsrc:dist pkgconfig tar:xz
CPE_VENDOR=	cairographics
USE_LDCONFIG=	yes
USE_LINUXSRC=	fontconfig freetype gettext glib glvnd libpng libxcb pixman \
		x11 xext xorgproto xrender

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-directfb \
		--disable-gallium \
		--disable-static \
		--disable-wgl \
		--enable-gl \
		--enable-gobject \
		--enable-egl \
		--enable-tee \
		--enable-xcb \
		--enable-xlib \
		--enable-xlib-xcb
INSTALL_TARGET=	install-strip

PLIST_SUB+=	LIBVER=2.11704.0

.include <bsd.port.mk>
