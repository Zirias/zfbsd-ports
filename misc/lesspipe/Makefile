PORTNAME=	lesspipe
DISTVERSIONPREFIX=	v
DISTVERSION=	2.06
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	slaven@rezic.de
COMMENT=	Preprocessor for less
WWW=		https://www.zeuthen.desy.de/~friebel/unix/lesspipe.html

LICENSE=	GPLv2

MY_DEPENDS=	bash:shells/bash
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		perl5 shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	wofr06

NO_BUILD=	yes
NO_ARCH=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--yes --prefix=${PREFIX}

SHEBANG_FILES=	archive_color code2color lesscomplete lesspipe.sh

PLIST_FILES=	bin/archive_color bin/code2color bin/lesscomplete bin/lesspipe.sh \
		etc/bash_completion.d/less_completion share/man/man1/lesspipe.1.gz \
		share/zsh/site-functions/_less

SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/archive_color ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/code2color ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lesscomplete ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/lesspipe.sh ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/less_completion ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/_less ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_MAN} ${WRKSRC}/lesspipe.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
