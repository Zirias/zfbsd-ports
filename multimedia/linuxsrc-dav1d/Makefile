PORTNAME=	dav1d
DISTVERSION=	1.2.1
CATEGORIES=	multimedia

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Small and fast AV1 decoder, Linux version
WWW=		https://code.videolan.org/videolan/dav1d

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
BUILD_DEPENDS_i386=	nasm:devel/nasm

USES=		linuxsrc:dist meson
USE_GITLAB=	yes
GL_SITE=	https://code.videolan.org
GL_ACCOUNT=	videolan
USE_LDCONFIG=	yes

MESON_ARGS=	-Dxxhash_muxer=disabled

LDFLAGS_i386=	-Wl,-z,notext

.include <bsd.port.mk>
