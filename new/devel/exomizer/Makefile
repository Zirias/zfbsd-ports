# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	exomizer
PORTVERSION=	3.0.0
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/magli143/exomizer/wiki/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	felix@palmen-it.de
COMMENT=	Cruncher for 6502-based systems

LICENSE=	ZLIB EXO
LICENSE_COMB=	multi
LICENSE_NAME_EXO=	exomizer
LICENSE_TEXT_EXO=	The names of this software and/or it's copyright \
			holders may not be used to endorse or promote products \
			derived from this software without specific prior \
			written permission.
LICENSE_PERMS_EXO=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell \
			auto-accept

USES=		gmake

do-extract:
		@${MKDIR} -p ${WRKSRC}
		@unzip -q -d ${WRKSRC} ${DISTDIR}/${DISTFILES}

do-build:
		gmake -C ${WRKSRC}/src

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/exomizer \
			${STAGEDIR}${PREFIX}/bin/exomizer
		${INSTALL_PROGRAM} ${WRKSRC}/src/exobasic \
			${STAGEDIR}${PREFIX}/bin/exobasic
		(cd ${WRKSRC} && ${COPYTREE_SHARE} "exodecrs rawdecrs" \
			${STAGEDIR}${DATADIR})

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}
		
.include <bsd.port.mk>
