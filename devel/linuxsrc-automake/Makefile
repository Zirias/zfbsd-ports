PORTNAME=	automake
DISTVERSION=	1.16.5
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU Standards-compliant Makefile generator, Linux version
WWW=		https://www.gnu.org/software/automake/

LICENSE=	GPLv2+ GFDL
LICENSE_COMB=	multi
LICENSE_FILE_GFDL=	${WRKSRC}/doc/fdl.texi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

USES=		cpe linuxsrc:dist,man tar:xz
CPE_VENDOR=	gnu
USE_LINUXSRC=	autoconf perl

GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/usr/share/${PORTNAME}-${DISTVERSION:R}
NO_ARCH=	yes

PLIST_SUB=	AMVERSION=${DISTVERSION:R}

.include <bsd.port.mk>
