PORTNAME=	flit-core
DISTVERSION=	3.9.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
DISTNAME=	flit_core-${DISTVERSION}
PKGNAMEPREFIX=	linuxsrc-py-

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Distribution-building parts of Flit, Linux version
WWW=		https://flit.pypa.io/en/stable/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		linuxsrc:dist
USE_LINUXSRC=	python

NO_ARCH=	yes

PYTHON_SITEDIR=	/usr/lib/python3.11/site-packages

do-build:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC} && python -m flit_core.wheel'

do-install:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC}; \
			python ./bootstrap_install.py --installdir \
				${STAGEDIR}${PREFIX}${PYTHON_SITEDIR} \
				${WRKSRC}/dist/${DISTNAME}*.whl; \
			python -m compileall -d ${PYTHON_SITEDIR} \
				-f ${STAGEDIR}${PREFIX}${PYTHON_SITEDIR}; \
			python -O -m compileall -d ${PYTHON_SITEDIR} \
				-f ${STAGEDIR}${PREFIX}${PYTHON_SITEDIR};'

.include <bsd.port.mk>
