PORTNAME=	vmaf
DISTVERSION=	r7
PORTREVISION=	3
CATEGORIES=	multimedia
PKGNAMEPREFIX=	vapoursynth-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video Multi-Method Assessment Fusion plugin for VapourSynth
WWW=		https://github.com/HomeOfVapourSynthEvolution/VapourSynth-VMAF

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/vapoursynth/VSHelper.h:multimedia/vapoursynth
LIB_DEPENDS=	libvmaf.so:multimedia/vmaf

USES=		compiler:c++17-lang meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	HomeOfVapourSynthEvolution
GH_PROJECT=	VapourSynth-${PORTNAME:tu}
DATADIR=	${PREFIX}/lib/vapoursynth
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}
PORTDATA=	lib${PORTNAME}.so
PORTDOCS=	*.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
