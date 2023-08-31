PORTNAME=	libXaw
DISTVERSION=	1.0.14
CATEGORIES=	x11-toolkits
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Athena Widgets library, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist,man pkgconfig tar:bz2
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xau xext xmu xpm xorgproto xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--without-xmlto
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
