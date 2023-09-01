PORTNAME=	libogg
DISTVERSION=	1.3.5
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/ogg/ \
		https://github.com/xiph/ogg/releases/download/v${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Ogg bitstream library, Linux version
WWW=		https://www.xiph.org/ogg/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
