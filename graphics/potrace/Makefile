PORTNAME=	potrace
DISTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/potrace/${PORTVERSION}

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Transforms bitmaps into vector graphics
WWW=		https://potrace.sourceforge.net

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CPE_VENDOR=	potrace_project

OPTIONS_DEFINE=	METRIC A4 DOCS
OPTIONS_DEFAULT=METRIC A4

METRIC_DESC=	Use metric units (cm) as default
METRIC_CONFIGURE_ENABLE=	metric
A4_DESC=	Use A4 as the default papersize
A4_CONFIGURE_ENABLE=	a4

.include <bsd.port.mk>
