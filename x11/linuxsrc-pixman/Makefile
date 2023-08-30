PORTNAME=	pixman
DISTVERSION=	0.42.2
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Low-level pixel manipulation library, Linux version
WWW=		http://pixman.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	perl:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-arm-a64-neon \
		--disable-gtk \
		--disable-static

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
