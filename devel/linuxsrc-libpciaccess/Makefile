PORTNAME=	libpciaccess
PORTVERSION=	0.17
CATEGORIES=	devel
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Generic PCI access library, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson linuxsrc:dist pkgconfig tar:xz
USE_LDCONFIG=	yes

PLIST_FILES=	usr/include/pciaccess.h \
		usr/${LINUXSRC_LIBDIRNAME}/libpciaccess.so \
		usr/${LINUXSRC_LIBDIRNAME}/libpciaccess.so.0 \
		usr/${LINUXSRC_LIBDIRNAME}/libpciaccess.so.0.11.1 \
		usr/${LINUXSRC_LIBDIRNAME}/pkgconfig/pciaccess.pc

.include <bsd.port.mk>
