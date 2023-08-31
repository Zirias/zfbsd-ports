PORTNAME=	libglvnd
DISTVERSION=	1.6.0
CATEGORIES=	graphics

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GL Vendor-Neutral Dispatch library, Linux version
WWW=		https://gitlab.freedesktop.org/glvnd/libglvnd

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi

USES=		linuxsrc:dist meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	glvnd
GL_TAGNAME=	b05bbcdaeb9b700cf7877e6d66f8fc3ac952295b
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xorgproto

MESON_ARGS=	-Dglx=enabled \
		-Dx11=enabled

.include <bsd.port.mk>
