PORTNAME=	gettext
DISTVERSION=	0.22
CATEGORIES=	devel
MASTER_SITES=	GNU/gettext

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU gettext, Linux version
WWW=		https://www.gnu.org/software/gettext/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist,man tar:xz
USE_LINUXSRC=	libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/preload*.so

.include <bsd.port.mk>
