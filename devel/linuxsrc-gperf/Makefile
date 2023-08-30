PORTNAME=	gperf
DISTVERSION=	3.1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Perfect hash functions for sets of keywords, Linux version
WWW=		https://www.gnu.org/software/gperf/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe linuxsrc:dist,man
CPE_VENDOR=	${CPE_PRODUCT}_project
CPE_PRODUCT=	${PORTNAME}tools

GNU_CONFIGURE=	yes

PLIST_FILES=	usr/bin/gperf \
		usr/share/doc/gperf.html \
		usr/share/info/gperf.info \
		usr/share/man/man1/gperf.1.gz

.include <bsd.port.mk>
