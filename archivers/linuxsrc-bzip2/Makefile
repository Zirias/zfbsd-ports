PORTNAME=	bzip2
DISTVERSION=	1.0.8
CATEGORIES=	archivers
MASTER_SITES=	https://sourceware.org/pub/bzip2/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Block-sorting file compressor, Linux version
WWW=		https://sourceware.org/bzip2/

LICENSE=	BZIP2
LICENSE_NAME=	BZIP2 license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe linuxsrc:base,man
CPE_VENDOR=	bzip
USE_LDCONFIG=	yes

MAKE_ARGS=		CC="${CC} ${CFLAGS}" \
			PREFIX=${STAGEDIR}${PREFIX}/usr
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-patch:
		@${REINPLACE_CMD} \
			-e 's|)/lib|)/${LINUXSRC_LIBDIRNAME}|g' \
			-e 's|)/man|)/share/man|g' \
			-e 's|$$(PREFIX)/bin/\([^[:space:]]* \)|\1|' \
			${WRKSRC}/Makefile
		@${ECHO_CMD} -e \
			"so: clean\n\t\$$(MAKE) -f Makefile-libbz2_so\n" \
			>>${WRKSRC}/Makefile
		@${ECHO_CMD} "all: so" >>${WRKSRC}/Makefile

post-install:
		@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libbz2.a
		${INSTALL_LIB} ${WRKSRC}/libbz2.so.${DISTVERSION} \
			${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}
		${LN} -s libbz2.so.${DISTVERSION} \
			${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libbz2.so.1
		${LN} -s libbz2.so.1 \
			${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libbz2.so
.for b in bunzip2 bzcat bzip2 bzip2recover
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/usr/bin/${b}
.endfor

.include <bsd.port.mk>
