PORTNAME=		libuv
DISTVERSIONPREFIX=	v
DISTVERSION=		1.46.0
CATEGORIES=		devel
MASTER_SITES=		https://dist.libuv.org/dist/v${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Multi-platform async I/O library, Linux version
WWW=		https://github.com/libuv/libuv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf cpe libtool linuxsrc:dist pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

pre-configure:
	${ECHO_CMD} "m4_define([UV_EXTRA_AUTOMAKE_FLAGS], [ serial-tests])" \
		> ${WRKSRC}/m4/libuv-extra-automake-flags.m4

.include <bsd.port.mk>
