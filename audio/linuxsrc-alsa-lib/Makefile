PORTNAME=	alsa-lib
DISTVERSION=	1.2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

USE_GITHUB=	yes
GH_ACCOUNT=	alsa-project

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	ALSA library, Linux version
WWW=		https://www.alsa-project.org/

LICENSE=	LGPL21+

USES=		autoreconf cpe libtool linuxsrc:dist tar:bzip2
CPE_VENDOR=	alsa-project
CPE_PRODUCT=	alsa
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
