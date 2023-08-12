PORTNAME=	zstd
DISTVERSION=	1.5.5
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/facebook/zstd/releases/download/v${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Fast real-time compression algorithm for Linux
WWW=		https://facebook.github.io/zstd/

LICENSE=		BSD3CLAUSE GPLv2
LICENSE_COMB=		dual
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING

LINLIB_DEPENDS=	linuxsrc-zlib>0:archivers/linuxsrc-zlib

USES=		gmake linuxsrc:tchain,man tar:zst
USE_LDCONFIG=	yes

MAKE_ARGS=	libdir=${LINUXSRC_LIBDIR} \
		MANDIR=/usr/share/man \
		PKGCONFIGDIR=${LINUXSRC_LIBDIR}/pkgconfig \
		PREFIX=/usr
MAKE_ENV=	V=1
ALL_TARGET=	default

CPPFLAGS+=	-I${WRKDIR}
LDFLAGS+=	-L${WRKDIR}

pre-build:
		@${LN} -s ${LINUXBASE}/usr/include/zconf.h ${WRKDIR}
		@${LN} -s ${LINUXBASE}/usr/include/zlib.h ${WRKDIR}
		@${LN} -s ${LINUXBASE}${LINUXSRC_LIBDIR}/libz.so ${WRKDIR}
		${MAKE_CMD} CC=${BUILDCC} CXX=${BUILDCXX} \
			-C ${WRKSRC}/contrib/gen_html

post-install:
		@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libzstd.a
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/usr/bin/zstd
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.so.*.*

.include <bsd.port.mk>
