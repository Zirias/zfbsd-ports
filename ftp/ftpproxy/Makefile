PORTNAME=	ftpproxy
PORTVERSION=	1.2.3
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	http://www.ftpproxy.org/download/ \
		http://www.ftpproxy.org/download/older_releases/

MAINTAINER=	philippe@le-berre.com
COMMENT=	FTP proxy
WWW=		https://www.ftpproxy.org/

USES=		gmake tar:tgz
MAKE_JOBS_UNSAFE=	yes
MAKE_ARGS=	CC="${CC}"

PLIST_FILES=	sbin/ftp.proxy \
		share/man/man1/ftp.proxy.1.gz

pre-build:
	@${REINPLACE_CMD} -e 's|^CFLAGS.*|CFLAGS=${CFLAGS} \
	     -DVERSION=\\"${PORTVERSION}\\"|' ${WRKSRC}/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ftp.proxy ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/ftp.proxy.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
