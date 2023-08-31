PORTNAME=	gobject-introspection
DISTVERSION=	1.76.1
CATEGORIES=	devel
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Interface introspection for GObject libraries, Linux version
WWW=		https://gi.readthedocs.io/en/latest/

LICENSE=	GPLv2+ LGPL20+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL20+ =	${WRKSRC}/COPYING.LGPL

USES=		bison linuxsrc:dist meson pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	gettext glib libffi python cairo:build

MESON_ARGS=	-Ddoctool=disabled

# A "relative" rpath (using $ORIGIN) doesn't seem to work with Linuxulator,
# work around this by adding an explicit library search path:
MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/${MESON_BUILD_DIR}/girepository

DATADIR=	${PREFIX}/usr/share/${PORTNAME}-1.0
PYTHON_CMD=	${LINUXBASE}/usr/bin/python

post-install:
	@${PYTHON_CMD} -m compileall -d ${LINUXSRC_LIBDIR}/${PORTNAME} \
		"${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/${PORTNAME}"
	@${PYTHON_CMD} -O -m compileall -d ${LINUXSRC_LIBDIR}/${PORTNAME} \
		"${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/${PORTNAME}"
	@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/${PORTNAME}/giscanner/doctemplates/*/meson.build*

.include <bsd.port.mk>
