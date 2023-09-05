PORTNAME=	libgcrypt
DISTVERSION=	1.10.2
CATEGORIES=	security
MASTER_SITES=	GNUPG

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	General purpose cryptographic library, Linux version
WWW=		https://www.gnupg.org/software/libgcrypt/index.html

LICENSE=	GPLv2+ LGPL21+
LICENSE_COMB=	multi

USES=		cpe libtool linuxsrc:dist,man tar:bzip2
CPE_VENDOR=	gnupg
USE_LDCONFIG=	yes
USE_LINUXSRC=	libgpgerror

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-drng-support \
		--disable-static
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
