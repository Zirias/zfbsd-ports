PORTNAME=	expat
DISTVERSION=	2.5.0
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/libexpat/libexpat/releases/download/R_${DISTVERSION:S|.|_|g}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	XML 1.0 parser written in C
WWW=		https://github.com/libexpat/libexpat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist tar:xz
USE_LDCONFIG=	yes
CPE_VENDOR=	libexpat_project
CPE_PRODUCT=	libexpat

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-docbook --without-examples
INSTALL_TARGET=	install-strip

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
