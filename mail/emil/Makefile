PORTNAME=	emil
PORTVERSION=	2.1b9
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.uu.se/pub/unix/networking/mail/emil/ \
		ftp://ftp.gwdg.de/pub/misc/emil/ \
		ftp://ftp.funet.fi/pub/unix/mail/emil/ \
		ftp://ftp.enst.fr/pub/unix/network/mail/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.uu.se/pub/unix/networking/mail/emil/
DISTNAME=	${PORTNAME}-2.1.0-beta9

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail format/encoding converter

USES=		cpe

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	YACC=byacc

OPTIONS_DEFINE=	DOCS

DOCS_MAKE_ENV_OFF=	NOPORTDOCS=yes

.include <bsd.port.mk>
