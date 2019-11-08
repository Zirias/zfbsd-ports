# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	emu64
PORTVERSION=	5.0.17
CATEGORIES=	emulators
USE_GITHUB=	yes
GH_ACCOUNT=	ThKattanek

MAINTAINER=	felix@palmen-it.de
COMMENT=	Commodore 64 emulator
LICENSE=	GPLv2

USES=	qmake:outsource qt:5 sdl
USE_SDL=	sdl2 image2
LIB_DEPENDS=	libpng.so:graphics/png libquazip5.so:archivers/quazip \
	libavcodec.so:multimedia/ffmpeg

.include <bsd.port.mk>
