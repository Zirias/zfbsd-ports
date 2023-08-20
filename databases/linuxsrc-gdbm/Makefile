PORTNAME=	gdbm
DISTVERSION=	1.23
CATEGORIES=	databases
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU database manager, Linux version
WWW=		https://www.gnu.org.ua/software/gdbm/

LICENSE=	GPLv3+

LINLIB_DEPENDS=	linuxsrc-readline>0:devel/linuxsrc-readline

USES=		libtool linuxsrc:base,man
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-libgdbm-compat

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
