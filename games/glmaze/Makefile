PORTNAME=	glmaze
DISTVERSION=	1.1a
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${DISTVERSION}$ \
		SF/nemysisfreebsdp/${CATEGORIES}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.png:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer OpenGL Maze Game
WWW=		https://glmaze.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gl sdl
USE_GL=		gl
USE_SDL=	mixer sdl

PORTDOCS=	readme.txt
OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES="glMaze" "" "${PORTNAME}" \
		"${PORTNAME}" "Game;ArcadeGame;" ""

# Wrong versioning upstream
PORTSCOUT=	ignore:1

post-extract:
	@(cd ${WRKSRC} && ${MV} ${PORTNAME}.1 ${PORTNAME}.6)

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/shot.c

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
