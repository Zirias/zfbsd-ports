PORTNAME=	convmv
PORTVERSION=	2.05
PORTREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	http://www.j3e.de/linux/convmv/ \
		http://www.sfr-fresh.com/unix/privat/

MAINTAINER=	kcwu@csie.org
COMMENT=	Convert filenames from one encoding to another
WWW=		https://j3e.de/linux/convmv/man/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_GPLv2=	${WRKSRC}/GPL2

USES=		perl5 shebangfix
SHEBANG_FILES=	convmv
NO_ARCH=	yes
PLIST_FILES=	bin/convmv share/man/man1/convmv.1.gz

.include <bsd.port.mk>
