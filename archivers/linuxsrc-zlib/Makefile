PORTNAME=	zlib
DISTVERSION=	1.3
CATEGORIES=	archivers
MASTER_SITES=	https://zlib.net/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Compression/decompresson library for Linux
WWW=		${MASTER_SITES}

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		linuxsrc:tchain,man tar:xz
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${LINUXSRC_PREFIX} --libdir=${LINUXSRC_LIBDIR}
CONFIGURE_ENV=	CHOST=${LINUXSRC_TRIPLET}

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-install:
		@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libz.a

.include <bsd.port.mk>
