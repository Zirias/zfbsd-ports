PORTNAME=	armadillo
PORTVERSION=	12.6.7
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	SF/arma

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ linear algebra library
WWW=		https://arma.sourceforge.net/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libarpack.so:math/arpack-ng \
		liblapack.so:math/lapack \
		libsuperlu.so:math/superlu

USES=		blaslapack:openblas cmake:testing compiler:c++11-lang pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

CMAKE_OFF=	BUILD_SMOKE_TEST
CMAKE_TESTING_ON=	BUILD_SMOKE_TEST

.include <bsd.port.mk>
