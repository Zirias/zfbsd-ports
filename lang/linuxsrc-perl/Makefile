PORTNAME=	perl
DISTVERSION=	5.38.0
CATEGORIES=	lang devel perl5
MASTER_SITES=	CPAN/../../src/5.0
DIST_SUBDIR=	perl

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Practical Extraction and Report Language, Linux version
WWW=		https://www.perl.org/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv1+ =	${WRKSRC}/Copying

USES=	cpe linuxsrc:dist,man tar:xz

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=	-des \
		-Dcc="${CC}" \
		-Doptimize="${CFLAGS}" \
		-Dprefix=/usr \
		-Dvendorprefix=/usr \
		-Dprivlib=/usr/lib/perl5/${PERLVERSION}/core_perl \
		-Darchlib=${LINUXSRC_LIBDIR}/perl5/${PERLVERSION}/core_perl \
		-Dsitelib=/usr/lib/perl5/${PERLVERSION}/site_perl \
		-Dsitearch=/usr/lib/perl5/${PERLVERSION}/site_perl \
		-Dvendorlib=/usr/lib/perl5/${PERLVERSION}/vendor_perl \
		-Dvendorarch=${LINUXSRC_LIBDIR}/perl5/${PERLVERSION}/vendor_perl \
		-Dman1dir=/usr/share/man/man1 \
		-Dman3dir=/usr/share/man/man3 \
		-Dpager="/usr/bin/less -isR" \
		-Duseshrplib \
		-Dusethreads
CONFIGURE_ENV=	BUILD_BZIP2=0 BUILD_ZLIB=False

MAKE_ENV:=	${CONFIGURE_ENV}
INSTALL_TARGET=	install-strip

PLIST_SUB=	DISTVERSION=${DISTVERSION} PERLVERSION=${PERLVERSION}

PERLVERSION=	${DISTVERSION:R}

post-install:
		${RM} ${STAGEDIR}${PREFIX}/usr/bin/perl
		${LN} -s perl${DISTVERSION} ${STAGEDIR}${PREFIX}/usr/bin/perl
		${FIND} ${STAGEDIR}${PREFIX}${LINUXSRC_LIBDIR} -name \*.so \
			-exec ${CHMOD} 755 \{\} \; \
			-exec ${STRIP_CMD} \{\} \;

.include <bsd.port.mk>
