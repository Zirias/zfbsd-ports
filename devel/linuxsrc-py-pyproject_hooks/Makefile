PORTNAME=	pyproject_hooks
DISTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	linuxsrc-py-

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Wrappers for pyproject.toml-based build backends, Linux version
WWW=		https://github.com/pypa/pyproject-hooks

LICENSE=	MIT

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
			${WRKSRC}/dist/pyproject_hooks-${DISTVERSION}*.whl'

.include <bsd.port.mk>
