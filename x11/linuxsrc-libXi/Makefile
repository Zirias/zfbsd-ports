PORTNAME=	libXi
DISTVERSION=	1.8
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/lib
DIST_SUBDIR=	xorg/lib

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Input extension library, Linux version
WWW=		https://www.freedesktop.org/Software/xlibs

LICENSE=	MIT

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:bz2
CPE_VENDOR=	x.org
USE_LDCONFIG=	yes
USE_LINUXSRC=	x11 xext xfixes xorgproto

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs \
		--disable-specs \
		--disable-static \
		--without-asciidoc \
		--without-fop \
		--without-xmlto \
		--without-xsltproc
INSTALL_TARGET=	install-strip


.include <bsd.port.mk>
