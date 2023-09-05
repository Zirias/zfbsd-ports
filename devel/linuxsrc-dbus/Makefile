PORTNAME=	dbus
DISTVERSION=	1.14.6
CATEGORIES=	devel gnome
MASTER_SITES=	http://dbus.freedesktop.org/releases/dbus/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Message bus system, Linux version
WWW=		https://www.freedesktop.org/Software/dbus

LICENSE=	GPLv2

USES=		cpe libtool linuxsrc:dist pkgconfig tar:xz
CPE_VENDOR=	d-bus_project
CPE_PRODUCT=	d-bus
USE_LDCONFIG=	yes
USE_LINUXSRC=	expat libice libsm x11 python:build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir=/usr/local/share \
		--disable-apparmor \
		--disable-doxygen-docs \
		--disable-selinux \
		--disable-static \
		--disable-systemd \
		--disable-xml-docs \
		--with-session-socket-dir=/tmp \
		--with-test-socket-dir=${WRKDIR} \
		--with-x

INSTALL_TARGET=	install-strip

post-install:
		${RM} -r ${STAGEDIR}${PREFIX}/etc \
			${STAGEDIR}${PREFIX}/usr/local \
			${STAGEDIR}${PREFIX}/var

.include <bsd.port.mk>
