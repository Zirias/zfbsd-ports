PORTNAME=	scr2txt
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/nik

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts the output of "vidcontrol -p" to text

NO_WRKSUBDIR=	yes
USES=		uidfix
MAKE_ENV=	BINDIR=${PREFIX}/bin SHAREDIR=${PREFIX}/share

PLIST_FILES=	bin/scr2txt \
		share/man/man1/scr2txt.1.gz

.include <bsd.port.mk>
