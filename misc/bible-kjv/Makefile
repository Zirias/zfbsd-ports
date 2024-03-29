PORTNAME=	bible-kjv
PORTVERSION=	4.38
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	DEBIAN
DISTNAME=	bible-kjv_${DISTVERSION}

MAINTAINER=	andrew@tao11.riddles.org.uk
COMMENT=	Interactive King James Bible

LICENSE=	GPLv2+

USES=		readline shebangfix perl5
USE_PERL5=	build

# makeindex2 asks for bash, but contains no shell construct more
# complex than an if...then, so use sh instead.

SHEBANG_FILES=	makeindex2 makeconc.pl
bash_CMD=	/bin/sh

# We don't really need all the warning options that the port uses.
PORT_CFLAGS=	-DDESTLIB=\\\"${DATADIR}\\\"

MAKE_ARGS=	DEST="${PREFIX}" \
		CFLAGS="${CPPFLAGS} ${CFLAGS} ${PORT_CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

# Upstream makefile does unsafe things with recursive sub-makes for
# building its build tools. Parallel build randomly fails.
MAKE_JOBS_UNSAFE=yes

WRKSRC=	${WRKDIR}/work

post-build:
	${REINPLACE_CMD} 's=/usr/=${PREFIX}/=g' ${WRKSRC}/bible.1
	cd ${WRKSRC} && \
		${CC} ${CPPFLAGS} ${CFLAGS} -o randverse debian/randverse.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bible ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/randverse ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bible.data ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bible.data.conc ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/bible.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/debian/randverse.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
