# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	acme-crossass
DISTVERSIONPREFIX=	code-0-
DISTVERSION=	r102
DISTVERSIONSUFFIX=	-trunk
PORTVERSION=	0.96.4${DISTVERSION}
CATEGORIES=	devel
MASTER_SITES=	https://sourceforge.net/code-snapshots/svn/a/ac/acme-crossass/code-0/
EXTRACT_SUFX=	.zip

MAINTAINER=	felix@palmen-it.de
COMMENT=	Cross-Assembler for 6502/6510/65816 CPU

LICENSE=	GPLv2
USES=		gmake

do-build:
		gmake CC=cc -C ${WRKSRC}/src

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/acme \
			${STAGEDIR}${PREFIX}/bin/acme

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/docs/*.txt ${STAGEDIR}${DOCSDIR}
		
.include <bsd.port.mk>
