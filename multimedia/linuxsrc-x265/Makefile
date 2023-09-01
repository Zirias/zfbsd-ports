PORTNAME=	x265
PORTVERSION=	3.4
CATEGORIES=	multimedia
MASTER_SITES=	https://bitbucket.org/multicoreware/x265_git/get/${BB_TAG}.tar.gz?meow=/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	H.265/High Efficiency Video Coding (HEVC) format
WWW=		https://www.x265.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC:H}/COPYING

BUILD_DEPENDS=	${"${ARCH:Maarch64}":?:nasm:devel/nasm}

USES=		cmake cpe dos2unix linuxsrc:dist
CPE_VENDOR=	multicorewareinc
DOS2UNIX_FILES=	abrEncApp.cpp
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLIB_INSTALL_DIR:STRING=${LINUXSRC_LIBDIRNAME}
CMAKE_ON=	ENABLE_ASSEMBLY \
		ENABLE_SHARED

CFLAGS+=	-O3

WRKSRC=		${WRKDIR}/multicoreware-x265_git-${BB_TAG}/source

BB_TAG=		25b2c07035ff	# Follow multimedia/x265

post-install:
		@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/lib*.a

.include <bsd.port.mk>
