# Created by: Tim Vanderhoek <hoek@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cc65
PORTVERSION=	2.17
DISTVERSIONPREFIX=	V
CATEGORIES=	devel
USE_GITHUB=	yes

MAINTAINER=	felix@palmen-it.de
COMMENT=	Cross-compiler for 6502-based systems, includes 65816 assembler

LICENSE=	ZLIB

USES=		gmake

MAKE_ARGS=	CC=cc PREFIX=${PREFIX}
ALL_TARGET=	bin lib

MAKE_JOBS_UNSAFE=	yes

do-install:
		gmake ${MAKE_ARGS} DESTDIR=${STAGEDIR} \
			-C ${WRKSRC}/src install
		gmake ${MAKE_ARGS} DESTDIR=${STAGEDIR} \
			-C ${WRKSRC}/libsrc install

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_BUILD_DEPENDS=	linuxdoc:textproc/linuxdoc-tools makeinfo:print/texinfo
DOCS_ALL_TARGET=	doc
DOCS_INFO=		apple2 apple2enh ar65 atari atari2600 atari5200 atmos \
			c128 c16 c64 ca65 cbm510 cbm610 cc65-intern cc65 \
			chrcvt65 cl65 co65 coding creativision customizing \
			da65 debugging dio funcref gamate geos grc65 index \
			intro ld65 library lynx nes od65 osi pce pet plus4 \
			sim65 smc sp65 supervision telestrat tgi using-make \
			vic20

do-install-DOCS-on:
		gmake ${MAKE_ARGS} DESTDIR=${STAGEDIR} infodir=${PREFIX}/info \
			-C ${WRKSRC}/doc install

do-build-EXAMPLES-on:
		gmake CC65_HOME=${WRKSRC} CFLAGS= PREFIX=${PREFIX} \
			-C ${WRKSRC}/samples

do-install-EXAMPLES-on:
		gmake ${MAKE_ARGS} DESTDIR=${STAGEDIR} \
			-C ${WRKSRC}/samples install

.include <bsd.port.mk>
