PORTNAME=	linphone
DISTVERSION=	5.2.6
PORTEPOCH=	1
CATEGORIES=	net

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	SIP client supporting voice/video calls and text messaging
WWW=		https://www.linphone.org/

LICENSE=	GPLv3

LIB_DEPENDS=	libbctoolbox.so:net/bctoolbox \
		libbelcard.so:deskutils/belcard \
		liblinphone++.so:net/liblinphone \
		libmediastreamer2.so:net/mediastreamer \
		libortp.so:net/ortp

USES=		cmake compiler:c++11-lib pkgconfig qt:5
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public
GL_PROJECT=	linphone-desktop
USE_QT=		concurrent core dbus declarative gui linguisttools multimedia \
		network quickcontrols2 speech svg testlib widgets \
		buildtools:build qmake:build \
		graphicaleffects:run quickcontrols:run

# Linphone's plugin API is implemented in a shared object with rather generic
# SONAME and filename, libapp-plugin.so. For classic installation in the
# local tree, we better move it to its own subdirectory, so we need RPATH
# here.
# This will affect actual Linphone plugins as well if they get ported.
CMAKE_ARGS=	-DCMAKE_INSTALL_DATADIR="${LOCALBASE}/share" \
		-DCMAKE_INSTALL_RPATH="${LOCALBASE}/lib/linphone" \

WRKSRC_SUBDIR=	linphone-app

#ICONDIR=	${LOCALBASE}/share/icons/hicolor/scalable/apps

post-patch:
	@${REINPLACE_CMD} -e 's|%%DISTVERSION%%|${DISTVERSION}|' \
		${WRKSRC}/CMakeLists.txt

# override install because otherwise, it does a complete rebuild during stage
#do-install:
#	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/linphone \
#		${STAGEDIR}${LOCALBASE}/bin
#	${MKDIR} ${STAGEDIR}${LOCALBASE}/lib/linphone
#	${MKDIR} ${STAGEDIR}${ICONDIR}
#	${INSTALL_LIB} ${BUILD_WRKSRC}/libapp-plugin.so \
#		${STAGEDIR}${LOCALBASE}/lib/linphone
#	${INSTALL_DATA} ${WRKSRC}/assets/images/linphone_logo.svg \
#		${STAGEDIR}${ICONDIR}/linphone.svg
#	${INSTALL_DATA} ${FILESDIR}/linphone.desktop \
#		${STAGEDIR}${LOCALBASE}/share/applications/linphone.desktop

.include <bsd.port.mk>
