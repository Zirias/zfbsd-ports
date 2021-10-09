PORTNAME=		remusock
DISTVERSION=		2.0
CATEGORIES=		net
MASTER_SITES=		https://github.com/Zirias/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/download/v${DISTVERSION}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Remote unix domain socket access
WWW=		https://github.com/Zirias/remusock

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libposercore.so:devel/poser

USES=		compiler:c11 gmake pkgconfig tar:xz

USE_RC_SUBR=	${PORTNAME}

MAKE_ARGS=	V=1
ALL_TARGET=	strip

.include <bsd.port.mk>
