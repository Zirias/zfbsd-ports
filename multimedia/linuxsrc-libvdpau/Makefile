PORTNAME=	libvdpau
DISTVERSION=	1.5
CATEGORIES=	multimedia

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	VDPAU wrapper and tracing library, Linux version
WWW=		https://freedesktop.org/wiki/Software/VDPAU

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		linuxsrc:dist meson pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	vdpau
GL_TAGNAME=	79f1506a3307d3275b0fdfb2e110c173f68e6f78
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xorgproto

MESON_ARGS=	-Ddocumentation=false

post-install:
		@${RM} -r ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
