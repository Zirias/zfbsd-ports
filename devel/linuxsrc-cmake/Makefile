PORTNAME=	cmake
DISTVERSION=	3.27.4
CATEGORIES=	devel
MASTER_SITES=	https://github.com/Kitware/CMake/releases/download/v${DISTVERSION}/ \
		https://www.cmake.org/files/v${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Cross-platform Makefile generator
WWW=		https://www.cmake.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

USES=		cpe linuxsrc:dist
CPE_VENDOR=	cmake_project
USE_LINUXSRC=	expat jsoncpp libarchive libuv rhash

HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --datadir=/share/cmake \
		--docdir=/share/doc/cmake \
		--no-system-curl \
		--no-system-nghttp2 \
		--parallel=${MAKE_JOBS_NUMBER} \
		--prefix=/usr \
		--system-expat \
		--system-jsoncpp \
		--system-zlib \
		--system-zstd \
		--system-bzip2 \
		--system-liblzma \
		--system-libarchive \
		--system-librhash \
		--system-libuv

INSTALL_TARGET=	install/strip

.include <bsd.port.mk>
