PORTNAME=	gnutls
PORTVERSION=	3.7.9
CATEGORIES=	security net
MASTER_SITES=	GNUPG/gnutls/v${PORTVERSION:R}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU Transport Layer Security library, Linux version
WWW=		https://gnutls.org/

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/doc/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/doc/COPYING.LESSER

USES=		cpe libtool linuxsrc:dist,man makeinfo pkgconfig tar:xz
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes
USE_LINUXSRC=	brotli libtasn1 nettle gettext:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-guile \
		--disable-libdane \
		--with-idn \
		--without-p11-kit \
		--without-tpm \
		--without-tpm2
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
