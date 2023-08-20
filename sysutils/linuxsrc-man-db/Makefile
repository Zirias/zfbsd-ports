PORTNAME=	man-db
DISTVERSION=	2.11.2
CATEGORIES=	sysutils
MASTER_SITES=	SAVANNAH/man-db

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Unix-style manual database for Linux
WWW=		https://www.nongnu.org/man-db/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	linuxsrc-groff>0:textproc/linuxsrc-groff
RUN_DEPENDS=	linuxsrc-groff>0:textproc/linuxsrc-groff
LINLIB_DEPENDS=	linuxsrc-gdbm>0:databases/linuxsrc-gdbm \
		linuxsrc-libpipeline>0:devel/linuxsrc-libpipeline

USES=		libtool linuxsrc:base,man pkgconfig tar:xz

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-setuid \
		--with-browser=lynx \
		--with-systemdsystemunitdir= \
		--with-systemdtmpfilesdir=

.include <bsd.port.mk>
