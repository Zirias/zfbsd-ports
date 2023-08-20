PORTNAME=	less
DISTVERSION=	643
CATEGORIES=	sysutils
MASTER_SITES=	http://www.greenwoodsoftware.com/less/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Better pager utility, Linux version
WWW=		https://www.greenwoodsoftware.com/less/

LICENSE=	GPLv3+ MIT
LICENSE_COMB=	dual

LINLIB_DEPENDS=	linuxsrc-ncurses>0:sysutils/linuxsrc-ncurses

USES=		cpe linuxsrc:base,man
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes

PLIST_FILES=	usr/bin/less \
		usr/bin/lessecho \
		usr/bin/lesskey \
		usr/share/man/man1/less.1.gz \
		usr/share/man/man1/lessecho.1.gz \
		usr/share/man/man1/lesskey.1.gz

.include <bsd.port.mk>
