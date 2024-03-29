PORTNAME=	ipv6toolkit
PORTVERSION=	2.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.si6networks.com/tools/ipv6toolkit/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Set of IPv6 security assessment tools
WWW=		https://www.si6networks.com/tools/ipv6toolkit/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		shebangfix uidfix
SHEBANG_FILES=	tools/blackhole6 tools/script6
MAKE_ENV=	DATADIR=${DATADIR} WRKSRC=${WRKSRC} MANDIR=${PREFIX}/share/man/man
SUB_FILES=	BSDMakefile Makefile Makefile.lib
MAKEFILE=	BSDMakefile
PORTDOCS=	README.TXT CHANGES.TXT CREDITS.TXT

CFLAGS+=	-fPIC

PROGDIRS=	addr6 flow6 frag6 icmp6 jumbo6 na6 ni6 ns6 path6 ra6 rd6 rs6 \
		scan6 tcp6 udp6
LIBDIRS=	libipv6

OPTIONS_DEFINE=	DOCS

post-extract:
	@cd ${WRKSRC} && ${MKDIR} ${PROGDIRS} ${LIBDIRS}

pre-build:
	${INSTALL_DATA} ${WRKDIR}/BSDMakefile ${WRKSRC}
	for D in ${PROGDIRS}; do \
		${INSTALL_DATA} ${WRKDIR}/Makefile ${WRKSRC}/$$D; \
	done
	for D in ${LIBDIRS}; do \
		${INSTALL_DATA} ${WRKDIR}/Makefile.lib ${WRKSRC}/$$D/Makefile; \
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/blackhole6 ${WRKSRC}/tools/script6 \
	    ${STAGEDIR}${PREFIX}/sbin

pre-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
