PORTNAME=	libXmu
DISTVERSION=	1.1.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Miscellaneous Utilities libraries, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist pkgconfig tar:bz2
USE_LDCONFIG=	yes
USE_LINUXSRC=	xorgproto x11 xt xext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
