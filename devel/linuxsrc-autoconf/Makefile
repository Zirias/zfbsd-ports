PORTNAME=	autoconf
DISTVERSION=	2.71
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Generate configure scripts and related files, Linux version
WWW=		https://www.gnu.org/software/autoconf/

LICENSE=	EXCEPTION GFDL GPLv2+ GPLv3+
LICENSE_COMB=	multi
LICENSE_NAME_EXCEPTION=	AUTOCONF CONFIGURE SCRIPT EXCEPTION
LICENSE_FILE_EXCEPTION=	${WRKSRC}/COPYING.EXCEPTION
LICENSE_FILE_GFDL=	${WRKSRC}/doc/fdl.texi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYINGv3
LICENSE_PERMS_EXCEPTION=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		linuxsrc:dist,man tar:xz
USE_LINUXSRC=	m4 perl

GNU_CONFIGURE=	yes

NO_ARCH=	yes

PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
