PORTNAME=	python
DISTVERSION=	3.11.5
CATEGORIES=	lang python
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION}
DISTNAME=	Python-${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Interpreted object-oriented programming language, Linux version
WWW=		https://www.python.org/

LICENSE=	PSFL

USES=		cpe linuxsrc:dist pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	expat libffi libuuid sqlite

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-optimizations \
		--enable-shared \
		--exec-prefix=/usr \
		--with-platlibdir=${LINUXSRC_LIBDIRNAME} \
		--with-system-expat \
		--with-system-ffi \
		--without-ensurepip \
		--without-static-libpython

PLIST_SUB=	DISTVERSION=${DISTVERSION} \
		NODOTVER=${DISTVERSION:R:S/.//} \
		SHORTVER=${DISTVERSION:R}

post-patch:
		@${ECHO_CMD} '*disabled*' >${WRKSRC}/Modules/Setup.local
		@${ECHO_CMD} _tkinter >>${WRKSRC}/Modules/Setup.local
		@${ECHO_CMD} nis >>${WRKSRC}/Modules/Setup.local

post-install:
		${FIND} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR} -type f \
			-name \*.so -exec ${STRIP_CMD} \{\} \;
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.so.*.*
		${LN} -s python3 ${STAGEDIR}${PREFIX}/usr/bin/python

.include <bsd.port.mk>
