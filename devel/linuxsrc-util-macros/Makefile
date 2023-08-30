PORTNAME=	util-macros
DISTVERSION=	1.19.3
CATEGORIES=	devel x11
MASTER_SITES=	XORG/individual/util
DIST_SUBDIR=	xorg/util

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	X.Org development aclocal macros, Linux version
WWW=		https://cgit.freedesktop.org/xorg/util/macros/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		linuxsrc:dist tar:bz2

NO_ARCH=	yes

GNU_CONFIGURE=	yes
MAKE_ARGS=	pkgconfigdir=${LINUXSRC_PKGCONFIGDIR}

PLIST_FILES=	usr/share/aclocal/xorg-macros.m4 \
		${LINUXSRC_PKGCONFIGDIR:S/^\///}/xorg-macros.pc \
		usr/share/util-macros/INSTALL

.include <bsd.port.mk>
