PORTNAME=	wemux
PORTVERSION=	3.2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Enhances tmux to make multi-user terminal multiplexing easier
WWW=		https://github.com/zolrath/wemux

LICENSE=	MIT

RUN_DEPENDS=	tmux:sysutils/tmux \
		bash:shells/bash

NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	nbraud
GH_TAGNAME=	5de95ad531476773c5c58be48b8bd8bf322eef7e

post-patch:
	@${REINPLACE_CMD} -e 's|$$(SYSCONFDIR)|${ETCDIR}|g' ${WRKSRC}/wemux.in
	@${REINPLACE_CMD} -e 's|$$(SYSCONFDIR)|${ETCDIR}|g' ${WRKSRC}/man/wemux.1.in
	@${REINPLACE_CMD} -e 's|$$(SYSCONFDIR)|${DOCDIR}|g' ${WRKSRC}/man/wemux.1.in

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wemux.in ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/wemux.conf.example ${STAGEDIR}${ETCDIR}/wemux.conf.example
	${INSTALL_MAN} ${WRKSRC}/man/wemux.1.in ${STAGEDIR}${PREFIX}/share/man/man1/wemux.1

.include <bsd.port.mk>
