PORTNAME=	jpeg-turbo
DISTVERSION=	3.0.0
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/${DISTVERSION}
DISTNAME=	lib${PORTNAME}-${DISTVERSION}

PATCH_SITES=	https://github.com/libjpeg-turbo/libjpeg-turbo/commit/
PATCHFILES=	035ea386d1b6a99a8a1e2ab57cc1fc903569136c.patch:-p1

MAINTAINER=	zirias@FreeBSD.org
COMMENT?=	SIMD-accelerated JPEG codec, Linux version
WWW?=		https://libjpeg-turbo.org/

LICENSE=		BSD3CLAUSE IJG ZLIB
LICENSE_COMB=		multi
LICENSE_GROUPS_IJG=	FSF GPL
LICENSE_NAME_IJG=	Independent JPEG Group License
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE.md
LICENSE_FILE_IJG=	${WRKSRC}/README.ijg
LICENSE_FILE_ZLIB=	${WRKSRC}/LICENSE.md
LICENSE_PERMS_IJG=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake cpe linuxsrc:dist,man
CPE_PRODUCT=	libjpeg-turbo
USE_LDCONFIG=	yes

BUILD_DEPENDS=	${"${ARCH:Maarch64}":?:nasm:devel/nasm}

CMAKE_ON=	WITH_JPEG8 
CMAKE_OFF=	ENABLE_STATIC

.include <bsd.port.mk>
