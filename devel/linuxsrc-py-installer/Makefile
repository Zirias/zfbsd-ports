PORTNAME=	installer
DISTVERSION=	0.7.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	linuxsrc-py-

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Library for installing Python wheels
WWW=		https://github.com/pypa/installer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		linuxsrc:dist
USE_LINUXSRC=	python pyflit:build

NO_ARCH=	yes

do-build:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC}; python -m flit_core.wheel'

do-install:
		PYTHONPATH=${WRKSRC}/src ${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC}; python -m installer \
			--destdir ${STAGEDIR}${PREFIX} --prefix /usr \
			${WRKSRC}/dist/installer-${DISTVERSION}*.whl'

.include <bsd.port.mk>
