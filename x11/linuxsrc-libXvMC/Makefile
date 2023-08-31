PORTNAME=	libXvMC
DISTVERSION=	1.0.12
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Video Extension Motion Compensation library, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist pkgconfig tar:bz2
CPE_VENDOR=	x
CPE_PRODUCT=	libxvmc
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xorgproto xv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
