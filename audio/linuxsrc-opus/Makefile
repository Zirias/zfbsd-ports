PORTNAME=	opus
DISTVERSION=	1.4
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/ \
		https://github.com/xiph/opus/releases/download/v${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	IETF audio codec, Linux version
WWW=		https://opus-codec.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist
CPE_VENDOR=	opus-codec
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doc \
		--disable-static \
		--enable-custom-modes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
