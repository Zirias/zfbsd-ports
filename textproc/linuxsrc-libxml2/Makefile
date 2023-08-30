PORTNAME=	libxml2
DISTVERSION=	2.10.4
CATEGORIES=	textproc gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${DISTVERSION:R}/
DIST_SUBDIR=	gnome

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	XML parser library for GNOME, Linux version
WWW=		http://xmlsoft.org/

LICENSE=	MIT

USES=		cpe libtool linuxsrc:dist,man pkgconfig tar:xz
CPE_VENDOR=	xmlsoft
USE_LDCONFIG=	yes
USE_LINUXSRC=	icu

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--with-history \
		--with-icu \
		--without-python

INSTALL_TARGET=	install-strip

PLIST_SUB+=	DISTVERSION=${DISTVERSION}

post-install:
		# Hack to remove any transitive dependencies from xml2-config
		# when invoked without --dynamic, should prevent unnecessary
		# linking
		${REINPLACE_CMD} '/libs=/s/xml2.*/xml2"/' \
			${STAGEDIR}${PREFIX}/usr/bin/xml2-config

.include <bsd.port.mk>
