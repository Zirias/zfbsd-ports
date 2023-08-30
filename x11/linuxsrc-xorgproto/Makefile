PORTNAME=	xorgproto
DISTVERSION=	2022.1
CATEGORIES=	x11
MASTER_SITES=	XORG/individual/proto
DIST_SUBDIR=	xorg/proto

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X Window System unified protocol definitions, Linux version
WWW=		https://gitlab.freedesktop.org/xorg/proto/xorgproto

LICENSE=	MIT

USES=		linuxsrc:dist tar:bz2
USE_LINUXSRC=	xmacros

NO_ARCH=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-fop \
		--without-xmlto \
		--without-xsltproc \
		--disable-specs

.include <bsd.port.mk>
