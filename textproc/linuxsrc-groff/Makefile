PORTNAME=	groff
DISTVERSION=	1.23.0
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Software typesetting package, Linux version
WWW=		https://www.gnu.org/software/groff/

LICENSE=	GPLv3

LINLIB_DEPENDS=	linuxsrc-gcc-libstdc++>0:devel/linuxsrc-gcc-libstdc++

USES=		cpe linuxsrc:base,man makeinfo
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-install:
		@${RM} -r ${STAGEDIR}${PREFIX}/usr/lib*
		${SED} -i '' 's|${STAGEDIR}${PREFIX}||g' \
			${STAGEDIR}${PREFIX}/usr/bin/chem \
			${STAGEDIR}${PREFIX}/usr/bin/glilypond \
			${STAGEDIR}${PREFIX}/usr/bin/gperl

.include <bsd.port.mk>
