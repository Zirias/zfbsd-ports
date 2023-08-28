PORTNAME=	rhash
DISTVERSION=	1.4.3
CATEGORIES=	security
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Utility and library for file hashes, Linux version
WWW=		http://rhash.sourceforge.net/

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe linuxsrc:dist,man
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-gettext \
		--enable-openssl \
		--extra-cflags="${CFLAGS}" \
		--extra-ldflags="${LDFLAGS}" \
		--libdir=${LINUXSRC_LIBDIR} \
		--prefix=/usr \
		--sysconfdir=/etc

INSTALL_TARGET=	install install-lib-headers \
		install-lib-so-link install-pkg-config

WRKSRC=		${WRKDIR}/RHash-${DISTVERSION}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.so.*

.include <bsd.port.mk>
