PORTNAME=	spindle
PORTVERSION=	3.1
CATEGORIES=	devel
MASTER_SITES=	https://hd0.linusakesson.net/files/

MAINTAINER=	felix@palmen-it.de
COMMENT=	C64 linker, loader and cruncher for trackmos
WWW=		https://www.linusakesson.net/software/spindle/

LICENSE=	MIT

BUILD_DEPENDS=	xa65>0:devel/xa65

USES=		gmake zip

WRKSRC_SUBDIR=	src

OPTIONS_DEFINE=	DOCS EXAMPLES

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's:CFLAGS=:CFLAGS?=:' \
		-e 's:CC=:CC?=:' \
		-e 's:xa:xa65:' \
		${WRKSRC}/Makefile

do-install:
.for b in mkheader mkpef pef2prg pefchain spin
	${INSTALL_PROGRAM} ${WRKSRC}/${b} ${STAGEDIR}${PREFIX}/bin/${b}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../spindle-handbook.pdf ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/../examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})
	(cd ${WRKSRC}/.. && ${COPYTREE_SHARE} template \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
