PORTNAME=	libunistring
DISTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Unicode string library, Linux version
WWW=		https://www.gnu.org/software/libunistring/

LICENSE=	GFDL GPLv2 LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GFDL=	${WRKSRC}/doc/libunistring.texi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/COPYING.LIB

USES=		cpe libtool linuxsrc:base tar:xz
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
