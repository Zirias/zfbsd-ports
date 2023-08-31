PORTNAME=	xtrans
DISTVERSION=	1.4.0
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Abstract network code for X, Linux version
WWW=		https://www.x.org/

LICENSE=	MIT

USES=		linuxsrc:dist pkgconfig tar:bz2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs \
		--without-xmlto

NO_ARCH=	yes

.include <bsd.port.mk>
