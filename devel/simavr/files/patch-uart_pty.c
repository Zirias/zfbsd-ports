--- examples/parts/uart_pty.c.orig	2016-04-02 01:43:30.716107000 +0200
+++ examples/parts/uart_pty.c	2016-04-02 01:44:36.824775000 +0200
@@ -30,8 +30,15 @@
 #ifdef __APPLE__
 #include <util.h>
 #else
+#ifdef FREEBSD
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
+#else
 #include <pty.h>
 #endif
+#endif
 
 #include "uart_pty.h"
 #include "avr_uart.h"
