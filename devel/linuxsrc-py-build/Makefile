PORTNAME=	build
DISTVERSION=	0.10.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	linuxsrc-py-

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	PEP517 package builder, Linux version
WWW=		https://github.com/pypa/build

LICENSE=	MIT

USES=		linuxsrc:dist
USE_LINUXSRC=	pypkg pyflit:build pyprhooks:run

NO_ARCH=	yes

do-build:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC}; python -m flit_core.wheel'

do-install:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC}; python -m installer \
			--destdir ${STAGEDIR}${PREFIX} --prefix /usr \
			${WRKSRC}/dist/build-${DISTVERSION}*.whl'

.include <bsd.port.mk>
