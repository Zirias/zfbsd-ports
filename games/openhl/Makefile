PORTNAME=	openhl
PORTVERSION=	20210607
CATEGORIES=	games

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Digital preservation of Half-Life
WWW=		https://github.com/osen/openhl

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		cmake:noninja pkgconfig sdl xorg mono:build python:build
USE_GITHUB=	yes
GH_ACCOUNT=	osen
GH_TAGNAME=	fee890e
USE_SDL=	sdl2
USE_XORG=	x11

PATCH_STRIP=	-p1
OPENHL_HOME=	${LOCALBASE}/lib/openhl

post-patch:
	${REINPLACE_CMD} 's|PREFIX=.*|PREFIX=${OPENHL_HOME}|' \
		${WRKSRC}/system/bin/hl ${WRKSRC}/system/bin/opfor

do-configure:

do-build:
	cd ${WRKSRC}; PYTHON=${PYTHON_CMD} ${SH} build.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/export/bin/hl ${STAGEDIR}${LOCALBASE}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/export/bin/opfor \
		${STAGEDIR}${LOCALBASE}/bin
	(cd ${WRKSRC}/export && ${COPYTREE_SHARE} "lib share" \
		${STAGEDIR}${OPENHL_HOME})
.for bin in libref_soft.so libmenu.so valve/libclient.so valve/libserver.so \
	gearbox/libclient.so gearbox/libserver.so libref_gl.so libxash.so \
	xash3d
	${STRIP_CMD} ${STAGEDIR}${OPENHL_HOME}/lib/xash3d/${bin}
.endfor
	${CHMOD} 555 ${STAGEDIR}${OPENHL_HOME}/lib/xash3d/xash3d

.include <bsd.port.mk>
