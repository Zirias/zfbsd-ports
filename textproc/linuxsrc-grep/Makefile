PORTNAME=	grep
DISTVERSION=	3.11
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU grep for Linux
WWW=		https://www.gnu.org/software/grep/

LICENSE=	GPLv3+

LINLIB_DEPENDS=	linuxsrc-libsigsegv>0:devel/linuxsrc-libsigsegv \
		linuxsrc-pcre2>0:devel/linuxsrc-pcre2

USES=		cpe linuxsrc:base,man tar:xz
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libsigsegv

.include <bsd.port.mk>
