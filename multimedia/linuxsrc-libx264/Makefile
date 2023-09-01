# For updating, see and follow multimedia/x264
PORTNAME=	x264
PORTVERSION=	0.${X264_BUILD}.${X264_REV}
CATEGORIES=	multimedia
PKGNAMEPREFIX=	linuxsrc-lib
DIST_SUBDIR=	x264

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	H.264/MPEG-4 AVC Video Encoding, Linux library
WWW=		https://www.videolan.org/x264.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=		${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		linuxsrc:dist
USE_GITLAB=	yes
GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	videolan
GL_TAGNAME=	baee400fa9ced6f5481a728138fed6e867b0ff7f
USE_LDCONFIG=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-cli \
		--disable-opencl \
		--enable-shared \
		--enable-strip \
		--extra-cflags="${CPPFLAGS} ${CFLAGS}" \
		--extra-ldflags="${LDFLAGS}" \
		--host=${LINUXSRC_TRIPLET} \
		--libdir=${LINUXSRC_LIBDIR} \
		--prefix=${LINUXSRC_PREFIX}

PLIST_FILES=	usr/include/x264.h \
		usr/include/x264_config.h \
		usr/${LINUXSRC_LIBDIRNAME}/libx264.so \
		usr/${LINUXSRC_LIBDIRNAME}/libx264.so.${X264_BUILD} \
		usr/${LINUXSRC_LIBDIRNAME}/pkgconfig/x264.pc

X264_BUILD=	164
X264_REV=	3095

.include <bsd.port.mk>
