PORTNAME=	libpng
DISTVERSION=	1.6.40
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PNGMSSUBDIR}/
#PATCH_SITES=	SF/${PORTNAME}-apng/${PNGMSSUBDIR}/
#PATCHFILES=	${DISTNAME}-apng.patch.gz:-p1
PATCH_SITES=	SF/${PORTNAME}-apng/lib${PORTNAME}16/1.6.39/
PATCHFILES=	${PORTNAME}-1.6.39-apng.patch.gz:-p1

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Library for manipulating PNG images, Linux version
WWW=		http://www.libpng.org/pub/png/libpng.html

LICENSE=	Libpng
LICENSE_GROUPS=	FSF GPL OSI
LICENSE_NAME=	libpng License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake cpe linuxsrc:dist,man tar:xz
USE_LDCONFIG=	yes

CMAKE_ON=	PNG_HARDWARE_OPTIMIZATIONS PNG_SHARED
CMAKE_OFF=	PNG_STATIC PNG_TESTS

PNGMSSUBDIR=	${PORTNAME}${DISTVERSION:R:S/.//}/${DISTVERSION}

.include <bsd.port.mk>
