# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	bitfire
DISTVERSION=	0.6.a.20181001
CATEGORIES=	devel
USE_GITHUB=	yes
GH_ACCOUNT=	bboxy
GH_TAGNAME=	ba41b01

MAINTAINER=	felix@palmen-it.de
COMMENT=	C64 demo-loader/framework

LICENSE=	PD
USES=		gmake
BUILD_DEPENDS=	acme:devel/acme-crossass

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
