PORTNAME=	wmspaceweather
PORTVERSION=	1.04
PORTREVISION=	6
CATEGORIES=	astro windowmaker
MASTER_SITES=	https://api.opensuse.org/public/source/openSUSE:Factory/WindowMaker-applets/ \
		ftp://ftp.canadatux.org/linux/windowmaker/
DISTNAME=	wmSpaceWeather-${PORTVERSION}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	DockApp that shows the weather at geosynchronous orbit

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Time-modules>=0:devel/p5-Time-modules

USES=		shebangfix xorg

WRKSRC=		${WRKDIR}/${DISTNAME}/wmSpaceWeather

SHEBANG_FILES=	GetKp
USE_XORG=	x11 xext xpm
ALL_TARGET=	clean all
MAKE_ENV=	OPSYS=${OPSYS}
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/GetKp bin/wmSpaceWeather \
		share/man/man1/wmSpaceWeather.1.gz

.include <bsd.port.mk>
