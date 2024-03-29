PORTNAME=	spin
PORTVERSION=	6.5.2
DISTVERSIONPREFIX=	version-
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	On-the-fly verification system for asynchronous concurrent systems
WWW=		http://spinroot.com

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Src/LICENSE

USES=		cpe

CPE_VENDOR=	spinroot

MAKEFILE=	makefile
ALL_TARGET=	all
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DNXT"

PORTDOCS=	*
PORTEXAMPLES=	*

USE_GITHUB=	yes
GH_ACCOUNT=	nimble-code
GH_PROJECT=	Spin

OPTIONS_DEFINE=	DOCS EXAMPLES ISPIN
OPTIONS_DEFAULT=	ISPIN
OPTIONS_SUB=	yes
ISPIN_DESC=	Install ispin and TCL/Tk dependency
ISPIN_USES=	shebangfix tk

SHEBANG_FILES=	optional_gui/ispin.tcl
tk_OLD_CMD=	/bin/sh
tk_CMD=		${WISH} -f

post-patch-ISPIN-on:
	${REINPLACE_CMD} -e "s|exec wish|#exec wish|" ${WRKSRC}/optional_gui/ispin.tcl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Src/spin ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/Man/spin.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/Doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-install-ISPIN-on:
	${INSTALL_SCRIPT} ${WRKSRC}/optional_gui/ispin.tcl ${STAGEDIR}${PREFIX}/bin/ispin

.include <bsd.port.mk>
