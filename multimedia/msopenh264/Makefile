PORTNAME=	msopenh264
DISTVERSION=	5.2.0.a.20240516
CATEGORIES=	multimedia net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mediastreamer plugin with H.264 codec
WWW=		https://www.linphone.org/technical-corner/mediastreamer2.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libmediastreamer2.so:net/mediastreamer \
		libopenh264.so:multimedia/openh264 \
		libortp.so:net/ortp

USES=		cmake
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_TAGNAME=	041b07a8

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=YES
PLIST_FILES=	lib/mediastreamer/plugins/libmsopenh264.so

.include <bsd.port.mk>
