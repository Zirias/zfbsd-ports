PORTNAME=	mswebrtc
DISTVERSION=	1.1.2.a.20240718
CATEGORIES=	multimedia net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Mediastreamer plugin with WebRTC codecs
WWW=		https://www.linphone.org/technical-corner/mediastreamer2.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libmediastreamer2.so:net/mediastreamer \
		libortp.so:net/ortp

USES=		cmake compiler:c++11-lib
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public public/external:webrtc
GL_PROJECT=	webrtc:webrtc
GL_TAGNAME=	9615e3eb 583acd27665cfadef8ab03eb85a768d308bd29dd:webrtc
GL_SUBDIR=	webrtc:webrtc

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=yes
PLIST_FILES=	lib/mediastreamer/plugins/libmswebrtc.so

.include <bsd.port.mk>
