PORTNAME=	libircbot
DISTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	irc devel

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Framework for creating an IRC bot in C
WWW=		https://github.com/Zirias/libircbot

LICENSE=	BSD2CLAUSE

USES=		compiler:c11 gmake

USE_GITHUB=	yes
GH_PROJECT=	zimk:zimk
GH_ACCOUNT=	Zirias
GH_TAGNAME=	eb363b7:zimk

USE_LDCONFIG=	yes
MAKE_ARGS=	pkgconfigdir=${LOCALBASE}/libdata/pkgconfig \
		V=1
ALL_TARGET=	strip

post-extract:
	@${MV} ${WRKSRC_zimk}/* ${WRKSRC}/zimk/

.include <bsd.port.mk>
