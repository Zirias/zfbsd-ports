PORTNAME=	libtool
DISTVERSION=	2.4.7
CATEGORIES=	devel
MASTER_SITES=	GNU/libtool

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Generic shared library support script, Linux version
WWW=		https://www.gnu.org/software/libtool/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe linuxsrc:dist,man tar:xz
CPE_VENDOR=	gnu
USE_LINUXSRC=	m4
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-install:
		${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/libltdl.*a

.include <bsd.port.mk>
