PORTNAME=	micropolis
PORTVERSION=	0.0.20180430
CATEGORIES=	games
PKGNAMESUFFIX=	-fbsd

MAINTAINER=	felix@palmen-it.de
COMMENT=	FreeBSD port of Micropolis
WWW=		https://github.com/interkosmos/micropolis

LICENSE=	MICROPOLISGPL
LICENSE_NAME=	Micropolis GPL
LICENSE_FILE=	${WRKSRC}/License.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=	gmake xorg
USE_XORG=	x11 xext xpm

OPTIONS_DEFINE=	DOCS
OPTIONS_RADIO=	SOUND
OPTIONS_RADIO_SOUND=	SOX ALSA SDL
OPTIONS_DEFAULT=	DOCS SOX
SOX_DESC=	Use play command from sox (typically using OSS)

USE_GITHUB=	yes
GH_ACCOUNT=	interkosmos
GH_TAGNAME=	79952cd

MAKEFILE=	makefile
CFLAGS+=	-std=c89 -Wno-return-type
MAKE_ARGS=	CC=${CC} LIBEXECDIR=${PREFIX}/libexec/micropolis
MAKE_JOBS_UNSAFE=	yes

OSS_RUN_DEPENDS=	play:audio/sox
ALSA_RUN_DEPENDS=	aplay:audio/alsa-utils
SDL_RUN_DEPENDS=	playsound:audio/sdl_sound

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSA}
PLAYCMD=aplay
.elif ${PORT_OPTIONS:MSDL}
PLAYCMD=playsound
.elif ${PORT_OPTIONS:MSOX}
PLAYCMD=play
.else
PLAYCMD=true
.endif

SUB_FILES=	player
SUB_LIST=	PLAYCMD=${PLAYCMD}

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS[[:space:]]*=|CFLAGS+=|' \
		${WRKSRC}/src/tclx/ucbsrc/makefile \
		${WRKSRC}/src/tclx/tkucbsrc/makefile \
		${WRKSRC}/src/tclx/ossupp/makefile \
		${WRKSRC}/src/tclx/src/makefile \
		${WRKSRC}/src/tclx/tksrc/makefile \
		${WRKSRC}/src/tclx/makefile \
		${WRKSRC}/src/sim/makefile \
		${WRKSRC}/src/tk/makefile \
		${WRKSRC}/src/tcl/makefile

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/player ${STAGEDIR}${DATADIR}/res/sounds

.include <bsd.port.mk>
