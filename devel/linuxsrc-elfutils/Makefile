PORTNAME=	elfutils
DISTVERSION=	0.189
CATEGORIES=	devel
MASTER_SITES=	https://sourceware.org/elfutils/ftp/${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Library for manipulating ELF files, Linux version
WWW=		https://sourceware.org/elfutils/

LICENSE=	LGPL3 GPLv2+ GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING-GPLV2
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING-LGPLV3

PLIST_SUB=	DISTVERSION=${DISTVERSION}

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:bzip2
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debuginfod \
		--disable-libdebuginfod

post-install:
		@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/lib*.a

.include <bsd.port.mk>
