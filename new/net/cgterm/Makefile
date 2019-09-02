# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	cgterm
DISTVERSION=	1.7b2
CATEGORIES=	net

MAINTAINER=	felix@palmen-it.de
COMMENT=	C/G telnet client for C64 BBSs

USE_GITHUB=	yes
GH_ACCOUNT=	MagerValp
GH_PROJECT=	CGTerm
GH_TAGNAME=	01e35d6

LICENSE=	PD
USES=		sdl
USE_SDL=	sdl
USES=		gmake
MAKE_ARGS=	CC=${CC}

do-install:
		${MAKE_CMD} -C${WRKSRC} PREFIX=${STAGEDIR}${PREFIX} install

.include <bsd.port.mk>

