PORTNAME=	usrinfo
PORTVERSION=	.10
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	aaron@snaphat.com
COMMENT=	Displays information about a user using either "<br>" or "\n" breaks

LICENSE=	BSD2CLAUSE

USES=	tar:bzip2

PLIST_FILES=	bin/usrinfo share/man/man1/usrinfo.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usrinfo ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/usrinfo.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
