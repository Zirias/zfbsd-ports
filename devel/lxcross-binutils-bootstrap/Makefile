PORTNAME=	binutils
DISTVERSION=	${LINUXSRC_V_BINUTILS}
CATEGORIES=	devel
MASTER_SITES=	GNU/binutils

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU binutils targeting Linux, bootstrap stage
WWW=		https://www.gnu.org/software/binutils/

LICENSE=		GPLv3 LGPL3
LICENSE_COMB=		multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING3.LIB

USES=		gmake makeinfo linuxsrc:boot tar:xz

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-nls \
			--disable-werror \
			--enable-gprofng=no
CONFIGURE_OUTSOURCE=	yes
MAKE_ARGS=		V=1
INSTALL_TARGET=		install-strip

PLIST_SUB=	LXCROSSBASE=${LXCROSSBASE}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/bfd-plugins/libdep.so

.include <bsd.port.mk>
