PORTNAME=	scalpel
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.digitalforensicssolutions.com/Scalpel/ \
		https://fossies.org/linux/misc/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	Frugal, high performance file carver
WWW=		http://www.digitalforensicssolutions.com/Scalpel/

LICENSE=	GPLv2

LIB_DEPENDS=	libtre.so:textproc/libtre

USES=		alias localbase
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
SUB_FILES=	pkg-message

PLIST_FILES=	etc/scalpel.conf.sample bin/scalpel share/man/man1/scalpel.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's/#ifdef __APPLE__/#if defined(__APPLE__) || defined(__FreeBSD__)/' \
		${WRKSRC}/src/scalpel.h
	@${REINPLACE_CMD} -e 's,__progname,__${PORTNAME}&,' \
		${WRKSRC}/src/scalpel.? ${WRKSRC}/src/helpers.c

post-install:
	@${CP} -p ${WRKSRC}/scalpel.conf ${STAGEDIR}${PREFIX}/etc/scalpel.conf.sample

.include <bsd.port.mk>
