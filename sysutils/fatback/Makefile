PORTNAME=	fatback
PORTVERSION=	1.3
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Recover deleted files from FAT filesystems
WWW=		https://sourceforge.net/project/showfiles.php?group_id=46038

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

INFO=		fatback-manual
EXTRACT_AFTER_ARGS=	--exclude 'getopt*'	\
			--exclude 'set[yl].c'

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s/-Werror//g" ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/fatback-manual.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in fatback-manual.texi texinfo.tex ChangeLog AUTHORS
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
