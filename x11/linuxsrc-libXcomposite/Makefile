PORTNAME=	libXcomposite
DISTVERSION=	0.4.6
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Composite extension library, Linux version
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist,man pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xfixes xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--without-xmlto
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
