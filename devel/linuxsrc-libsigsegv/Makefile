PORTNAME=	libsigsegv
DISTVERSION=	2.14
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Handling page faults in user mode, Linux version
WWW=		https://www.gnu.org/software/libsigsegv/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:base
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	AWK="${AWK}" \
		--disable-static \
		--enable-shared

INSTALL_TARGET=	install-strip

PLIST_FILES=	usr/include/sigsegv.h \
		usr/${LINUXSRC_LIBDIRNAME}/libsigsegv.so \
		usr/${LINUXSRC_LIBDIRNAME}/libsigsegv.so.2 \
		usr/${LINUXSRC_LIBDIRNAME}/libsigsegv.so.2.0.7

.include <bsd.port.mk>
