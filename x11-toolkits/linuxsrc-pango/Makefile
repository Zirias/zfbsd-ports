PORTNAME=	pango
DISTVERSION=	1.50.14
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Framework for layout/rendering of i18n text, Linux version
WWW=		https://www.pango.org/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe linuxsrc:dist meson pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
USE_LINUXSRC=	cairo fontconfig freetype fribidi gettext glib harfbuzz \
		x11 xft xrender gintrospect:build

MESON_ARGS=	-Dgtk_doc=false \
		-Dlibthai=disabled \
		-Dxft=enabled

.include <bsd.port.mk>
