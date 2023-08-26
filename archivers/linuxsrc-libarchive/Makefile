PORTNAME=	libarchive
DISTVERSION=	3.7.1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://libarchive.org/downloads/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Library to handle several archive formats, Linux version
WWW=		https://libarchive.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	expat

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-zstd \
		--with-openssl \
		--without-xml2

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
