# Created by: Felix Palmen <felix@palmen-it.de>
# $FreeBSD$

PORTNAME=	simavr
PORTVERSION=	1.3
CATEGORIES=	devel

MAINTAINER=	felix@palmen-it.de
COMMENT=	Simulator for several Atmel AVR chips

LICENSE=	GPLv3

BUILD_DEPENDS=	avr-gcc:devel/avr-gcc \
		${LOCALBASE}/avr/lib/libc.a:devel/avr-libc

USE_GITHUB=	yes
GH_ACCOUNT=	buserror
GH_TAGNAME=	v${PORTVERSION}

USES=		gmake
ALL_TARGET=	build-simavr
MAKE_ARGS=	"RELEASE=1 PREFIX=${PREFIX} DESTDIR=${STAGEDIR}${PREFIX}"

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		DOCS EXAMPLES

DOCS_ALL_TARGET=	doc
DOCS_USE=		tex=latex:build tex=pdftex:build tex=texmf:build

EXAMPLES_ALL_TARGET=	build-examples
EXAMPLES_USE=		xorg=xdamage xorg=xcb xorg=xext xorg=xfixes \
			xorg=xrandr gl=glut

OBJDIRNAME=		obj-${:!${CC} -dumpmachine!}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/simavr
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsimavr.so.1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/manual/manual.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/simavr_callgraph.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
.for BOARD ELF in \
		hd77480 charlcd \
		i2ctest i2ctest \
		ledramp ledramp \
		simduino simduino \
		ssd1306 ssd1306demo \
		timer_64led timer_64led
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/board_${BOARD}
	${INSTALL_PROGRAM} \
		${WRKSRC}/examples/board_${BOARD}/${OBJDIRNAME}/${ELF}.elf \
		${STAGEDIR}${EXAMPLESDIR}/board_${BOARD}/${ELF}
	${INSTALL_DATA} ${WRKSRC}/examples/board_${BOARD}/*.[aihc]* \
			${WRKSRC}/examples/board_${BOARD}/README \
			${WRKSRC}/examples/board_${BOARD}/Makefile \
			${STAGEDIR}${EXAMPLESDIR}/board_${BOARD}/
.endfor
.for AXF in \
		hd77480/atmega48_charlcd \
		i2ctest/atmega1280_i2ctest \
		ledramp/atmega48_ledramp \
		ssd1306/atmega32_ssd1306 \
		timer_64led/atmega168_timer_64led
	${STRIP_CMD} ${STAGEDIR}${EXAMPLESDIR}/board_${AXF}.axf
.endfor
.for EXDIR in parts shared
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${EXDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${EXDIR}/*.[hc] \
			${STAGEDIR}${EXAMPLESDIR}/${EXDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/Makefile.common ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile.opengl \
			${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
