PORTNAME=	libICE
DISTVERSION=	1.1.0
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Inter Client Exchange library for X11, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist pkgconfig tar:xz
CPE_VENDOR=	freedesktop
USE_LDCONFIG=	yes
USE_LINUXSRC=	xorgproto xtrans

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
