PORTNAME=	gcc
DISTVERSION=	${LINUXSRC_V_GCC}
CATEGORIES=	devel
MASTER_SITES=	GNU/gcc/gcc-${DISTVERSION}
PKGNAMESUFFIX=	-libgcc

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GCC libgcc for Linux
WWW=		https://gcc.gnu.org

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

BUILD_DEPENDS=	linuxsrc-zlib>0:archivers/linuxsrc-zlib \
		linuxsrc-zstd>0:archivers/linuxsrc-zstd \
		linuxsrc-gmp>0:math/linuxsrc-gmp \
		linuxsrc-mpc>0:math/linuxsrc-mpc \
		linuxsrc-mpfr>0:math/linuxsrc-mpfr

USES=		gmake libtool linuxsrc:tchain tar:xz
USE_LDCONFIG=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-bootstrap \
			--disable-fixincludes \
			--disable-libstdcxx \
			--enable-default-pie \
			--enable-default-ssp \
			--enable-languages=c,c++ \
			--with-system-zlib
CONFIGURE_ENV=		CC_FOR_BUILD="${BUILDCC}" \
			CXX_FOR_BUILD="${BUILDCXX}" \
			CC_FOR_TARGET=${CC} \
			CXX_FOR_TARGET=${CXX}
CONFIGURE_OUTSOURCE=	yes
MAKE_ENV=		${CONFIGURE_ENV}
ALL_TARGET=		all-target-libgcc
INSTALL_TARGET=		install-strip-target-libgcc

CFLAGS+=	-I${WRKDIR}
LDFLAGS+=	-L${WRKDIR}

PLIST_FILES=	usr/${LINUXSRC_LIBDIRNAME}/libgcc_s.so \
		usr/${LINUXSRC_LIBDIRNAME}/libgcc_s.so.1

LIBGCCSTATICRM=	/usr/lib${"${ARCH:Mi386}":?/gcc:}

pre-configure:
.for h in gmp.h mpc.h mpfr.h zconf.h zdict.h zlib.h zstd.h zstd_errors.h
		@${LN} -s ${LINUXBASE}/usr/include/$h ${WRKDIR}
.endfor
.for l in libgmp.so libmpc.so libmpfr.so libz.so libzstd.so
		@${LN} -s ${LINUXBASE}${LINUXSRC_LIBDIR}/$l ${WRKDIR}
.endfor

post-install:
		@${RM} -r ${STAGEDIR}${PREFIX}${LIBGCCSTATICRM}
		${STRIP_CMD} \
			${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libgcc_s.so.*

.include <bsd.port.mk>
