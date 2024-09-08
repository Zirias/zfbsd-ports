PORTNAME=	lime
PORTVERSION=	5.3.81
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	End-to-end encryption library for instant messaging
WWW=		https://www.linphone.org/technical-corner/lime

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelle-sip.so:net/belle-sip \
		libbelr.so:textproc/belr \
		libsoci_sqlite3.so:databases/soci

USES=	cmake
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=YES \
		-DCMAKE_PREFIX_PATH=${LOCALBASE} \
		-DENABLE_STRICT=NO

DATADIR=	${PREFIX}/share/Lime

.include <bsd.port.mk>
