PORTNAME=	libtasn1
PORTVERSION=	4.19.0
CATEGORIES=	security
MASTER_SITES=	GNU \
		GNUPG/gnutls/${PORTNAME}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	ASN.1 structure parser library, Linux version
WWW=		https://www.gnu.org/software/libtasn1/

LICENSE=	LGPL21+ GPLv3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist pkgconfig
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
