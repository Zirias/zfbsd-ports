PORTNAME=	lame
DISTVERSION=	3.100
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Fast MP3 encoder kit, Linux version
WWW=		http://lame.sourceforge.net/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist,man
CPE_VENDOR=	lame_project
USE_LDCONFIG=	yes

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_i386=	nasm:devel/nasm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtktest \
		--disable-static \
		--enable-mp3rtp \
		--enable-nasm
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
