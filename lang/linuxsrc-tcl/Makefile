PORTNAME=	tcl
DISTVERSION=	8.6.13
CATEGORIES=	lang
MASTER_SITES=	SF/tcl/Tcl/${DISTVERSION}
DISTNAME=	${PORTNAME}${DISTVERSION}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Tool Command Language, Linux version
WWW=		https://www.tcl.tk/

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/../license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe linuxsrc:dist,man

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-man-suffix=tcl \
		--enable-shared \
		--enable-threads \
		--includedir=/usr/include/tcl${TCLSHORTVER}

INSTALL_TARGET=	install install-private-headers

WRKSRC_SUBDIR=	unix

PLIST_SUB=	SHORTVER=${TCLSHORTVER}

TCLSHORTVER=	${DISTVERSION:R}
TCLSTRIPFILES=	/usr/bin/tclsh${TCLSHORTVER} \
		${LINUXSRC_LIBDIR}/tdbcmysql1.1.5/libtdbcmysql1.1.5.so \
		${LINUXSRC_LIBDIR}/tdbcodbc1.1.5/libtdbcodbc1.1.5.so \
		${LINUXSRC_LIBDIR}/tdbcpostgres1.1.5/libtdbcpostgres1.1.5.so \
		${LINUXSRC_LIBDIR}/tdbc1.1.5/libtdbc1.1.5.so \
		${LINUXSRC_LIBDIR}/itcl4.2.3/libitcl4.2.3.so \
		${LINUXSRC_LIBDIR}/thread2.8.8/libthread2.8.8.so \
		${LINUXSRC_LIBDIR}/libtcl${TCLSHORTVER}.so \
		${LINUXSRC_LIBDIR}/sqlite3.40.0/libsqlite3.40.0.so

post-build:
	${REINPLACE_CMD} \
	-e "s|${WRKSRC}|${LINUXSRC_LIBDIR}|" \
	-e "s|${WRKSRC:H}|/usr/include/tcl${TCLSHORTVER}|" \
	${WRKSRC}/tclConfig.sh
	${REINPLACE_CMD} \
	-e "s|${WRKSRC}/pkgs/tdbc1.1.5|${LINUXSRC_LIBDIR}/tdbc1.1.5|" \
	-e "s|${WRKSRC:H}/pkgs/tdbc1.1.5/generic|/usr/include/tcl${TCLSHORTVER}|" \
	-e "s|${WRKSRC:H}/pkgs/tdbc1.1.5/library|${LINUXSRC_LIBDIR}/tcl${TCLSHORTVER}|" \
	-e "s|${WRKSRC:H}/pkgs/tdbc1.1.5|/usr/include/tcl${TCLSHORTVER}|" \
	${WRKSRC}/pkgs/tdbc1.1.5/tdbcConfig.sh
	${REINPLACE_CMD} \
	-e "s|${WRKSRC}/pkgs/itcl4.2.3|${LINUXSRC_LIBDIR}/itcl4.2.3|" \
	-e "s|${WRKSRC:H}/pkgs/itcl4.2.3/generic|/usr/include/tcl${TCLSHORTVER}|" \
	-e "s|${WRKSRC:H}/pkgs/itcl4.2.3|/usr/include/tcl${TCLSHORTVER}|" \
	${WRKSRC}/pkgs/itcl4.2.3/itclConfig.sh

.include <bsd.port.pre.mk>

post-install:
.for f in ${TCLSTRIPFILES}
	${CHMOD} 755 ${STAGEDIR}${PREFIX}${f}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}${f}
.endfor
	${LN} -s tclsh${TCLSHORTVER} ${STAGEDIR}${PREFIX}/usr/bin/tclsh

.include <bsd.port.post.mk>
