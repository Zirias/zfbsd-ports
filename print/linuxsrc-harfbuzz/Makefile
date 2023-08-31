PORTNAME=	harfbuzz
DISTVERSION=	8.1.1
CATEGORIES=	print
MASTER_SITES=	https://github.com/harfbuzz/harfbuzz/releases/download/${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT?=	OpenType text shaping engine, Linux version
WWW=		https://harfbuzz.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe linuxsrc:dist meson pkgconfig tar:xz
CPE_VENDOR=	harfbuzz_project
USE_LDCONFIG=	yes
USE_LINUXSRC=	cairo freetype glib graphite2 icu \
		gintrospect:build python:build

MESON_ARGS=	-Dcairo=enabled \
		-Dchafa=disabled \
		-Ddocs=disabled \
		-Dgraphite2=enabled \
		-Dicu=enabled \
		-Dtests=disabled

PLIST_SUB=	LIBVER=0.60811.0

.include <bsd.port.mk>
