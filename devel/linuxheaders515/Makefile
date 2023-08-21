PORTNAME=	linux
DISTVERSION=	5.15.127
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/linux/kernel/v5.x
PKGNAMESUFFIX=	headers515

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Linux kernel headers
WWW=		https://kernel.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed \
		rsync:net/rsync
RUN_DEPENDS?=	linuxsrc_base-dirs>0:emulators/linuxsrc_base-dirs

USES=		gmake linuxsrc:env,archs tar:xz

MAKE_ARGS=	V=1 HOSTCC="${CC} ${LINUXHOSTDEFS}" ARCH=${LINUXHDRARCH} \
		INSTALL_HDR_PATH=${STAGEDIR}${PREFIX}/usr
ALL_TARGET=	headers
INSTALL_TARGET=	headers_install

BINARY_ALIAS=	sed=${LOCALBASE}/bin/gsed

LINUXHDRARCH=	${ARCH:S/amd64/x86_64/:S/aarch64/arm64/}
PREFIX?=	${LINUXBASE}

# Work around a constant not found on arm64 and i386
LINUXHOSTDEFS=	-DR_X86_64_JUMP_SLOT=7

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1302507
IGNORE=	Linux 5.15 kernel ABI is not supported on FreeBSD 13.2 and older
.endif

.include <bsd.port.mk>
