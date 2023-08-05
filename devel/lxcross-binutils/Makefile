PORTNAME=	binutils
DISTVERSION=	${LINUXSRC_V_BINUTILS}
CATEGORIES=	devel
MASTER_SITES=	GNU/binutils

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU binutils for Linux
WWW=		https://www.gnu.org/software/binutils/

LICENSE=		GPLv3 LGPL3
LICENSE_COMB=		multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING3.LIB

BUILD_DEPENDS=	lxcross-glibc>0:devel/lxcross-glibc

USES=		bison gmake libtool linuxsrc:cross makeinfo tar:xz

GNU_CONFIGURE=		yes
CONFIGURE_ARGS= 	--enable-64-bit-bfd \
			--enable-gold \
			--enable-ld=default \
			--enable-plugins \
			--enable-shared \
			--disable-werror
CONFIGURE_OUTSOURCE=	yes

MAKE_ENV=		V=1
INSTALL_TARGET=		install-strip

PLIST_SUB=	BUILDTRIPLET=${LINUXSRC_BUILDTRIPLET}

.include <bsd.port.mk>
