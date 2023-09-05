PORTNAME=	at-spi2-core
PORTVERSION=	2.48.0
CATEGORIES=	accessibility x11-toolkits
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Assistive Technology Service Provider Interface, Linux version
WWW=		https://gitlab.gnome.org/GNOME/at-spi2-core

LICENSE=	LGPL21

USES=		linuxsrc:dist meson pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	dbus gettext glib x11 xi xkbcommon xtst gintrospect:build

MESON_ARGS=	-Dx11=enabled

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/etc \
		${STAGEDIR}${PREFIX}/usr/lib/systemd
	@-${RMDIR} ${STAGEDIR}${PREFIX}/usr/lib

.include <bsd.port.mk>
