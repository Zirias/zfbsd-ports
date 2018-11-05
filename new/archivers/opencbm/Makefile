# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	opencbm
PORTVERSION=	0.4.99.99a
CATEGORIES=	archivers
USE_GITHUB=	yes
GH_TAGNAME=	v${PORTVERSION}

MAINTAINER=	felix@palmen-it.de
COMMENT=	Commodore CBM serial IEC/IEEE-488 bus utilities

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/OpenCBM-${PORTVERSION}

USES=	gmake

MAKE_ARGS=	CC=cc
MAKE_JOBS_UNSAFE=	yes
MAKEFILE=	LINUX/Makefile

ALL_TARGET=	opencbm plugin-xum1541 plugin-xu1541 plugin-xa1541
INSTALL_TARGET=	install install-plugin-xum1541 install-plugin-xu1541 \
		install-plugin-xa1541

BUILD_DEPENDS=	cc65:devel/cc65

.include <bsd.port.mk>
