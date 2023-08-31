PORTNAME=	libXdamage
DISTVERSION=	1.1.6
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Damage extension library, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist,man pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xfixes xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

PLIST_FILES=	usr/include/X11/extensions/Xdamage.h \
		usr/${LINUXSRC_LIBDIRNAME}/libXdamage.so \
		usr/${LINUXSRC_LIBDIRNAME}/libXdamage.so.1 \
		usr/${LINUXSRC_LIBDIRNAME}/libXdamage.so.1.1.0 \
		usr/${LINUXSRC_LIBDIRNAME}/pkgconfig/xdamage.pc

.include <bsd.port.mk>
