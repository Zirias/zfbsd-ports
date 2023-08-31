PORTNAME=	fribidi
DISTVERSION=	1.0.13
CATEGORIES=	converters
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Unicode Bidirectional Algorithm, Linux version
WWW=		https://fribidi.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe linuxsrc:dist,man meson tar:xz
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes

CFLAGS+=	-O3

.include <bsd.port.mk>
