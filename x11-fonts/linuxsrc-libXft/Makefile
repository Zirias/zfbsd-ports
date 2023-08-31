PORTNAME=	libXft
DISTVERSION=	2.3.7
CATEGORIES=	x11-fonts
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Client-sided font API for X applications, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/Xft/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		libtool linuxsrc:dist,man pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	fontconfig freetype x11 xorgproto xrender

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
