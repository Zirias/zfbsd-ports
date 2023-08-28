PORTNAME=	meson
DISTVERSION=	1.2.1
CATEGORIES=	devel python
MASTER_SITES=	https://github.com/mesonbuild/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	High performance build system, Linux version
WWW=		https://mesonbuild.com/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		linuxsrc:dist
USE_LINUXSRC=	python pybuild:build pysetup:build pywheel:build ninja:run

NO_ARCH=	yes

do-build:
		${LINUXBASE}/bin/sh -c 'cd ${WRKSRC}; \
			python -m build --no-isolation --wheel'

do-install:
		${LINUXBASE}/bin/sh -c \
			'cd ${WRKSRC}; python -m installer \
			--destdir ${STAGEDIR}${PREFIX} --prefix /usr \
			${WRKSRC}/dist/meson-${DISTVERSION}*.whl'

.include <bsd.port.mk>
