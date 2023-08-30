PORTNAME=	freetype
DISTVERSION=	2.13.1
CATEGORIES=	print
MASTER_SITES=	SAVANNAH/${PORTNAME} \
		SF/freetype/${PORTNAME}2/${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	TrueType font rendering engine, Linux version
WWW=		https://www.freetype.org/

LICENSE=	FTL GPLv2+
LICENSE_COMB=	dual
LICENSE_NAME_FTL=	The FreeType Project license
LICENSE_FILE_FTL=	${WRKSRC}/docs/FTL.TXT
LICENSE_FILE_GPLv2+ =	${WRKSRC}/docs/GPLv2.TXT
LICENSE_PERMS_FTL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake cpe linuxsrc:dist pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	brotli libpng

CMAKE_ON=	BUILD_SHARED_LIBS \
		DISABLE_FORCE_DEBUG_POSTFIX \
		FT_DISABLE_HARFBUZZ \
		FT_REQUIRE_BROTLI \
		FT_REQUIRE_BZIP2 \
		FT_REQUIRE_PNG \
		FT_REQUIRE_ZLIB

.include <bsd.port.mk>
