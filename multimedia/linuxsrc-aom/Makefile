PORTNAME=	aom
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.0-rc1
CATEGORIES=	multimedia

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	AV1 reference encoder/decoder, Linux version
WWW=		https://aomedia.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		cmake linuxsrc:dist
USE_GITHUB=	yes
GH_ACCOUNT=	jbeich # mirror
USE_LDCONFIG=	yes
USE_LINUXSRC=	perl:build
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	ENABLE_DOCS ENABLE_TESTS

post-patch:
# Extract (snapshot) version from the port instead of CHANGELOG
	@${REINPLACE_CMD} 's,$${AOM_ROOT}/CHANGELOG,${DISTVERSIONFULL:S/^v//},' \
		${WRKSRC}/build/cmake/version.cmake

post-install:
	@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.a

.include <bsd.port.mk>
