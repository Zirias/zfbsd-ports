PORTNAME=	bzrtp
PORTVERSION=	5.3.81
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	ZRTP support library (RFC 6189)
WWW=		https://www.linphone.org

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox

USES=		cmake cpe gnome sqlite
CPE_VENDOR=	${PORTNAME}_project
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=YES \
		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_STRICT=NO

DATADIR=	${PREFIX}/share/BZRTP

post-patch:
	@${REINPLACE_CMD} 's/<alloca\.h>/<stdlib.h>/' ${WRKSRC}/src/zidCache.c

.include <bsd.port.mk>
