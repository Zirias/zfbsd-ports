PORTNAME=	icu
DISTVERSION=	73_2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/unicode-org/${PORTNAME}/releases/download/release-${DISTVERSION:S/rc/-&/:S/_/-/g}/ \
		SF/${PORTNAME}/${PORTNAME:tu}4C/${PORTVERSION}
DISTNAME=	icu4c-${DISTVERSION}-src

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	International Components for Unicode (from IBM), Linux version
WWW=		https://icu.unicode.org/

LICENSE=	ICU
LICENSE_NAME=	ICU license
LICENSE_FILE=	${WRKSRC}/../LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe linuxsrc:dist,man tar:tgz
CPE_VENDOR=	${PORTNAME}-project
CPE_PRODUCT=	international_components_for_unicode
USE_LDCONFIG=	yes
USE_LINUXSRC=	python:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-layoutex \
		--disable-renaming \
		--disable-samples \
		--enable-static \
		--with-data-packaging=archive
MAKE_ARGS=	VERBOSE=1

CPPFLAGS+=	-DICU_NO_USER_DATA_OVERRIDE

WRKSRC=		${WRKDIR}/icu/source

PLIST_SUB+=	ICUMAJOR=${ICUMAJOR} ICUVER=${PORTVERSION:C/r.?/1/}

ICUMAJOR=	${PORTVERSION:C/\..*//}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/usr/bin/g* \
		${STAGEDIR}${PREFIX}/usr/bin/*conv \
		${STAGEDIR}${PREFIX}/usr/bin/icuexportdata \
		${STAGEDIR}${PREFIX}/usr/bin/icuinfo \
		${STAGEDIR}${PREFIX}/usr/bin/derb \
		${STAGEDIR}${PREFIX}/usr/bin/pkgdata
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/usr/sbin/*
	@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/lib*.a

.include <bsd.port.mk>
