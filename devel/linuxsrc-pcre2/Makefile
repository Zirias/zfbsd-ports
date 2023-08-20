PORTNAME=	pcre2
DISTVERSION=	10.42
CATEGORIES=	devel
MASTER_SITES=	https://github.com/PCRE2Project/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Perl Compatible Regular Expressions, version 2, for Linux
WWW=		https://www.pcre.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

LINLIB_DEPENDS=	linuxsrc-bzip2>0:archivers/linuxsrc-bzip2 \
		linuxsrc-zlib>0:archivers/linuxsrc-zlib \
		linuxsrc-readline>0:devel/linuxsrc-readline

USES=		cpe libtool linuxsrc:base,man pkgconfig tar:bz2
CPE_VENDOR=	pcre
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static \
		--enable-jit \
		--enable-pcre2-16 \
		--enable-pcre2-32 \
		--enable-pcre2grep-libbz2 \
		--enable-pcre2grep-libz \
		--enable-pcre2test-libreadline \
		--enable-unicode

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
