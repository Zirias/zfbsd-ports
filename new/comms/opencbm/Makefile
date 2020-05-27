# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	opencbm${OCBM_NAMESUFFIX}
PORTVERSION=	0.4.99.99a
CATEGORIES=	comms archivers
DIST_SUBDIR=	opencbm

PATCH_DIST_STRIP=	-p1
PATCH_SITES=	https://github.com/OpenCBM/OpenCBM/commit/
PATCHFILES=	${OCBM_PATCHES}

MAINTAINER=	felix@palmen-it.de
COMMENT=	${OCBM_COMMENT}

LICENSE=	${OCBM_LICENSE}
LICENSE_COMB=	${OCBM_LI_COMB}

BUILD_DEPENDS=	${OCBM_BUILDDEPS}
RUN_DEPENDS=	${OCBM_RUNDEPS}

USES=		${OCBM_USES}

USE_GITHUB=	yes
GH_ACCOUNT=	OpenCBM
GH_PROJECT=	OpenCBM
GH_TAGNAME=	v${PORTVERSION}

PATCH_WRKSRC=	${WRKDIR}/OpenCBM-${PORTVERSION}

OCBM_LICENSE=	GPLv2
OCBM_LI_COMB=	single

.if ${PORTNAME} == opencbm-kmod

OCBM_COMMENT=	OpenCBM driver module for parallel-port X[MA]-1541 cables

OCBM_PATCHES=	ca4c06e7430caf3b2296d4e1e00051fff015fc53.diff \
		073b833772e4325c7f680d6aeb81bc11844f03ca.diff \
		3e967551e200d0c03aa4898e482626a7510acd21.diff

OCBM_LICENSE=	GPLv2+

OCBM_USES=	kmod uidfix

WRKSRC_SUBDIR=	opencbm/sys/freebsd
PLIST_SUB+=	OPENCBM="@comment " XA1541="@comment " KMOD=""

post-install:
		${INSTALL_MAN} ${FILESDIR}/opencbm.4 \
			${STAGEDIR}${PREFIX}/man/man4

.else

OCBM_PATCHES=	12ef17d4cf78903c9c52d7a348a816424d549b89.diff

OCBM_BUILDDEPS=	cc65:devel/cc65

OCBM_USES=	gmake

MAKE_ARGS=	CC=cc INFODIR=${PREFIX}/share/info \
		SUBDIRS_PLUGIN_XA1541=opencbm/lib/plugin/xa1541
MAKEFILE=	LINUX/Makefile
MAKE_JOBS_UNSAFE=	yes

OCBM_LIBVERSION=	0.4.99.99
PLUGINBASENAME=		${PREFIX}/lib/opencbm/plugin/libopencbm-

.if ${PORTNAME} == opencbm

OCBM_COMMENT=	Commodore CBM serial IEC/IEEE-488 bus utilities

OCBM_LICENSE+=	BSD3CLAUSE
OCBM_LI_COMB=	multi

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS INFO
OPTIONS_DEFAULT=	DOCS INFO

ALL_TARGET=	opencbm plugin-xu1541 plugin-xum1541
INSTALL_TARGET=	install install-plugin-xu1541 install-plugin-xum1541
PLIST_SUB+=	OPENCBM="" XA1541="@comment " KMOD="@comment "

DOCS_BUILD_DEPENDS=	dvips:print/tex-dvipsk \
			latex:print/tex-formats \
			linuxdoc:textproc/linuxdoc-tools
DOCS_USES=		ghostscript:build
DOCS_ALL_TARGET=	doc
DOCS_MAKE_ARGS_OFF=	TXT= DVI= PDF= HTML=

INFO_BUILD_DEPENDS=	linuxdoc:textproc/linuxdoc-tools
INFO_USES=		makeinfo
INFO_ALL_TARGET=	doc
INFO_INFO=		opencbm
INFO_MAKE_ARGS_OFF=	INFO=

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/opencbm/docs && \
		${COPYTREE_SHARE} "html misc opencbm.pdf opencbm.txt" \
		${STAGEDIR}${DOCSDIR})

do-install-INFO-on:
	${INSTALL_MAN} ${WRKSRC}/opencbm/docs/opencbm.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopencbm.so.${OCBM_LIBVERSION}
.for p in xu1541 xum1541
	${STRIP_CMD} ${STAGEDIR}${PLUGINBASENAME}${p}.so.${OCBM_LIBVERSION}
.endfor
	@${RM} ${STAGEDIR}${PREFIX}/etc/opencbm.conf
	@${MV} ${STAGEDIR}${PREFIX}/etc/opencbm.conf.d/00opencbm.conf \
		${STAGEDIR}${PREFIX}/etc/opencbm.conf.d/00opencbm.conf.sample
	@${MV} ${STAGEDIR}${PREFIX}/bin/opencbm_plugin_helper_tools \
		${STAGEDIR}${PREFIX}/sbin/opencbm_plugin_helper_tools

.else

OCBM_COMMENT=	OpenCBM plugin for parallel-port cables

OCBM_PATCHES+=	ca4c06e7430caf3b2296d4e1e00051fff015fc53.diff

OCBM_RUNDEPS=	opencbm=${PORTVERSION}:comms/opencbm \
		opencbm-kmod=${PORTVERSION}:comms/opencbm-kmod

ALL_TARGET=	plugin-xa1541
INSTALL_TARGET=	install-plugin-xa1541
PLIST_SUB+=	OPENCBM="@comment " XA1541="" KMOD="@comment "

post-install:
	${STRIP_CMD} ${STAGEDIR}${PLUGINBASENAME}xa1541.so.${OCBM_LIBVERSION}
	@${RM} ${STAGEDIR}${PREFIX}/etc/opencbm.conf

.endif
.endif

.include <bsd.port.mk>
