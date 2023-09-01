PORTNAME=	v4l-utils
DISTVERSION=	1.24.1
CATEGORIES=	multimedia
MASTER_SITES=	https://linuxtv.org/downloads/v4l-utils/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Video4Linux utilities and libraries, Linux version
WWW=		https://linuxtv.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

USES=		libtool linuxsrc:dist,man pkgconfig tar:bz2
USE_LDCONFIG=	yes
USE_LINUXSRC=	alsa elfutils jpeg perl:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-doxygen-doc \
		--disable-libdvbv5 \
		--disable-qv4l2 \
		--disable-qvidcap \
		--disable-static \
		--without-libudev
INSTALL_TARGET=	install-strip

post-install:
		@${RM} -r ${STAGEDIR}${PREFIX}/etc
		@${RM} -r ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>

