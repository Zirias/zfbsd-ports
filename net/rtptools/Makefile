PORTNAME=	rtptools
DISTVERSION=	1.22
PORTREVISION=	1
CATEGORIES=	net mbone

MAINTAINER=	se@FreeBSD.org
COMMENT=	Set of tools to record, playback, and monitor RTPv2 data streams
WWW=		https://www.cs.columbia.edu/irt/software/rtptools/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GITHUB=	yes
GH_ACCOUNT=	irtlab

PORTSCOUT=	limit:^\d.*

.for f in multidump multiplay rtpdump rtpplay rtpsend rtptrans
PLIST_FILES+=	bin/${f}
PLIST_FILES+=	share/man/man1/${f}.1.gz
.endfor

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md ChangeLog.html rtptools.html

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} html
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
