PORTNAME=	graphite2
DISTVERSION=	1.3.14
CATEGORIES=	graphics print
MASTER_SITES=	https://github.com/silnrsi/graphite/releases/download/${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Rendering for non-Roman writing systems, Linux version
WWW=		https://graphite.sil.org

LICENSE=	GPLv2 LGPL21 MPL20
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSE

LDFLAGS+=	-Wl,--as-needed

USES=		cmake cpe libtool linuxsrc:dist tar:tgz
CPE_VENDOR=	sil
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLIB_SUFFIX:STRING="${"${ARCH:Mi386}":?:64}"

.include <bsd.port.mk>
