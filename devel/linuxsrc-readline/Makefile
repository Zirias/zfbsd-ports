PORTNAME=	readline
PORTVERSION=	8.2.${PATCHLEVEL}
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	${PORTNAME}-${PORTVERSION:R}

PATCH_SITES=	GNU/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}-patches

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Library for editing command lines, Linux version
WWW=		https://tiswww.case.edu/php/chet/readline/rltop.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LINLIB_DEPENDS=	linuxsrc-ncurses>0:sysutils/linuxsrc-ncurses

USES=		cpe linuxsrc:dev,man
CPE_VENDOR=	gnu
CPE_VERSION=	${PORTVERSION:R}
USE_LDCONFIG=	yes

# https://ftp.gnu.org/gnu/readline/readline-8.2-patches/
PATCHES=	1
.if defined(PATCHES)
CPE_UPDATE=	${PATCHLEVEL}
PATCHLEVEL=	${PATCHES:O:[-1]}
.for patch in ${PATCHES}
PATCHFILES+=	${PORTNAME}${PORTVERSION:R:S|.||}-${patch:S|^|00|:S|.*(...)$|\1|}
.endfor
.else
PATCHLEVEL=	0
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-curses

MAKE_ARGS=	SHLIB_LIBS="-lncursesw"

PLIST_SUB=	DISTVERSION=${PORTVERSION:R}

post-install:
		@${RMDIR} ${STAGEDIR}${PREFIX}/usr/bin
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.so.*.*

.include <bsd.port.mk>
