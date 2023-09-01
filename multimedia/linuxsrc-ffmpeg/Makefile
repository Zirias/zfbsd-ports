PORTNAME=	ffmpeg
DISTVERSION=	6.0
CATEGORIES=	multimedia audio net
MASTER_SITES=	https://ffmpeg.org/releases/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Realtime A/V encoder/converter and streaming, Linux version
WWW=		https://ffmpeg.org/

LICENSE=	GPLv3+ LGPL21+
LICENSE_COMB=	multi

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		cpe linuxsrc:dist,man pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	alsa aom dav1d fontconfig freetype frei0r fribidi glvnd \
		gnutls lame lcms2 libass libdrm libva libvdpau libvorbis \
		libvpx libwebp libx264 libxcb libxml2 opus svtav1 v4l x11 \
		x265 \
		perl:build

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	ffbuild/config.log
CONFIGURE_ARGS=	--disable-libcelt \
		--disable-static \
		--enable-alsa \
		--enable-asm \
		--enable-fontconfig \
		--enable-frei0r \
		--enable-gmp \
		--enable-gnutls \
		--enable-gpl \
		--enable-iconv \
		--enable-lcms2 \
		--enable-libaom \
		--enable-libass \
		--enable-libdav1d \
		--enable-libdrm \
		--enable-libfreetype \
		--enable-libfribidi \
		--enable-libmp3lame \
		--enable-libopus \
		--enable-libsvtav1 \
		--enable-libv4l2 \
		--enable-libvorbis \
		--enable-libvpx \
		--enable-libwebp \
		--enable-libx264 \
		--enable-libx265 \
		--enable-libxcb \
		--enable-libxml2 \
		--enable-network \
		--enable-opengl \
		--enable-optimizations \
		--enable-pic \
		--enable-runtime-cpudetect \
		--enable-shared \
		--enable-vaapi \
		--enable-vdpau \
		--enable-version3 \
		--libdir=${LINUXSRC_LIBDIR} \
		--prefix=${LINUXSRC_PREFIX}

MAKE_ENV=	V=1
INSTALL_TARGET=	install-progs install-doc install-data \
		install-libs install-headers install-examples

NOPRECIOUSMAKEVARS=	yes #ARCH

.include <bsd.port.mk>
