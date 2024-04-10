PORTNAME=	qxmoji
DISTVERSION=	0.7
CATEGORIES=	x11
MASTER_SITES=	${WWW}/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X11 emoji keyboard with Qt GUI
WWW=		https://github.com/Zirias/qxmoji

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	noto-emoji>0:x11-fonts/noto-emoji

FLAVORS=	qt5 qt6
FLAVOR?=	${FLAVORS:[1]}

USES=		compiler:c++17-lang gmake pkgconfig tar:xz \
		qt:${FLAVOR:S/qt//} xorg
_USE_QT5=	core gui widgets x11extras buildtools:build linguisttools:build
_USE_QT6=	base tools:build
USE_QT=		${_USE_QT${FLAVOR:S/qt//}}
USE_XORG=	xcb

MAKEFILE=	GNUmakefile
MAKE_ARGS=	QT_VERSION=${FLAVOR:S/qt//}
ALL_TARGET=	strip

CONFLICTS_INSTALL=	${FLAVORS:S/^/${PORTNAME}-/}
OPTIONS_DEFINE=		DOCS

.include <bsd.port.mk>
