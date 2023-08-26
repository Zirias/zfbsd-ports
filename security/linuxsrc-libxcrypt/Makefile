PORTNAME=	libxcrypt
DISTVERSION=	4.4.36
CATEGORIES=	security
MASTER_SITES=	https://github.com/besser82/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Extended crypt library, Linux version
WWW=		https://github.com/besser82/libxcrypt

LICENSE=	LGPL21

USES=		libtool linuxsrc:base,man perl5 tar:xz
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		ac_cv_prog_CC=${LINUXBASE}/usr/bin/gcc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libcrypt.so.1.1.0

.include <bsd.port.mk>
