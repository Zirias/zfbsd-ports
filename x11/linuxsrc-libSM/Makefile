PORTNAME=	libSM
DISTVERSION=	1.2.3
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Session Management library for X11, Linux version
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT

USES=		libtool linuxsrc:dist pkgconfig tar:bz2
USE_LDCONFIG=	yes
USE_LINUXSRC=	libice xorgproto xtrans

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs \
		--disable-static \
		--without-xmlto

.include <bsd.port.mk>
