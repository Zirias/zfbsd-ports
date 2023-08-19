PORTNAME=	coreutils
DISTVERSION=	9.3
CATEGORIES=	sysutils
MASTER_SITES=	GNU/coreutils

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU coreutils for Linux
WWW=		https://www.gnu.org/software/coreutils/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LINLIB_DEPENDS=	linuxsrc-acl>0:sysutils/linuxsrc-acl \
		linuxsrc-attr>0:sysutils/linuxsrc-attr \
		linuxsrc-gmp>0:math/linuxsrc-gmp \
		linuxsrc-libcap>0:sysutils/linuxsrc-libcap \
		linuxsrc-openssl>0:security/linuxsrc-openssl

USES=		linuxsrc:base,man tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-no-install-program=chroot,kill,uptime
CONFIGURE_ENV=	FORCE_UNSAFE_CONFIGURE=1

.include <bsd.port.mk>
