PORTNAME=	dev86
PORTVERSION=	0.16.20
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://v3.sk/~lkundrak/dev86/archive/ \
		http://tmp.chruetertee.ch/ \
		http://disasterarea.chruetertee.ch/
DISTNAME=	Dev86src-${PORTVERSION}

MAINTAINER=	phs@deadc0.de
COMMENT=	8086 development tools
WWW=		http://homepage.ntlworld.com/robert.debath/

CONFLICTS=	bcc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DESTDIRNAME=	DIST

post-patch:
	@${REINPLACE_CMD} -e 's|^MANDIR=.*|MANDIR=${PREFIX}/share/man|' \
		${WRKSRC}/Makefile
# Respect CFLAGS in Makefiles.
	@${GREP} -Rl 'CFLAGS=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i "" \
	    -Ee "s|CFLAGS='|&${CFLAGS} |; s|^(CFLAGS=)([^'])|\1${CFLAGS} \2|"

.include <bsd.port.mk>
