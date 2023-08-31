PORTNAME=	libXext
DISTVERSION=	1.3.4
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X11 Extension library, Linux version
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:bz2
CPE_VENDOR=	x
CPE_PRODUCT=	libxext
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xau xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-specs \
		--disable-static \
		--without-xmlto
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
