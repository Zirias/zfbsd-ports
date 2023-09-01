PORTNAME=	libdrm
DISTVERSION=	2.4.116
CATEGORIES=	graphics x11
MASTER_SITES=	https://dri.freedesktop.org/libdrm/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Userspace interface to DRM services, Linux version
WWW=		https://dri.freedesktop.org/

LICENSE=	MIT

USES=		linuxsrc:dist meson pkgconfig tar:xz
USE_LDCONFIG=	yes
USE_LINUXSRC=	libpciaccess

MESON_ARGS=	-Dcairo-tests=disabled \
		-Detnaviv=disabled \
		-Dexynos=disabled \
		-Dfreedreno=disabled \
		-Dfreedreno-kgsl=false \
		-Dvalgrind=disabled \
		-Dinstall-test-programs=false \
		-Dman-pages=disabled \
		-Dnouveau=disabled \
		-Domap=disabled \
		-Dvc4=disabled

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
MESON_ARGS+=	-Dvmwgfx=enabled \
		-Dintel=enabled
PLIST_SUB+=	INTEL_DRIVER="" VMWGFX_DRIVERS=""
.else
MESON_ARGS+=	-Dvmwgfx=disabled \
		-Dintel=disabled
PLIST_SUB+=	INTEL_DRIVER="@comment _nonexistent/" \
		VMWGFX_DRIVERS="@comment _nonexistent/"
.endif

.include <bsd.port.mk>
