PORTNAME=	linuxsrc_base-dirs
PORTVERSION=	1
CATEGORIES=	emulators

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Basic directories for a Linux userland

USES=			metaport
USE_LINUX_PREFIX=	yes

PLIST_SUB=	LINUXBASE=${LINUXBASE} SYSCTLMIB=${SYSCTLMIB}

.include <bsd.port.options.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64
PLIST_SUB+=	LIB64=""
SYSCTLMIB=	kern.features.linux64
.else
PLIST_SUB+=	LIB64="@comment "
SYSCTLMIB=	compat.linux.osrelease
.endif

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc
		${MKDIR} ${STAGEDIR}${PREFIX}/usr/lib
		${LN} -s usr/bin ${STAGEDIR}${PREFIX}/bin
		${LN} -s usr/sbin ${STAGEDIR}${PREFIX}/sbin
		${LN} -s usr/lib ${STAGEDIR}${PREFIX}/lib
.if ${ARCH} == aarch64 || ${ARCH} == amd64
		${MKDIR} ${STAGEDIR}${PREFIX}/usr/lib64
		${LN} -s usr/lib64 ${STAGEDIR}${PREFIX}/lib64
.endif
		${MKDIR} ${STAGEDIR}${PREFIX}/var/cache

.include <bsd.port.mk>
