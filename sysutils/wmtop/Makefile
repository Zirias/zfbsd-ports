PORTNAME=	wmtop
PORTVERSION=	0.84
PORTREVISION=	4
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp to display top three CPU consuming processes
WWW=		https://wmtop.sourceforge.net/

LICENSE=	GPLv2

USES=		gmake xorg		# gmake is needed for -jX builds
USE_XORG=	xpm x11
USE_CSTD=	gnu89
ALL_TARGET=	freebsd
CFLAGS+=	-fcommon  # clang11/gcc10

PORTDOCS=	BUGS CHANGES README TODO
PLIST_FILES=	bin/wmtop \
		share/man/man1/wmtop.1.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's/^\(LIBS.*\)/\1 -lkvm/ ; \
		s/^\(FLAGS.*\)/\1 -DNO_PROCFS/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmtop ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmtop.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
