PORTNAME=	libass
DISTVERSION=	0.17.1
CATEGORIES=	multimedia devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Portable ASS/SSA subtitle renderer, Linux version
WWW=		https://github.com/libass/libass

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${"${ARCH:Maarch64}":?:nasm:devel/nasm}

USES=		cpe libtool linuxsrc:dist pkgconfig tar:xz
CPE_VENDOR=	libass_project
USE_LDCONFIG=	yes
USE_LINUXSRC=	fontconfig freetype fribidi harfbuzz libunibreak

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		${"${ARCH:Maarch64}":?:--enable-asm} \
		--enable-libunibreak

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
