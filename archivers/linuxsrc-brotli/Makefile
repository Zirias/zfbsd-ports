PORTNAME=		brotli
DISTVERSION=		1.0.9
DISTVERSIONPREFIX=	v
CATEGORIES=		archivers devel

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Generic-purpose lossless compression algorithm, Linux version
WWW=		https://github.com/google/brotli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		cpe libtool linuxsrc:dist
CPE_VENDOR=	google
USE_LDCONFIG=	yes
USE_LINUXSRC=	automake:build libtool:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip
PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-patch:
		${REINPLACE_CMD} '/autoreconf/s/ --symlink//' \
			${WRKSRC}/bootstrap

pre-configure:
		cd ${WRKSRC} && ${LINUXBASE}/bin/sh ./bootstrap

.include <bsd.port.mk>
