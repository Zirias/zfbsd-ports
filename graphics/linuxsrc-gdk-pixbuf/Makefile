PORTNAME=	gdk-pixbuf
DISTVERSION=	2.42.10
CATEGORIES=	graphics
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Graphic library for GTK+, Linux version
WWW=		https://developer.gnome.org/gdk-pixbuf/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	shared-mime-info>0:misc/shared-mime-info

USES=		cpe linuxsrc:dist meson pkgconfig tar:xz trigger
CPE_VENDOR=	gnome
TRIGGERS=	linuxsrc-gdk-pixbuf-query-loaders
USE_LDCONFIG=	yes
USE_LINUXSRC=	gettext glib jpeg libpng \
		gintrospect:build libxslt:build python:build

MESON_ARGS=	-Dbuiltin_loaders="none" \
		-Dgtk_doc=false \
		-Dinstalled_tests=false \
		-Djpeg=enabled \
		-Dman=false \
		-Dpng=enabled \
		-Dtests=false \
		-Dtiff=disabled

SUB_LIST=	LIBDIR=${LINUXSRC_LIBDIR} GTK2_VERSION=2.10.0

.include <bsd.port.mk>
