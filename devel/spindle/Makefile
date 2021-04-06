# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	spindle
PORTVERSION=	2.3
CATEGORIES=	devel
MASTER_SITES=	https://hd0.linusakesson.net/files/

MAINTAINER=	felix@palmen-it.de
COMMENT=	C64 linker, loader and cruncher for trackmos
WWW=		https://www.linusakesson.net/software/spindle/

LICENSE=	MIT

BUILD_DEPENDS=	xa65>0:devel/xa65

USES=		gmake tar:tgz

WRKSRC_SUBDIR=	${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

MAKE_ENV=	XA=xa65
MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's:CFLAGS=:CFLAGS?=:' \
		-e 's:gcc:$${CC}:' \
		-e 's:xa:$${XA}:' \
		${WRKSRC}/Makefile

do-install:
.for b in mkpef pef2prg pefchain spin
	${INSTALL_PROGRAM} ${WRKSRC}/${b} ${STAGEDIR}${PREFIX}/bin/${b}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/.. && ${COPYTREE_SHARE} \
		"example-pefchain example-spin template" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
