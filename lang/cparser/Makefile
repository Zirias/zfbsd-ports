PORTNAME=	cparser
PORTVERSION=	0.9.14
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C99 compiler using libFIRM as backend
WWW=		https://sourceforge.net/projects/cparser/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfirm.so:devel/libfirm

USES=		gmake pkgconfig tar:bzip2

PLIST_FILES=	bin/cparser \
		share/man/man1/cparser.1.gz

BUILDDIR=	optimize

OPTIONS_DEFINE=	DEBUG

DEBUG_VARS=	BUILDDIR=debug

post-patch-DEBUG-off:
	@${REINPLACE_CMD} -e 's/^variant  ?= debug/variant  ?= optimize/' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${BUILDDIR}/cparser ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cparser.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
