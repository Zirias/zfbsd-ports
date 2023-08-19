PORTNAME=	attr
DISTVERSION=	2.5.1
CATEGORIES=	sysutils
MASTER_SITES=	SAVANNAH/attr

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Extended attribute utilities for Linux
WWW=		https://savannah.nongnu.org/projects/attr/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USES=		libtool linuxsrc:base,man tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.so.*.*

.include <bsd.port.mk>
