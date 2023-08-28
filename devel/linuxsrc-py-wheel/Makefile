PORTNAME=	wheel
DISTVERSION=	0.41.0
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	linuxsrc-py-

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Built-package format for Python, Linux version
WWW=		https://github.com/pypa/wheel

LICENSE=	MIT

USES=		linuxsrc:dist
USE_LINUXSRC=	python pybuild:build pyflit:build

# see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=268500
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar
NO_ARCH=	yes

do-build:
		${LINUXBASE}/bin/sh -c 'cd ${WRKSRC}; \
			python -m build --no-isolation --wheel'

do-install:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC}; python -m installer \
			--destdir ${STAGEDIR}${PREFIX} --prefix /usr \
			${WRKSRC}/dist/wheel-${DISTVERSION}*.whl'

.include <bsd.port.mk>
