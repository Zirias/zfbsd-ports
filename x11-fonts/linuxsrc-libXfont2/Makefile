PORTNAME=	libXfont2
DISTVERSION=	2.0.5
CATEGORIES=	x11-fonts
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X font library, Linux version
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		libtool linuxsrc:dist pkgconfig tar:bz2
USE_LDCONFIG=	yes
USE_LINUXSRC=	freetype libfontenc xorgproto xtrans

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-devel-docs \
		--disable-static \
		--without-fop \
		--without-xmlto
INSTALL_TARGET=	install-strip

PLIST_FILES=	usr/include/X11/fonts/libxfont2.h \
		usr/${LINUXSRC_LIBDIRNAME}/libXfont2.so \
		usr/${LINUXSRC_LIBDIRNAME}/libXfont2.so.2 \
		usr/${LINUXSRC_LIBDIRNAME}/libXfont2.so.2.0.0 \
		usr/${LINUXSRC_LIBDIRNAME}/pkgconfig/xfont2.pc

.include <bsd.port.mk>
