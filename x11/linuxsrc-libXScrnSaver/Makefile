PORTNAME=	libXScrnSaver
DISTVERSION=	1.2.4
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	The XScrnSaver library, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist,man pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
