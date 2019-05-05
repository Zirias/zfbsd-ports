# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	makemkv
PORTVERSION=	1.14.3
CATEGORIES=	multimedia
DIST_SUBDIR=	${PORTNAME}

FDKAACVERSION=	2.0.0
FFMPEGVERSION=	4.1.3

MASTER_SITES=	http://www.makemkv.com/download/old/:makemkv \
		http://www.makemkv.com/download/:makemkv \
		SF/opencore-amr/fdk-aac/:fdkaac \
		https://ffmpeg.org/releases/:ffmpeg
DISTFILES=	makemkv-oss-${PORTVERSION}.tar.gz:makemkv \
		makemkv-bin-${PORTVERSION}.tar.gz:makemkv \
		fdk-aac-${FDKAACVERSION}.tar.gz:fdkaac \
		ffmpeg-${FFMPEGVERSION}.tar.bz2:ffmpeg

RESTRICTED=	yes
RESTRICTED_FILES=	makemkv-bin-${PORTVERSION}.tar.gz
ONLY_FOR_ARCHS=	i386 amd64

LICENSE=	MAKEMKV FDK LGPL21+
LICENSE_COMB=	multi
LICENSE_NAME_MAKEMKV=	The MakeMKV EULA
LICENSE_NAME_FDK=	The FDK AAC License
LICENSE_FILE_MAKEMKV=	${WRKDIR}/makemkv-bin-${PORTVERSION}/src/eula_en_linux.txt
LICENSE_FILE_FDK=	${WRKDIR}/fdk-aac-${FDKAACVERSION}/NOTICE
LICENSE_PERMS_MAKEMKV=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell \
			no-auto-accept
LICENSE_PERMS_FDK=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell \
			auto-accept
LICENSE_DISTFILES_FDK=	fdk-aac-${FDKAACVERSION}.tar.gz
LICENSE_DISTFILES_LGPL21+ =	ffmpeg-${FFMPEGVERSION}.tar.bz2
LICENSE_DISTFILES_MAKEMKV=	makemkv-bin-${PORTVERSION}.tar.gz \
				makemkv-oss-${PORTVERSION}.tar.gz

MAINTAINER=	felix@palmen-it.de
COMMENT=	Video converter reading from DVD and Bluray

WRKSRC=		${WRKDIR}/makemkv-oss-${PORTVERSION}

BUILD_DEPENDS=	nasm>0:devel/nasm \
		${LOCALBASE}/include/expat.h:textproc/expat2 \
		patchelf>0:sysutils/patchelf

USES=	gmake linux pkgconfig ssl:build
USE_LINUX=	base expat expat:build openssl openssl:build devtools:build

LINUXTRIPLET=	${LINUX_ARCH}-redhat-linux
LINUXLIBDIR=	${LINUXBASE}/${LINUX_ARCH:Mx86_64:?lib64:lib}

PREFIX=		/opt/makemkv
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-gui --host=${LINUXTRIPLET}
CONFIGURE_ENV=	CC=${LINUXTRIPLET}-gcc CXX=${LINUXTRIPLET}-g++ \
		PATH=${WRKDIR}/staticlibs/bin:${PATH} \
		PKG_CONFIG_PATH=${WRKDIR}/staticlibs/lib/pkgconfig \
		CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${WRKDIR}/staticlibs/lib

MAKE_ENV=	PATH=${WRKDIR}/staticlibs/bin:${PATH}

do-patch:
		sed -ie 's:INSTALL) -D:INSTALL):' ${WRKSRC}/Makefile.in
		sed -ie 's:/bin/bash:/bin/sh:' \
			${WRKDIR}/makemkv-bin-${PORTVERSION}/Makefile
		sed -ie 's:x86_64:amd64:' \
			${WRKDIR}/makemkv-bin-${PORTVERSION}/Makefile
		sed -ie 's:-t \([^ ]*\) \([^ ]*\):\2 \1:' \
			${WRKDIR}/makemkv-bin-${PORTVERSION}/Makefile

pre-configure:
		${MKDIR} ${WRKDIR}/staticlibs/bin
		cd ${WRKDIR}/staticlibs/bin; \
		for t in gcc link ld objdump ar nm strip ranlib g++; do \
			ln -s ${LINUXBASE}/bin/$$t ${LINUXTRIPLET}-$$t; \
		done
		${MKDIR} ${WRKDIR}/staticlibs/lib
		cd ${WRKDIR}/staticlibs/lib; \
			ln -s ${LINUXLIBDIR}/libz.so.1 libz.so; \
			ln -s ${LINUXLIBDIR}/libcrypto.so.10 libcrypto.so; \
			ln -s ${LINUXLIBDIR}/libexpat.so.1 libexpat.so
		cd ${WRKDIR}/fdk-aac-${FDKAACVERSION}; \
		PATH=${WRKDIR}/staticlibs/bin:$$PATH \
		LDFLAGS=-L${WRKDIR}/staticlibs/lib \
		./configure --prefix=${WRKDIR}/staticlibs \
			--disable-shared --enable-static --with-pic \
			--host=${LINUXTRIPLET}; \
		PATH=${WRKDIR}/staticlibs/bin:$$PATH \
		${MAKE_CMD} install
		cd ${WRKDIR}/ffmpeg-${FFMPEGVERSION}; \
		PATH=${WRKDIR}/staticlibs/bin:$$PATH \
		PKG_CONFIG_PATH=${WRKDIR}/staticlibs/lib/pkgconfig \
		CPPFLAGS="-Dcaddr_t=void\* -D__daddr_t_defined" \
		LDFLAGS=-L${WRKDIR}/staticlibs/lib \
		./configure --prefix=${WRKDIR}/staticlibs \
			--disable-shared --enable-static --enable-pic \
			--enable-libfdk-aac --pkg-config=pkg-config \
			--cross-prefix=${LINUXTRIPLET}- --arch=${LINUX_ARCH} \
			--target-os=linux --host-cc=${CC}; \
		PATH=${WRKDIR}/staticlibs/bin:$$PATH \
		${MAKE_CMD} ARCH=x86 && \
		PATH=${WRKDIR}/staticlibs/bin:$$PATH \
		${MAKE_CMD} install

post-stage:
		cd ${WRKDIR}/makemkv-bin-${PORTVERSION}; \
		${MKDIR} tmp; \
		echo accepted > tmp/eula_accepted; \
		${MAKE_CMD} DESTDIR=${STAGEDIR} PREFIX=${PREFIX} install
		patchelf --set-rpath ${PREFIX}/lib \
			${STAGEDIR}${PREFIX}/bin/makemkvcon
		sed -ie 's:/sys/bus/scsi:/opt/makemkv/:' \
			${STAGEDIR}${PREFIX}/bin/makemkvcon
		${MKDIR} ${STAGEDIR}${LOCALBASE}/bin
		mv ${STAGEDIR}${PREFIX}/bin/makemkvcon \
			${STAGEDIR}${LOCALBASE}/bin
		${MKDIR} ${STAGEDIR}${LOCALBASE}/sbin
		${INSTALL_SCRIPT} ${SCRIPTDIR}/update-makemkv-drives \
			${STAGEDIR}${LOCALBASE}/sbin

.include <bsd.port.mk>
