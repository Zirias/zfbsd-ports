PORTNAME=	gawk
DISTVERSION=	5.2.2
CATEGORIES=	lang
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU version of AWK scripting language, Linux version
WWW=		https://www.gnu.org/software/gawk/gawk.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LINLIB_DEPENDS=	linuxsrc-libsigsegv>0:devel/linuxsrc-libsigsegv \
		linuxsrc-readline>0:devel/linuxsrc-readline \
		linuxsrc-gmp>0:math/linuxsrc-gmp \
		linuxsrc-mpfr>0:math/linuxsrc-mpfr

USES=		libtool linuxsrc:base,man makeinfo tar:lz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	AWK=${AWK}

INSTALL_TARGET=	install-strip

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
