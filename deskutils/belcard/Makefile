PORTNAME=	belcard
DISTVERSION=	5.3.81
CATEGORIES=	deskutils

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	vCard support library
WWW=		https://www.linphone.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelr.so:textproc/belr

USES=		cmake compiler:c++17-lang
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=YES \
		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_STRICT=NO \
		-DENABLE_UNIT_TESTS=NO

DATADIR=	${PREFIX}/share/BelCard

.include <bsd.port.mk>
