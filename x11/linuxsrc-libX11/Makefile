PORTNAME=	libX11
DISTVERSION=	1.8.6
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X11 library, Linux version
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:xz
CPE_VENDOR=	x
USE_LDCONFIG=	yes
USE_LINUXSRC=	libxcb xorgproto xtrans

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-specs \
		--disable-static \
		--with-perl=no \
		--without-xmlto
CONFIGURE_ENV=	ac_cv_path_PS2PDF=""
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
