PORTNAME=	xcb-proto
DISTVERSION=	1.15.2
CATEGORIES=	x11 python
MASTER_SITES=	XORG/individual/proto
DIST_SUBDIR=	xorg/proto

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) protocol, Linux version
WWW=		https://xcb.freedesktop.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		linuxsrc:dist tar:xz
USE_LINUXSRC=	libxml2:build python:build

GNU_CONFIGURE=	yes
MAKE_ARGS=	pkgconfigdir=${LINUXSRC_PKGCONFIGDIR}

DATADIR=	${PREFIX}/usr/share/xcb
NO_ARCH=	yes

.include <bsd.port.mk>
