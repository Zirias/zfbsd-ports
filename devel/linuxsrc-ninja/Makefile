PORTNAME=	ninja
DISTVERSION=	1.11.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Small build system closest in spirit to Make, Linux version
WWW=		https://ninja-build.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	ninja-build

USES=		linuxsrc:dist
USE_LINUXSRC=	python:build

PLIST_FILES=	usr/bin/ninja

do-build:
	@(cd ${WRKSRC} && CXX="${CXX}" CFLAGS="${CXXFLAGS}" \
		${LINUXBASE}/bin/sh -c 'python configure.py --bootstrap')

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/usr/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ninja ${STAGEDIR}${PREFIX}/usr/bin

.include <bsd.port.mk>
