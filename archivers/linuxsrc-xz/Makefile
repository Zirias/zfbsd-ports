PORTNAME=	xz
DISTVERSION=	5.4.4
CATEGORIES=	archivers
MASTER_SITES=	https://tukaani.org/xz/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	XZ Utils for Linux
WWW=		${MASTER_SITES}

LICENSE=	GPLv2 GPLv3 LGPL21
LICENSE_COMB=	multi

USES=		cpe libtool linuxsrc:base,man tar:xz
CPE_VENDOR=	xz_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
