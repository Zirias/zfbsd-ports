PORTNAME=	sed
DISTVERSION=	4.9
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	GNU stream editor
WWW=		https://www.gnu.org/software/sed/sed.html

LICENSE=	GPLv3+ GFDL
LICENSE_COMB=	multi

LINLIB_DEPENDS=	linuxsrc-acl>0:sysutils/linuxsrc-acl

USES=		cpe makeinfo linuxsrc:base,man tar:xz
CPE_VENDOR=	gnu

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
