PORTNAME=	libcap
DISTVERSION=	2.69
CATEGORIES=	sysutils security
MASTER_SITES=	KERNEL_ORG/linux/libs/security/linux-privs/libcap2

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Utilities and libraries for capabilities on Linux
WWW=		https://sites.google.com/site/fullycapable/

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/License

BUILD_DEPENDS=	linuxsrc-sed>0:textproc/linuxsrc-sed

USES=		linuxsrc:base,man tar:xz
USE_LDCONFIG=	yes

MAKE_ARGS=	LIBDIR=${LINUXSRC_LIBDIR} \
		PAM_CAP=no \
		prefix=/usr

post-install:
		@${RM} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.a
		${STRIP_CMD} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR}/*.so.*.*
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/usr/sbin/*

.include <bsd.port.mk>
