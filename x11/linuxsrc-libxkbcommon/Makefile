PORTNAME=	libxkbcommon
DISTVERSION=	1.5.0
CATEGORIES=	x11
MASTER_SITES=	https://xkbcommon.org/download/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Keymap handling library, Linux version
WWW=		https://xkbcommon.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		bison cpe linuxsrc:dist meson pkgconfig tar:xz
CPE_VENDOR=	xkbcommon
USE_LDCONFIG=	yes
USE_LINUXSRC=	libxcb libxml2

MESON_ARGS=	-Denable-docs=false \
		-Denable-wayland=false \
		-Denable-x11=true

.include <bsd.port.mk>
