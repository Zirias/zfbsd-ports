PORTNAME=	musicpc
DISTVERSION=	0.35
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.musicpd.org/download/mpc/0/
DISTNAME=	mpc-${PORTVERSION}

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Command line client for the musicpd
WWW=		https://www.musicpd.org/clients/mpc/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	rsync>0:net/rsync
LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient

USES=		meson pkgconfig tar:xz

MESON_ARGS=	--mandir=${PREFIX}/share/

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS ICONV
OPTIONS_DEFAULT=	DOCS ICONV

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_USES=	python:env
DOCS_MESON_ENABLED=	documentation

ICONV_USES=	iconv
ICONV_MESON_ENABLED=	iconv
ICONV_LDFLAGS=	-L${ICONV_PREFIX}/lib ${ICONV_LIB}

.include <bsd.port.mk>
