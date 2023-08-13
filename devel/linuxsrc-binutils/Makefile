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

LINLIB_DEPENDS=	linuxsrc-zlib>0:archivers/linuxsrc-zlib \
		linuxsrc-zstd>0:archivers/linuxsrc-zstd

USES=	bison gmake libtool linuxsrc:tchain,man makeinfo pkgconfig tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS= 	--enable-64-bit-bfd \
			--enable-gold \
			--enable-host-shared \
			--enable-ld=default \
			--enable-plugins \
			--enable-shared \
			--enable-year2038 \
			--disable-werror \
			--with-system-zlib \
			--with-zstd
CONFIGURE_ENV=		CC_FOR_BUILD="${BUILDCC}" \
			CXX_FOR_BUILD="${BUILDCXX}" \
			PKG_CONFIG_PATH=${LINUXBASE}${LINUXSRC_LIBDIR}/pkgconfig
CONFIGURE_OUTSOURCE=	yes
MAKE_ENV=		V=1 ${CONFIGURE_ENV}
INSTALL_TARGET=		install-strip

CPPFLAGS+=	-I${WRKDIR}
LDFLAGS+=	-L${WRKDIR}

pre-configure:
.for h in zconf.h zdict.h zlib.h zstd.h zstd_errors.h
		@${LN} -s ${LINUXBASE}/usr/include/$h ${WRKDIR}
.endfor
		@${LN} -s ${LINUXBASE}${LINUXSRC_LIBDIR}/libz.so ${WRKDIR}
		@${LN} -s ${LINUXBASE}${LINUXSRC_LIBDIR}/libzstd.so ${WRKDIR}

.include <bsd.port.mk>
