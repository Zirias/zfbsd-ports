PORTNAME=	nettle
PORTVERSION=	3.9.1
CATEGORIES=	security
MASTER_SITES=	GNU \
		https://www.lysator.liu.se/~nisse/archive/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Low-level cryptographic library, Linux version
WWW=		https://www.lysator.liu.se/~nisse/nettle/

LICENSE=	GPLv2+ LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYINGv2
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LESSERv3

USES=		cpe linuxsrc:dist makeinfo
CPE_VENDOR=	nettle_project
USE_LDCONFIG=	yes
USE_LINUXSRC=	m4:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-shared

post-install:
		${CHMOD} 755 ${STAGEDIR}${PREFIX}/usr/bin/*
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/usr/bin/*
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/lib*.so.*

.include <bsd.port.mk>
