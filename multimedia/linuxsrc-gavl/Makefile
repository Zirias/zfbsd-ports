PORTNAME=	gavl
PORTVERSION=	1.4.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/gmerlin/${PORTNAME}/${PORTVERSION}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Handle uncompressed video and audio data, Linux version
WWW=		http://gmerlin.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool linuxsrc:dist pkgconfig
USE_LDCONFIG=	yes
USE_LINUXSRC=	libpng

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cpuflags=none \
		--without-doxygen

MAKE_ARGS=	LDFLAGS="${LDFLAGS} -Wl,--as-needed -lm"
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
