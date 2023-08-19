PORTNAME=	linuxsrc_base
PORTVERSION=	1
CATEGORIES=	emulators

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	Basic GNU/Linux userland for the Linuxulator

RUN_DEPENDS=	linuxsrc-bash>0:shells/linuxsrc-bash \
		linuxsrc-bzip2>0:archivers/linuxsrc-bzip2 \
		linuxsrc-coreutils>0:sysutils/linuxsrc-coreutils \
		linuxsrc-gawk>0:lang/linuxsrc-gawk \
		linuxsrc-glibc-localedata>0:misc/linuxsrc-glibc-localedata \
		linuxsrc-grep>0:textproc/linuxsrc-grep \
		linuxsrc-less>0:sysutils/linuxsrc-less \
		linuxsrc-libidn2>0:dns/linuxsrc-libidn2 \
		linuxsrc-libxcrypt>0:security/linuxsrc-libxcrypt \
		linuxsrc-man-db>0:sysutils/linuxsrc-man-db \
		linuxsrc-sed>0:textproc/linuxsrc-sed \
		linuxsrc-xz>0:archivers/linuxsrc-xz

USES=			metaport
USE_LINUX_PREFIX=	yes

.include <bsd.port.mk>
