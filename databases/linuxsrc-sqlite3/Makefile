PORTNAME=	sqlite3
DISTVERSION=	3.42.0
CATEGORIES=	databases
MASTER_SITES=	https://www.sqlite.org/${SDISTYEAR}/ \
		https://www2.sqlite.org/${SDISTYEAR}/ \
		https://www3.sqlite.org/${SDISTYEAR}/
DISTNAME=	sqlite-src-${DISTVERSION:C/\.([[:digit:]])[[:>:]]/0\1/g:S/.//g}00

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	SQL database engine in a C library, Linux version
WWW=		https://www.sqlite.org/

LICENSE=	PD

USES=		libtool linuxsrc:dist zip
USE_LDCONFIG=	yes
USE_LINUXSRC=	tcl:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-fts4 \
		--enable-fts5

CPPFLAGS+=	-DSQLITE_ENABLE_COLUMN_METADATA=1 \
		-DSQLITE_ENABLE_DBSTAT_VTAB=1 \
		-DSQLITE_ENABLE_FTS3_TOKENIZER=1 \
		-DSQLITE_ENABLE_UNLOCK_NOTIFY=1 \
		-DSQLITE_SECURE_DELETE=1

SDISTYEAR=	${%Y:L:gmtime}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/usr/bin/sqlite3
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.so.*.*

.include <bsd.port.mk>
