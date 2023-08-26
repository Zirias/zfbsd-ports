PORTNAME=	libuuid
DISTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Portable uuid C library, Linux version
WWW=		https://libuuid.sourceforge.io/

LICENSE=	BSD3CLAUSE

USES=		libtool linuxsrc:dist
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

PLIST_FILES=	usr/include/uuid/uuid.h \
		usr/${LINUXSRC_LIBDIRNAME}/libuuid.so \
		usr/${LINUXSRC_LIBDIRNAME}/libuuid.so.1 \
		usr/${LINUXSRC_LIBDIRNAME}/libuuid.so.1.0.0 \
		usr/${LINUXSRC_LIBDIRNAME}/pkgconfig/uuid.pc

.include <bsd.port.mk>
