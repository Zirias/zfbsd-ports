PORTNAME=	glib
DISTVERSION=	2.76.4
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Some useful routines of C programming, Linux version
WWW=		https://www.gtk.org/

LICENSE=	LGPL20

USES=		cpe linuxsrc:dist meson pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
USE_LINUXSRC=	elfutils libffi gettext:build perl:build

MESON_ARGS=	-Dinstalled_tests=false \
		-Dlibmount=disabled \
		-Dman=false \
		-Dselinux=disabled \
		-Dtests=false

PLIST_SUB=	LIBVERSION=${_LIBVERSION}

_LIBVERSION=	0.7600.4

.include <bsd.port.mk>
