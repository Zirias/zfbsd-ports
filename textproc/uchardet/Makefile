PORTNAME=	uchardet
DISTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://www.freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal charset detection library
WWW=		https://www.freedesktop.org/wiki/Software/uchardet/

LICENSE=	GPLv2+ LGPL21+ MPL11
LICENSE_COMB=	dual
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang pathfix tar:xz
USE_LDCONFIG=	yes

TEST_TARGET=	test

CMAKE_ARGS=	-DTARGET_ARCHITECTURE=NONE -DCMAKE_INSTALL_MANDIR:PATH=${PREFIX}/share/man

.if defined(WITH_DEBUG)
PLIST_SUB+=	VERSION_SUFFIX=".debug"
.else
PLIST_SUB+=	VERSION_SUFFIX=""
.endif

.include <bsd.port.mk>
