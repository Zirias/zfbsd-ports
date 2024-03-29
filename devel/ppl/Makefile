PORTNAME=	ppl
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.unipr.it/pub/ppl/releases/${PORTVERSION}/ \
		http://bugseng.com/products/ppl/download/ftp/releases/${PORTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for the manipulation of convex polyhedra
WWW=		https://bugseng.com/products/ppl

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gm4:devel/m4
LIB_DEPENDS=	libglpk.so:math/glpk \
		libgmp.so:math/gmp

USES=		gmake perl5 tar:xz libtool localbase:ldflags
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-debugging \
		--enable-optimization \
		--enable-documentation \
		--with-cflags="${CFLAGS}" \
		--with-cxxflags="${CXXFLAGS}" \
		--with-gmp-include="${LOCALBASE}/include" \
		--with-gmp-lib="${LOCALBASE}/lib" \
		--enable-interfaces="${INTERFACES}"
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

# Only enable C and C++ interfaces. Checks for java, prolog and ocaml
# have to be added.
INTERFACES=	c,cxx

post-patch:
	@${REINPLACE_CMD} -e \
		'/OPT_FLAGS/s|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/for file in/s|COPYING||' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
