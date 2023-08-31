PORTNAME=	frei0r
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.1
CATEGORIES=	graphics

MAINTAINER=	zirias@FreeBSD.org
COMMENT?=	Minimalistic plugin API for video effects, Linux version
WWW=		https://frei0r.dyne.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake linuxsrc:dist pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	dyne
USE_LINUXSRC=	cairo gavl

CMAKE_ON=	BUILD_EXTRA_PLUGINS \
		WITHOUT_OPENCV
CMAKE_OFF=	WITHOUT_CAIRO \
		WITHOUT_GAVL

.include <bsd.port.mk>
