PORTNAME=	setuptools
DISTVERSION=	63.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	linuxsrc-py-
DIST_SUBDIR=	python

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Python packages installer, Linux version
WWW=		https://pypi.org/project/setuptools/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe linuxsrc:dist
USE_LINUXSRC=	python

CPE_VENDOR=	python

NO_ARCH=	yes

do-build:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC} && python ./setup.py build'

do-install:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC} && python ./setup.py install \
			-c -O1 --prefix=/usr --root=${STAGEDIR}${PREFIX}'

.include <bsd.port.mk>
