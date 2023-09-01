PORTNAME=	libwebp
PORTVERSION=	1.3.1
CATEGORIES=	graphics
MASTER_SITES=	http://downloads.webmproject.org/releases/webp/ \
		https://storage.googleapis.com/downloads.webmproject.org/releases/webp/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Google WebP image format libraries, Linux version
WWW=		https://developers.google.com/speed/webp

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist,man
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-libwebpdecoder \
		--enable-libwebpdemux  \
		--enable-libwebpmux \
		build_cwebp=no \
		build_dwebp=no \
		build_gif2webp=no \
		build_img2webp=no \
		build_vwebp=no
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
