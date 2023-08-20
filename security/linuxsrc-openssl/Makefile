PORTNAME=	openssl
DISTVERSION=	3.1.2
CATEGORIES=	security devel
MASTER_SITES=	https://www.openssl.org/source/ \
		ftp://ftp.cert.dfn.de/pub/tools/net/openssl/source/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	TLSv1.3 capable SSL and crypto library, Linux version
WWW=		https://www.openssl.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LINLIB_DEPENDS=	linuxsrc-zlib>0:archivers/linuxsrc-zlib

USES=		cpe linuxsrc:base perl5
USE_LDCONFIG=	yes
USE_PERL5=	build

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	config
CONFIGURE_ARGS=		--libdir=${LINUXSRC_LIBDIRNAME} \
			--openssldir=/etc/ssl \
			--prefix=/usr \
			linux-${LINUXSRC_ARCH:S/i386/elf/} \
			shared \
			zlib
CONFIGURE_ENV=		PERL="${PERL}"

ALL_TARGET=	build_sw
INSTALL_TARGET=	install_sw install_ssldirs

post-install:
		@${RMDIR} ${STAGEDIR}${PREFIX}/etc/ssl/certs
		@${RMDIR} ${STAGEDIR}${PREFIX}/etc/ssl/private
		@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.a
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/usr/bin/openssl
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.so.*

.include <bsd.port.mk>
