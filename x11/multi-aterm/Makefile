PORTNAME=	multi-aterm
PORTVERSION=	0.2.1
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://www.nongnu.org/materm/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Multi terminal based on aterm
WWW=		https://www.nongnu.org/materm/materm.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Unmaintained, last upstream release in 2004
EXPIRATION_DATE=	2024-04-13

USES=		cpe xorg
USE_XORG=	x11 xpm

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=--with-xpm=${LOCALBASE}

PORTDOCS=	AUTHORS ChangeLog TODO

OPTIONS_DEFINE=	DOCS UTMP WTMP

UTMP_CONFIGURE_ON=	--enable-utmp
WTMP_CONFIGURE_ON=	--enable-wtmp

post-patch:
	${REINPLACE_CMD} -e 's|NULL;|0;|g' \
		${WRKSRC}/src/notebook2.c

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
