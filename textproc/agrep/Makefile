PORTNAME=	agrep
PORTVERSION=	2.04
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	GENTOO \
		ftp://ftp.cs.arizona.edu/agrep/ \
		ftp://ftp.cs.arizona.edu/agrep/:doc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		agrep.ps.1.Z:doc agrep.ps.2.Z:doc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Approximate grep (fast approximate pattern-matching tool)

# Converted from NO_CDROM
LICENSE=	agrep
LICENSE_NAME=	agrep
LICENSE_TEXT=	No redistribution for profit
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=	tar:Z

CONFLICTS_INSTALL=	rubygem-amatch # bin/agrep

ALL_TARGET=
MAKE_ARGS=	CFLAGS="${CFLAGS}"
PLIST_FILES=	bin/agrep share/man/man1/agrep.1.gz
PORTDOCS=	COPYRIGHT agrep.algorithms agrep.ps.1.Z agrep.ps.2.Z

OPTIONS_DEFINE=	DOCS

post-extract:
	${CP} ${DISTDIR}/agrep.ps.1.Z ${DISTDIR}/agrep.ps.2.Z ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/agrep ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/agrep.1 ${STAGEDIR}${PREFIX}/share/man/man1/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
