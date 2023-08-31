PORTNAME=	libunibreak
DISTVERSION=	5.1
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/adah1972/${PORTNAME}/releases/download/${PORTNAME}_${DISTVERSION:C/\./_/}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Line and word breaking for Unicode, Linux version
WWW=		http://vimgadgets.sourceforge.net/libunibreak/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		libtool linuxsrc:dist
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

MAKE_ARGS=	LN_S="${INSTALL_DATA}"
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
