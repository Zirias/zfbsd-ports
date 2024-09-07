PORTNAME=	bcunit
PORTVERSION=	5.3.79
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fork of defunct project CUnit, with several fixes and patches applied
WWW=		https://gitlab.linphone.org/BC/public/bcunit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake libtool pathfix pkgconfig
USE_GITLAB=	yes
GL_SITE=	https://gitlab.linphone.org/BC
GL_ACCOUNT=	public

CFLAGS+=	-fPIC

.include <bsd.port.mk>
