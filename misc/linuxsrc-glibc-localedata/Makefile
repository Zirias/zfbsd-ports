PORTNAME=	glibc
DISTVERSION=	${LINUXSRC_V_GLIBC}
CATEGORIES=	misc
MASTER_SITES=	GNU/glibc
PKGNAMEPREFIX=	linuxsrc-
PKGNAMESUFFIX=	-localedata

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Locale data from GNU glibc for Linux
WWW=		https://www.gnu.org/software/libc/

LICENSE=	GPLv2

BUILD_DEPENDS=	linuxsrc-glibc>0:devel/linuxsrc-glibc
RUN_DEPENDS=	linuxsrc-glibc>0:devel/linuxsrc-glibc

USES=			gmake linuxsrc:env tar:xz
USE_LINUX_PREFIX=	yes

MAKE_ARGS=	install_root=${STAGEDIR}${PREFIX} \
		LOCALEDEF=${LOCALEDEF_CMD}
INSTALL_TARGET=	install-locales

LOCALEDEF_CMD=	${LINUXBASE}/usr/bin/localedef
NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC_SUBDIR=	localedata

PLIST_FILES=	usr/lib/locale/locale-archive

post-patch:
		@${REINPLACE_CMD} \
			-e '/include \.\./d' \
			-e 's/: install-locales-dir/:/' \
			${WRKSRC}/Makefile

pre-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/usr/lib/locale
		-${LOCALEDEF_CMD} --prefix=${STAGEDIR}${PREFIX} \
			-i POSIX -f UTF-8 C.UTF-8 2>/dev/null

.include <bsd.port.mk>
