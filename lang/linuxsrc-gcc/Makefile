PORTNAME=	gcc
DISTVERSION=	${LINUXSRC_V_GCC}
CATEGORIES=	lang
MASTER_SITES=	GNU/gcc/gcc-${DISTVERSION}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GCC for Linux
WWW=		https://gcc.gnu.org

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

RUN_DEPENDS=	linuxsrc-binutils>0:devel/linuxsrc-binutils
LINLIB_DEPENDS=	linuxsrc-gmp>0:math/linuxsrc-gmp \
		linuxsrc-mpc>0:math/linuxsrc-mpc \
		linuxsrc-mpfr>0:math/linuxsrc-mpfr \
		linuxsrc-zlib>0:archivers/linuxsrc-zlib \
		linuxsrc-zstd>0:archivers/linuxsrc-zstd \

USES=		gmake libtool linuxsrc:tchain,man makeinfo tar:xz
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
INSTALL_TARGET=		install-strip

CFLAGS+=	-I${WRKDIR}
LDFLAGS+=	-L${WRKDIR}

PLIST_SUB=	DISTVERSION=${DISTVERSION}

GCCINCFIXDIR=	/usr/lib/gcc/${LINUXSRC_TRIPLET}/${DISTVERSION}/include-fixed
GCCLIBXSUBDIR=	libexec/gcc/${LINUXSRC_TRIPLET}/${DISTVERSION}
GCCWRAPSH=	gccwrap${"${ARCH:Mi386}":?:64}.sh

pre-configure:
.for h in gmp.h mpc.h mpfr.h zconf.h zdict.h zlib.h zstd.h zstd_errors.h
		@${LN} -s ${LINUXBASE}/usr/include/$h ${WRKDIR}
.endfor
.for l in libgmp.so libmpc.so libmpfr.so libz.so libzstd.so
		@${LN} -s ${LINUXBASE}${LINUXSRC_LIBDIR}/$l ${WRKDIR}
.endfor

post-install:
		@${RMDIR} ${STAGEDIR}${PREFIX}/usr/include
		@${RMDIR} ${STAGEDIR}${PREFIX}${GCCINCFIXDIR}
		@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libgcc_s.so*
		@${RM} ${STAGEDIR}${PREFIX}/usr/bin/c++
		${MV} ${STAGEDIR}${PREFIX}/usr/bin/gcc \
			${STAGEDIR}${PREFIX}/usr/bin/gcc.real
		${MV} ${STAGEDIR}${PREFIX}/usr/bin/g++ \
			${STAGEDIR}${PREFIX}/usr/bin/g++.real
		${INSTALL_SCRIPT} ${FILESDIR}/${GCCWRAPSH} \
			${STAGEDIR}${PREFIX}/usr/bin/gcc
		${INSTALL_SCRIPT} ${FILESDIR}/${GCCWRAPSH} \
			${STAGEDIR}${PREFIX}/usr/bin/g++
		${LN} -s gcc ${STAGEDIR}${PREFIX}/usr/bin/cc
		${LN} -s gcc.real ${STAGEDIR}${PREFIX}/usr/bin/cc.real
		${LN} -s g++ ${STAGEDIR}${PREFIX}/usr/bin/c++
		${LN} -s g++.real ${STAGEDIR}${PREFIX}/usr/bin/c++.real
		@${MKDIR} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/bfd-plugins
		${LN} -s ../../${GCCLIBXSUBDIR}/liblto_plugin.so \
			${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/bfd-plugins

.include <bsd.port.mk>
