# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	bitfire
DISTVERSION=	1.0-alpha
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	felix@palmen-it.de
COMMENT=	C64 demo-loader/framework

LICENSE=	PD

BUILD_DEPENDS=	acme>0:devel/acme \
		gsed>0:textproc/gsed

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	bboxy

post-patch:
		${REINPLACE_CMD} -E -e 's:make:$$(MAKE):g' \
			-e "s:$$(printf '\t')@:$$(printf '\t'):" \
			-e 's#([^[:space:]]+\.h)#| \1#' \
			-e 's:sed:gsed:g' \
			${WRKSRC}/bitfire/Makefile \
			${WRKSRC}/bitfire/benchmark/Makefile \
			${WRKSRC}/bitfire/zx0/Makefile

do-build:
		gmake CC=cc -C ${WRKSRC}/bitfire

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/bitfire/bitnax \
			${STAGEDIR}${PREFIX}/bin/bitnax
		${INSTALL_PROGRAM} ${WRKSRC}/bitfire/d64write \
			${STAGEDIR}${PREFIX}/bin/d64write
		(cd ${WRKSRC} && ${COPYTREE_SHARE} "bootstrap installer" \
			${STAGEDIR}${DATADIR})
		${INSTALL_DATA} ${WRKSRC}/*.inc \
			${STAGEDIR}${DATADIR}
		${MKDIR} ${STAGEDIR}${DATADIR}/bitfire
		${INSTALL_DATA} ${WRKSRC}/bitfire/*.inc \
			${STAGEDIR}${DATADIR}/bitfire
		${INSTALL_DATA} ${WRKSRC}/bitfire/request_disc.asm \
			${STAGEDIR}${DATADIR}/bitfire
		${INSTALL_DATA} ${WRKSRC}/bitfire/reset_drive.asm \
			${STAGEDIR}${DATADIR}/bitfire

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_MAN} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_MAN} ${WRKSRC}/Makefile.example.for.demo.build \
			${STAGEDIR}${EXAMPLESDIR}
		
.include <bsd.port.mk>
