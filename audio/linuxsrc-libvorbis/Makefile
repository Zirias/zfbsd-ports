PORTNAME=	libvorbis
DISTVERSION=	1.3.7
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/vorbis/ \
		https://github.com/xiph/vorbis/releases/download/v${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Audio compression codec library, Linux version
WWW=		https://xiph.org/vorbis/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist tar:xz
CPE_VENDOR=	xiph.org
USE_LDCONFIG=	yes
USE_LINUXSRC=	libogg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
