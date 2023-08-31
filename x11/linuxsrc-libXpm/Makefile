PORTNAME=	libXpm
DISTVERSION=	3.5.15
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Pixmap library, Linux version
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:xz
CPE_VENDOR=	libxpm_project
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xorgproto xt gettext:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
