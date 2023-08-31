PORTNAME=	libxshmfence
DISTVERSION=	1.3.2
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Shared memory 'SyncFence' primitive, Linux version
WWW=		https://gitlab.freedesktop.org/xorg/lib/libxshmfence

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

PLIST_FILES=	usr/include/X11/xshmfence.h \
		usr/${LINUXSRC_LIBDIRNAME}/libxshmfence.so \
		usr/${LINUXSRC_LIBDIRNAME}/libxshmfence.so.1 \
		usr/${LINUXSRC_LIBDIRNAME}/libxshmfence.so.1.0.0 \
		usr/${LINUXSRC_LIBDIRNAME}/pkgconfig/xshmfence.pc

.include <bsd.port.mk>
