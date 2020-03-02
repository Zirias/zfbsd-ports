# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	emu64
PORTVERSION=	5.0.18
CATEGORIES=	emulators

MAINTAINER=	felix@palmen-it.de
COMMENT=	Commodore 64 emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png libquazip5.so:archivers/quazip \
	libavcodec.so:multimedia/ffmpeg

USES=	desktop-file-utils gl pkgconfig qmake:outsource qt:5 sdl
USE_GL=	gl glu
USE_QT=	buildtools_build core gui linguisttools_build widgets

USE_SDL=	sdl2 image2
USE_GITHUB=	yes
GH_ACCOUNT=	ThKattanek

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
