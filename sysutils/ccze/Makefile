PORTNAME=	ccze
PORTVERSION=	0.2.1
PORTREVISION=	6
CATEGORIES=	sysutils
MASTER_SITES=	http://falafel.200ok.org/distfiles/ccze/ \
		http://200ok.org/distfiles/ccze/

MAINTAINER=	ecu@200ok.org
COMMENT=	Fast log colorizer
WWW=		http://bonehunter.rulez.org/CCZE.phtml

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		gmake ncurses
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	FAQ

.include <bsd.port.options.mk>

post-install:
	@${WRKSRC}/src/ccze-dump > ${STAGEDIR}${PREFIX}/etc/cczerc-sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${STAGEDIR}${DOCSDIR}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/*.so

.include <bsd.port.mk>
