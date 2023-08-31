PORTNAME=	libFS
DISTVERSION=	1.0.8
CATEGORIES=	x11-fonts
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	The FS library, Linux version
WWW=		https://www.x.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist pkgconfig tar:bz2
CPE_VENDOR=	x
CPE_PRODUCT=	libfs
USE_LDCONFIG=	yes
USE_LINUXSRC=	xorgproto xtrans

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
