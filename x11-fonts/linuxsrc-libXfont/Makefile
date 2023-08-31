PORTNAME=	libXfont
DISTVERSION=	1.5.4
CATEGORIES=	x11-fonts
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X font library, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		cpe libtool linuxsrc:dist pkgconfig tar:bz2
CPE_PRODUCT=	libxfont
CPE_VENDOR=	x
USE_LDCONFIG=	yes
USE_LINUXSRC=	freetype libfontenc xorgproto xtrans

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-devel-docs \
		--disable-static \
		--without-xmlto
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
