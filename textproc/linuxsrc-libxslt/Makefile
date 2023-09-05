PORTNAME=	libxslt
DISTVERSION=	1.1.37
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${DISTVERSION:R}/
DIST_SUBDIR=	gnome

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	XML stylesheet transformation library, Linux version
WWW=		https://gitlab.gnome.org/GNOME/libxslt/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:xz
CPE_VENDOR=	xmlsoft
USE_LDCONFIG=	yes
USE_LINUXSRC=	libgcrypt libxml2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-crypto \
		--without-python
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
