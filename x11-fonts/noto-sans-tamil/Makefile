PORTNAME=	noto
PORTVERSION=	2.004
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/notofonts/tamil/releases/download/NotoSansTamil-v${PORTVERSION}/
PKGNAMESUFFIX=	-sans-tamil
DISTNAME=	NotoSansTamil-v${PORTVERSION}
DIST_SUBDIR=	Noto

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Noto Sans Tamil
WWW=		https://fonts.google.com/noto \
		https://notofonts.github.io/ \
		https://github.com/notofonts/tamil

LICENSE=	OFL11
#LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/NotoSansTamil/hinted/ttf/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
