PORTNAME=	legesmotus
PORTVERSION=	0.4.0
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Team-based, networked, 2D shooter set in zero-gravity
WWW=		http://legesmotus.cs.brown.edu/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual  # not GPLv2+
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib gmake
USE_CXXSTD=	c++11  # strtoll, atoll
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--mandir="${PREFIX}/share/man" \
		--datadir="${DATADIR}"
MAKE_ENV=	XDIR=${LOCALBASE}

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

PORTDATA=	*

OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT SERVER METASERVER SERVERSCANNER
OPTIONS_DEFAULT=CLIENT SERVER
OPTIONS_SUB=	yes

CLIENT_DESC=		Build client
SERVER_DESC=		Build server
METASERVER_DESC=	Build metaserver
SERVERSCANNER_DESC=	Build server scanner

CLIENT_CONFIGURE_OFF=	--disable-client
CLIENT_USES=		gl sdl
CLIENT_USE=		SDL=sdl,image,ttf,mixer GL=gl
CLIENT_DESKTOP_ENTRIES=	"Leges Motus" \
			"" \
			"${DATADIR}/sprites/blue_head32.png" \
			"legesmotus" \
			"Game;ActionGame;" \
			""
SERVER_CONFIGURE_OFF=		--disable-server
METASERVER_CONFIGURE_ON=	--enable-metaserver
SERVERSCANNER_CONFIGURE_ON=	--enable-serverscanner

.include <bsd.port.mk>
