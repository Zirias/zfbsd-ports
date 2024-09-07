PORTNAME=	ortp
DISTVERSION=	5.3.81
CATEGORIES=	net

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Real-time Transport Protocol (RTP) library
WWW=		https://www.linphone.org/technical-corner/ortp.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake compiler:c11
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON \
		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_DOC=OFF \
		-DENABLE_STRICT=OFF

DATADIR=	${PREFIX}/share/Ortp

.include <bsd.port.mk>
