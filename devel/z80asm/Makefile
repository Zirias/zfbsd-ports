PORTNAME=	z80asm
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://savannah.c3sl.ufpr.br/${PORTNAME}/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

MAINTAINER=	sigma.zx@gmail.com
COMMENT=	Assembler for the Z80 microprocessor
WWW=		https://savannah.nongnu.org/projects/z80asm/

OPTIONS_DEFINE=	EXAMPLES

USES=		gmake

do-install:
	${INSTALL_MAN} ${WRKSRC}/z80asm.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/z80asm ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.asm ${WRKSRC}/headers/*.asm \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
