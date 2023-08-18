PORTNAME=	bash
DISTVERSION=	5.2.15
CATEGORIES=	shells
MASTER_SITES=	GNU/bash

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU Project's Bourne Again SHell, Linux version
WWW=		https://www.gnu.org/software/bash/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LINLIB_DEPENDS=	linuxsrc-readline>0:devel/linuxsrc-readline \
		linuxsrc-ncurses>0:sysutils/linuxsrc-ncurses

USES=		bison cpe linuxsrc:dev,man makeinfo
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-bash-malloc \
		--disable-rpath \
		--enable-disabled-builtins \
		--enable-help-builtin \
		--with-installed-readline

post-install:
		${LN} -s bash ${STAGEDIR}${PREFIX}/usr/bin/sh

.include <bsd.port.mk>
