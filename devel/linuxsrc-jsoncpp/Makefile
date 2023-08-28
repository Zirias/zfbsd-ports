PORTNAME=	jsoncpp
DISTVERSION=	1.9.5
CATEGORIES=	devel

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	JSON reader and writer library for C++, Linux version
WWW=		https://github.com/open-source-parsers/jsoncpp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe linuxsrc:dist meson pkgconfig
CPE_VENDOR=	jsoncpp_project
USE_GITHUB=	yes
GH_ACCOUNT=	open-source-parsers
USE_LDCONFIG=	yes

MESON_ARGS=	--default-library=shared

.include <bsd.port.mk>
