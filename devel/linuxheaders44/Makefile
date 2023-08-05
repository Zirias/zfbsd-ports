PORTNAME=	linux
DISTVERSION=	4.4.302
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/linux/kernel/v4.x
PKGNAMESUFFIX=	headers44

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Linux kernel headers
WWW=		https://kernel.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS?=	linuxsrc_base-dirs>0:emulators/linuxsrc_base-dirs

USES=		gmake linuxsrc:env,archs tar:xz

MAKE_ARGS=	V=1 HOSTCC="${CC} ${LINUXHOSTDEFS}" ARCH=${LINUXHDRARCH} \
		INSTALL_HDR_PATH=${STAGEDIR}${PREFIX}/usr
ALL_TARGET=	__headers
INSTALL_TARGET=	headers_install

LINUXHDRARCH=	${ARCH:S/amd64/x86_64/:S/aarch64/arm64/}
PREFIX?=	${LINUXBASE}

# Work around a constant not found on arm64 and i386
LINUXHOSTDEFS=	-DR_X86_64_JUMP_SLOT=7

post-install:
		${FIND} ${STAGEDIR} -name *.install* -exec ${RM} \{\} +
		${RMDIR} ${STAGEDIR}${PREFIX}/usr/include/uapi

.include <bsd.port.mk>
