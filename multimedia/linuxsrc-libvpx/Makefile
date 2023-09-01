PORTNAME=	libvpx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13.0
CATEGORIES=	multimedia

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	VP8/VP9 reference encoder/decoder, Linux version
WWW=		https://www.webmproject.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm


USES=		cpe linuxsrc:dist
CPE_VENDOR=	webmproject
USE_GITHUB=	yes
GH_ACCOUNT=	webmproject
USE_LDCONFIG=	yes
USE_LINUXSRC=	perl:build

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${LINUXSRC_PREFIX} \
		--disable-install-docs \
		--disable-install-srcs \
		--disable-static \
		--disable-unit-tests \
		--enable-multi-res-encoding \
		--enable-pic \
		--enable-shared \
		--enable-vp9-highbitdepth \
		--enable-vp9-postproc \
		--enable-vp9-temporal-denoising \
		--libdir=${LINUXSRC_LIBDIR} \
		--size-limit=16384x16384
MAKE_ARGS=	verbose=yes
ALL_TARGET=	#

post-patch:
	# FreeBSD 13 diff does not know the --version argument
	@${REINPLACE_CMD} 's|diff --version|hash diff|' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/usr/bin/vpx*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libvpx.so.*.*.*

.include <bsd.port.mk>
