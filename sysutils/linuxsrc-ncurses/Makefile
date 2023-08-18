PORTNAME=	ncurses
DISTVERSION=	6.4
CATEGORIES=	sysutils devel
MASTER_SITES=	ftp://ftp.invisible-island.net/${PORTNAME}/ \
		https://invisible-mirror.net/archives/ncurses/
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Default curses implementation for Linux
WWW=		https://invisible-island.net/ncurses/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LINLIB_DEPENDS=	linuxsrc-gcc-libstdc++>0:devel/linuxsrc-gcc-libstdc++

USES=		cpe linuxsrc:dev,man
CPE_VENDOR=	gnu
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pc-files \
		--enable-widec \
		--with-cxx-shared \
		--with-shared \
		--without-debug \
		--without-normal \
		--with-pkg-config-libdir=${LINUXSRC_PKGCONFIGDIR}

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-install:
		@-${RM} ${STAGEDIR}${PREFIX}/usr/lib/terminfo
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.so.*.*
.for l in ncurses form panel menu
		${ECHO_CMD} "INPUT(-l${l}w)" > \
			${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/lib${l}.so
		${LN} -s ${l}w.pc \
			${STAGEDIR}${PREFIX}${LINUXSRC_PKGCONFIGDIR}/${l}.pc
.endfor
		${ECHO_CMD} "INPUT(-lncursesw)" > \
			${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libcurses.so
		${ECHO_CMD} "INPUT(-lncursesw)" > \
			${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libcursesw.so

.include <bsd.port.mk>
