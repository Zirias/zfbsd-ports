PORTNAME=	netcat
PORTVERSION=	1.10
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	SF/${DISTNAME}/unix%20netcat%20${PORTVERSION}%20by%20_Hobbit_/%5BUnnamed%20release%5D
DISTNAME=	nc${PORTVERSION:S/.//}

#PATCH_SITES=	ftp://sith.mimuw.edu.pl/pub/users/baggins/IPv6/
PATCH_SITES=	GENTOO
PATCHFILES=	nc-v6-20000918.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Simple utility which reads and writes data across network connections
WWW=		http://nc110.sourceforge.net/

USES=		tar:tgz
NO_WRKSUBDIR=	yes

CFLAGS+=	-D${OPSYS:tu} -Wno-int-conversion
LDFLAGS+=	-static

PORTDOCS=	README
PLIST_FILES=	bin/netcat share/man/man1/netcat.1.gz

OPTIONS_DEFINE=	IPV6 TELNET GAPING DOCS
OPTIONS_DEFAULT=TELNET GAPING
TELNET_DESC=	Enable TELNET support
GAPING_DESC=	Enable GAPING_SECURITY_HOLE support

IPV6_CFLAGS=	-DINET6
TELNET_CFLAGS=	-DTELNET
GAPING_CFLAGS=	-DGAPING_SECURITY_HOLE

post-patch:
	@${SED} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' ${FILESDIR}/nc.1 \
		> ${WRKDIR}/${PORTNAME}.1

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${PORTNAME}.c -o ${PORTNAME} ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
