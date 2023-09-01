PORTNAME=	libva
DISTVERSION=	2.19.0
CATEGORIES=	multimedia

MAINTAINER=	zirias@FreeBSD.org
COMMENT?=	VAAPI library, Linux version
WWW=		https://github.com/intel/libva

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson linuxsrc:dist pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	intel
USE_LDCONFIG=	yes
USE_LINUXSRC=	glvnd libdrm libxcb x11 xext xfixes xorgproto

MESON_ARGS=	-Dwith_glx=yes \
		-Dwith_wayland=no \
		-Dwith_x11=yes

.include <bsd.port.mk>
