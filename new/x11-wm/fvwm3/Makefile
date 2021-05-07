# Created by: Felix Palmen <felix@palmen-it.de>

PORTNAME=	fvwm3
PORTVERSION=	1.0.2
CATEGORIES=	x11-wm
MASTER_SITES=	https://github.com/fvwmorg/fvwm3/releases/download/${PORTVERSION}/

MAINTAINER=	felix@palmen-it.de
COMMENT=	F? Virtual Window Manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libbson-1.0.so:devel/libbson \
		libevent.so:devel/libevent

USES=	iconv:translit pkgconfig python:3.7+ readline xorg
USE_XORG=	ice x11 xext xrandr xrender xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_path_PYTHON=${PYTHON_CMD} \
		--disable-golang

OPTIONS_DEFINE=	FRIBIDI MANPAGES NLS PERL PNG SVG XCURSOR XFT XPM XSM
OPTIONS_DEFAULT=	FRIBIDI MANPAGES PERL PNG XCURSOR XFT XSM

FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=	bidi

MANPAGES_BUILD_DEPENDS=	rubygem-asciidoctor>0:textproc/rubygem-asciidoctor
MANPAGES_USES=	gmake
MANPAGES_CONFIGURE_ENABLE=	mandoc

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext-runtime

PERL_USES=	perl5
PERL_CONFIGURE_ENABLE=	perllib

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ENABLE=	png

SVG_LIB_DEPENDS=	librsvg-2.so:graphics/librsvg2-rust
SVG_USES=	gnome
SVG_USE=	gnome=cairo,glib20,gdkpixbuf2
SVG_CONFIGURE_ENABLE=	rsvg

XCURSOR_USE=	xorg=xcursor
XCURSOR_CONFIGURE_ENABLE=	xcursor

XFT_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libfontconfig.so:x11-fonts/fontconfig
XFT_USE=	xorg=xft
XFT_CONFIGURE_ENABLE=	xft

XPM_USE=	xorg=xpm
XPM_CONFIGURE_OFF=	--with-xpm-library=no

XSM_DESC=	X11 session management support
XSM_USE=	xorg=sm
XSM_CONFIGURE_ENABLE=	sm

.include <bsd.port.mk>
