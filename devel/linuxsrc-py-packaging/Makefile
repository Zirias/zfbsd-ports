PORTNAME=	packaging
DISTVERSION=	23.1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	linuxsrc-py-

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Core utilities for Python packages, Linux version
WWW=		https://github.com/pypa/packaging

LICENSE=	APACHE20 BSD2CLAUSE
LICENSE_COMB=	dual

USES=		linuxsrc:dist
USE_LINUXSRC=	pyinst pyflit:build

NO_ARCH=	yes

do-build:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC}; python -m flit_core.wheel'

do-install:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC}; python -m installer \
			--destdir ${STAGEDIR}${PREFIX} --prefix /usr \
			${WRKSRC}/dist/packaging-${DISTVERSION}*.whl'

.include <bsd.port.mk>
