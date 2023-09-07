PORTNAME=	gtk
DISTVERSION=	2.24.33
CATEGORIES=	x11-toolkits
MASTER_SITES=	GNOME/sources/gtk+/${DISTVERSION:R}
PKGNAMESUFFIX=	2
DISTNAME=	gtk+-${DISTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Gimp Toolkit for X11 GUI, Linux version
WWW=		https://www.gtk.org/

LICENSE=	LGPL20

BUILD_DEPENDS=	shared-mime-info>0:misc/shared-mime-info

USES=		cpe libtool linuxsrc:dist pkgconfig tar:xz
CPE_VENDOR=	gnome
USE_LDCONFIG=	yes
USE_LINUXSRC=	atk cairo gdkpixbuf gettext pango x11 xcomposite xcursor \
		xdamage xext xfixes xi xinerama xrender \
		gintrospect:build perl:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cups \
		--disable-static \
		--with-xinput=yes
INSTALL_TARGET=	install-strip

post-install:
		${RM} -r ${STAGEDIR}${PREFIX}/etc \
			${STAGEDIR}${PREFIX}/usr/share/gtk-2.0 \
			${STAGEDIR}${PREFIX}/usr/share/gtk-doc

.include <bsd.port.mk>
