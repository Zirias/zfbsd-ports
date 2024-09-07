PORTNAME=	bctoolbox
DISTVERSION=	5.3.81
CATEGORIES=	net

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Belledonne Communications utility library
WWW=		https://gitlab.linphone.org/BC/public/bctoolbox

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	bcunit>=5.3.79:devel/bcunit
LIB_DEPENDS=	libmbedtls.so:security/mbedtls

USES=		cmake compiler:c++17-lang
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=ON \
		-DENABLE_STRICT=NO \
		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DCMAKE_SKIP_INSTALL_RPATH=ON

CFLAGS+=	-DHAVE_ARC4RANDOM
DATADIR=	${PREFIX}/share/BCToolbox

post-patch:
	@${REINPLACE_CMD} '/clock_gettime/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
