PORTNAME=	latd
PORTVERSION=	1.31
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/linux-decnet/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux-DECnet project LAT protocol suite
WWW=		https://linux-decnet.sourceforge.net/

LICENSE=	GPLv2

USES=		alias compiler
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

PLIST_FILES=	bin/llogin etc/latd.conf.sample \
		share/man/man1/llogin.1.gz share/man/man5/latd.conf.5.gz \
		share/man/man8/latd.8.gz share/man/man8/latcp.8.gz share/man/man8/moprc.8.gz \
		sbin/latcp sbin/latd sbin/moprc

post-extract:
	@${CHMOD} ${BINMODE} ${WRKSRC}/install-sh

post-patch:
	@${FIND} ${WRKSRC} -name "*.cc" | ${XARGS} ${REINPLACE_CMD} -e \
		'/<utmp.h>/s|^|// | ; \
		 s| \(setiosflags\)| std::\1| ; \
		 s| \(resetiosflags\)| std::\1|'

.include <bsd.port.mk>
