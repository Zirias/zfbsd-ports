PORTNAME=	libXdmcp
DISTVERSION=	1.1.3
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Display Manager Control Protocol library, Linux version
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT

USES=		cpe libtool linuxsrc:dist pkgconfig tar:bz2
CPE_VENDOR=	x.org
USE_LDCONFIG=	yes
USE_LINUXSRC=	xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs \
		--disable-static \
		--without-xmlto
INSTALL_TARGET=	install-strip

PLIST_FILES=	usr/include/X11/Xdmcp.h \
		usr/${LINUXSRC_LIBDIRNAME}/libXdmcp.so \
		usr/${LINUXSRC_LIBDIRNAME}/libXdmcp.so.6 \
		usr/${LINUXSRC_LIBDIRNAME}/libXdmcp.so.6.0.0 \
		usr/${LINUXSRC_LIBDIRNAME}/pkgconfig/xdmcp.pc

.include <bsd.port.mk>
