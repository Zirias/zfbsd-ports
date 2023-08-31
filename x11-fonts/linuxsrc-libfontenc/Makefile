PORTNAME=	libfontenc
DISTVERSION=	1.1.7
CATEGORIES=	x11-fonts
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	The fontenc Library, Linux version
WWW=		https://www.x.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

PLIST_FILES=	usr/include/X11/fonts/fontenc.h \
		usr/${LINUXSRC_LIBDIRNAME}/libfontenc.so \
		usr/${LINUXSRC_LIBDIRNAME}/libfontenc.so.1 \
		usr/${LINUXSRC_LIBDIRNAME}/libfontenc.so.1.0.0 \
		usr/${LINUXSRC_LIBDIRNAME}/pkgconfig/fontenc.pc

.include <bsd.port.mk>
