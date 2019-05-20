# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	makemkv
PORTVERSION=	1.14.3
CATEGORIES=	multimedia
MASTER_SITES=	http://www.makemkv.com/download/old/:makemkv \
		http://www.makemkv.com/download/:makemkv \
		SF/opencore-amr/fdk-aac/:fdkaac \
		https://ffmpeg.org/releases/:ffmpeg \
		https://www.openssl.org/source/old/${OPENSSLVERSION}/:openssl
DISTFILES=	makemkv-oss-${PORTVERSION}.tar.gz:makemkv \
		makemkv-bin-${PORTVERSION}.tar.gz:makemkv \
		fdk-aac-${FDKAACVERSION}.tar.gz:fdkaac \
		ffmpeg-${FFMPEGVERSION}.tar.bz2:ffmpeg \
		openssl-${OPENSSLFULLVER}.tar.gz:openssl
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	felix@palmen-it.de
COMMENT=	Video converter reading from DVD and Bluray

LICENSE=	MAKEMKV FDK LGPL21+ OpenSSL
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
LICENSE_DISTFILES_OpenSSL=	openssl-${OPENSSLFULLVER}.tar.gz
LICENSE_DISTFILES_MAKEMKV=	makemkv-bin-${PORTVERSION}.tar.gz \
				makemkv-oss-${PORTVERSION}.tar.gz

ONLY_FOR_ARCHS=	amd64 i386
USES=	gmake linux pkgconfig perl5
USE_LINUX=	base expat expat:build openssl openssl:build devtools:build
USE_PERL5=	build
BUILD_DEPENDS=	nasm>0:devel/nasm \
		${LOCALBASE}/include/expat.h:textproc/expat2 \
		patchelf>0:sysutils/patchelf

RESTRICTED=	yes
RESTRICTED_FILES=	makemkv-bin-${PORTVERSION}.tar.gz

WRKSRC=		${WRKDIR}/makemkv-oss-${PORTVERSION}

FDKAACVERSION=	2.0.0
FFMPEGVERSION=	4.1.3
OPENSSLVERSION=	${"${linux_ARGS:Mc7}" != "":?1.0.2:1.0.1}
OPENSSLPATCHLEVEL=	${"${linux_ARGS:Mc7}" != "":?k:e}
OPENSSLFULLVER=	${OPENSSLVERSION}${OPENSSLPATCHLEVEL}

LINUXTRIPLET=	${LINUX_ARCH}-redhat-linux
LINUXLIBDIR=	${LINUXBASE}/${"${LINUX_ARCH:Mx86_64}" != "":?lib64:lib}
OPENSSLTARGET=	${"${LINUX_ARCH:Mx86_64}" != "":?linux-x86_64:linux-elf}

PATCHELF_CMD=	${LOCALBASE}/bin/patchelf
OPTPREFIX=	/opt/makemkv

CFLAGS+=	-DFORCE_OPENSSL_NO_EC \
		-I${WRKDIR}/openssl-${OPENSSLFULLVER}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${WRKDIR}/staticlibs/lib
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${OPTPREFIX} --disable-gui --host=${LINUXTRIPLET}
CONFIGURE_ENV=	CC=${LINUXTRIPLET}-gcc CXX=${LINUXTRIPLET}-g++ \
		PATH=${WRKDIR}/staticlibs/bin:${PATH} \
		PKG_CONFIG_PATH=${WRKDIR}/staticlibs/lib/pkgconfig
MAKE_ENV=	PATH=${WRKDIR}/staticlibs/bin:${PATH}

post-patch:
		@${REINPLACE_CMD} -e 's:INSTALL) -D:INSTALL):' \
			${WRKSRC}/Makefile.in
		@${REINPLACE_CMD} -e 's:/bin/bash:/bin/sh:' \
			-e 's:x86_64:amd64:' \
			-e 's:-t \([^ ]*\) \([^ ]*\):\2 \1:' \
			${WRKDIR}/makemkv-bin-${PORTVERSION}/Makefile

pre-configure:
		${MKDIR} ${WRKDIR}/staticlibs/bin
		cd ${WRKDIR}/staticlibs/bin; \
		for t in gcc link ld objdump ar nm strip ranlib g++; do \
			${LN} -s ${LINUXBASE}/bin/$$t ${LINUXTRIPLET}-$$t; \
		done
		${MKDIR} ${WRKDIR}/staticlibs/lib
		cd ${WRKDIR}/staticlibs/lib; \
			${LN} -s ${LINUXLIBDIR}/libz.so.1 libz.so; \
			${LN} -s ${LINUXLIBDIR}/libcrypto.so.10 libcrypto.so; \
			${LN} -s ${LINUXLIBDIR}/libexpat.so.1 libexpat.so
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
		cd ${WRKDIR}/openssl-${OPENSSLFULLVER}; \
		./Configure --openssldir= --prefix=/usr ${OPENSSLTARGET}

pre-install:
		${MKDIR} ${STAGEDIR}${OPTPREFIX}/lib
		${MKDIR} ${STAGEDIR}${OPTPREFIX}/bin
		${MKDIR} ${STAGEDIR}${OPTPREFIX}/share
		${MKDIR} ${STAGEDIR}${PREFIX}/man/man1
		${INSTALL_MAN} ${FILESDIR}/makemkvcon.1 \
			${STAGEDIR}${PREFIX}/man/man1

post-stage:
		cd ${WRKDIR}/makemkv-bin-${PORTVERSION}; \
		${MKDIR} tmp; \
		${ECHO_CMD} accepted > tmp/eula_accepted; \
		${MAKE_CMD} DESTDIR=${STAGEDIR} PREFIX=${OPTPREFIX} install
		${PATCHELF_CMD} --set-rpath ${OPTPREFIX}/lib \
			${STAGEDIR}${OPTPREFIX}/bin/makemkvcon
		${REINPLACE_CMD} -e 's:/sys/bus/scsi:/opt/makemkv/:' \
			${STAGEDIR}${OPTPREFIX}/bin/makemkvcon
		${INSTALL_SCRIPT} ${SCRIPTDIR}/makemkvcon \
			${STAGEDIR}${PREFIX}/bin
		${INSTALL_SCRIPT} ${SCRIPTDIR}/update-makemkv-drives \
			${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
