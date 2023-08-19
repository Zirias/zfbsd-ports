PORTNAME=	acl
DISTVERSION=	2.3.1
CATEGORIES=	sysutils
MASTER_SITES=	SAVANNAH/acl

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	POSIX ACL utilities for Linux
WWW=		https://savannah.nongnu.org/projects/acl/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

LINLIB_DEPENDS=	linuxsrc-attr>0:sysutils/linuxsrc-attr

USES=		libtool linuxsrc:base,man tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.so.*.*

.include <bsd.port.mk>
