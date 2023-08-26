PORTNAME=	libffi
DISTVERSION=	3.4.4
CATEGORIES=	devel
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Foreign Function Interface, Linux version
WWW=		https://sourceware.org/libffi/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe libtool linuxsrc:dist,man
CPE_VENDOR=	libffi_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
