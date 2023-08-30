PORTNAME=	fontconfig
DISTVERSION=	2.14.2
CATEGORIES=	x11-fonts
MASTER_SITES=	https://www.freedesktop.org/software/fontconfig/release/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	XML-based font configuration API for X Windows
WWW=		https://www.freedesktop.org/wiki/Software/fontconfig/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe linuxsrc:dist meson pkgconfig tar:xz
CPE_VENDOR=	fontconfig_project
USE_LDCONFIG=	yes
USE_LINUXSRC=	expat freetype gettext:build gperf:build python:build

MESON_ARGS=	-Dadditional-fonts-dirs=${LOCALBASE}/lib/X11/fonts:${LOCALBASE}/share/fonts \
		-Dcache-build=disabled \
		-Dcache-dir=/var/db/fontconfig \
		-Ddoc=disabled \
		-Ddefault-fonts-dirs=${LINUXSRC_PREFIX}/share/fonts \
		-Dlocalstatedir=/var \
		-Dtemplate-dir=/etc/fonts/conf.avail \
		-Dxml-dir=/etc/fonts

.include <bsd.port.mk>
