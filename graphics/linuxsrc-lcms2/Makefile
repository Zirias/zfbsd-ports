PORTNAME=	lcms2
DISTVERSION=	2.15
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/mm2/Little-CMS/releases/download/lcms${PORTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Small color management engine, Linux version
WWW=		https://www.littlecms.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist,man
CPE_VENDOR=	littlecms
CPE_PRODUCT=	little_cms_color_engine
USE_LDCONFIG=	yes
USE_LINUXSRC=	jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-fastfloat \
		--with-jpeg \
		--with-threaded
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
