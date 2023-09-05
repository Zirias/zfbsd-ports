PORTNAME=	libgpg-error
PORTVERSION=	1.47
CATEGORIES=	security devel
MASTER_SITES=	GNUPG

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Common error values for all GnuPG components, Linux version
WWW=		https://www.gnupg.org/software/libgpg-error/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB

USES=		cpe libtool linuxsrc:dist,man tar:bzip2
CPE_VENDOR=	gnupg
USE_LDCONFIG=	yes
USE_LINUXSRC=	gettext

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-install-gpg-error-config
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
