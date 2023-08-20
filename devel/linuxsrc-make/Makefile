PORTNAME=	make
DISTVERSION=	4.4.1
CATEGORIES=	devel
MASTER_SITES=	GNU/make

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU version of 'make' utility, Linux version
WWW=		https://www.gnu.org/software/make/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe linuxsrc:dev,man tar:lz
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-guile

.include <bsd.port.mk>
