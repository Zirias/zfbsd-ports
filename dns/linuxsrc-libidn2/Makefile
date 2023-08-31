PORTNAME=	libidn2
DISTVERSION=	2.3.4
CATEGORIES=	dns
MASTER_SITES=	GNU/libidn

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	IDNA2008 internationalized domain names, Linux version
WWW=		https://www.gnu.org/software/libidn/\#libidn2 \
		https://gitlab.com/libidn/libidn2

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LINLIB_DEPENDS=	linuxsrc-libunistring>0:devel/linuxsrc-libunistring

USES=		libtool linuxsrc:base,man makeinfo
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
