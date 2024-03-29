PORTNAME=	stone
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.gcd.org/sengoku/stone/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP/IP packet repeater in the application layer
WWW=		https://www.gcd.org/sengoku/stone/

LICENSE=	GPLv2

.if !defined(WITHOUT_SSL)
USES=		ssl
.endif
USE_RC_SUBR=	stone

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SSL)
ALL_TARGET=	bsd-pop
MAKE_ARGS=	POP_LIBS="-lmd" LIBS="-DUNIX_DAEMON"
post-extract:
	${TOUCH} ${WRKSRC}/global.h
.else
ALL_TARGET=	bsd-ssl
MAKE_ARGS=	SSL_FLAGS="-DUSE_SSL -I${OPENSSLINC}" \
		SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto" LIBS="-DUNIX_DAEMON"
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stone ${STAGEDIR}${PREFIX}/bin/stone
	${INSTALL_MAN} ${FILESDIR}/stone.1 ${STAGEDIR}${PREFIX}/share/man/man1/stone.1
	${INSTALL_MAN} ${FILESDIR}/stone.1.ja ${STAGEDIR}${PREFIX}/share/man/ja/man1/stone.1
	${INSTALL_DATA} ${FILESDIR}/stone.cnf ${STAGEDIR}${PREFIX}/etc/stone.cnf.sample

.include <bsd.port.post.mk>
