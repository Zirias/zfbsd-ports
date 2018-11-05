--- opencbm/lib/plugin/xa1541/LINUX/iec.c.orig	2017-09-06 18:59:00.000000000 +0200
+++ opencbm/lib/plugin/xa1541/LINUX/iec.c	2018-11-05 17:26:00.779743000 +0100
@@ -12,6 +12,7 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <unistd.h>
+#include <errno.h>
 
 #include "opencbm.h"
 #include "cbm_module.h"
@@ -99,88 +100,100 @@
 
 int opencbm_plugin_listen(CBM_FILE f, unsigned char dev, unsigned char secadr)
 {
-    return ioctl(f, CBMCTRL_LISTEN, (dev<<8) | secadr);
+    int arg = (dev<<8) | secadr;
+    return ioctl(f, CBMCTRL_LISTEN, &arg) ? -errno : 0;
 }
 
 int opencbm_plugin_talk(CBM_FILE f, unsigned char dev, unsigned char secadr)
 {
-    return ioctl(f, CBMCTRL_TALK, (dev<<8) | secadr);
+    int arg = (dev<<8) | secadr;
+    return ioctl(f, CBMCTRL_TALK, &arg) ? -errno : 0;
 }
 
 int opencbm_plugin_open(CBM_FILE f, unsigned char dev, unsigned char secadr)
 {
-    int rv;
-
-    rv = ioctl(f, CBMCTRL_OPEN, (dev<<8) | secadr);
-    return rv;
+    int arg = (dev<<8) | secadr;
+    return ioctl(f, CBMCTRL_OPEN, &arg) ? -errno : 0;
 }
 
 int opencbm_plugin_close(CBM_FILE f, unsigned char dev, unsigned char secadr)
 {
-    return ioctl(f, CBMCTRL_CLOSE, (dev<<8) | secadr);
+    int arg = (dev<<8) | secadr;
+    return ioctl(f, CBMCTRL_CLOSE, &arg) ? -errno : 0;
 }
 
 int opencbm_plugin_unlisten(CBM_FILE f)
 {
-    return ioctl(f, CBMCTRL_UNLISTEN);
+    return ioctl(f, CBMCTRL_UNLISTEN) ? -errno : 0;
 }
 
 int opencbm_plugin_untalk(CBM_FILE f)
 {
-    return ioctl(f, CBMCTRL_UNTALK);
+    return ioctl(f, CBMCTRL_UNTALK) ? -errno : 0;
 }
 
 int opencbm_plugin_get_eoi(CBM_FILE f)
 {
-    return ioctl(f, CBMCTRL_GET_EOI);
+    int eoi;
+    if (ioctl(f, CBMCTRL_GET_EOI, &eoi)) return -errno;
+    return eoi;
 }
 
 int opencbm_plugin_clear_eoi(CBM_FILE f)
 {
-    return ioctl(f, CBMCTRL_CLEAR_EOI);
+    return ioctl(f, CBMCTRL_CLEAR_EOI) ? -errno : 0;
 }
 
 int opencbm_plugin_reset(CBM_FILE f)
 {
-    return ioctl(f, CBMCTRL_RESET);
+    return ioctl(f, CBMCTRL_RESET) ? -errno : 0;
 }
 
 unsigned char opencbm_plugin_pp_read(CBM_FILE f)
 {
-    return ioctl(f, CBMCTRL_PP_READ);
+    unsigned char val;
+    if (ioctl(f, CBMCTRL_PP_READ, &val)) return -errno;
+    return val;
 }
 
 void opencbm_plugin_pp_write(CBM_FILE f, unsigned char c)
 {
-    ioctl(f, CBMCTRL_PP_WRITE, c);
+    ioctl(f, CBMCTRL_PP_WRITE, &c);
 }
 
 int opencbm_plugin_iec_poll(CBM_FILE f)
 {
-    return ioctl(f, CBMCTRL_IEC_POLL);
+    int val;
+    if (ioctl(f, CBMCTRL_IEC_POLL, &val)) return -errno;
+    return val;
 }
 
 int opencbm_plugin_iec_get(CBM_FILE f, int line)
 {
-    return (ioctl(f, CBMCTRL_IEC_POLL) & line) != 0;
+    int val;
+    if (ioctl(f, CBMCTRL_IEC_POLL, &val)) return -errno;
+    return (val & line) != 0;
 }
 
 void opencbm_plugin_iec_set(CBM_FILE f, int line)
 {
-    ioctl(f, CBMCTRL_IEC_SET, line);
+    ioctl(f, CBMCTRL_IEC_SET, &line);
 }
 
 void opencbm_plugin_iec_release(CBM_FILE f, int line)
 {
-    ioctl(f, CBMCTRL_IEC_RELEASE, line);
+    ioctl(f, CBMCTRL_IEC_RELEASE, &line);
 }
 
 int opencbm_plugin_iec_wait(CBM_FILE f, int line, int state)
 {
-    return ioctl(f, CBMCTRL_IEC_WAIT, (line<<8) | state);
+    int arg = (line<<8) | state;
+    if (ioctl(f, CBMCTRL_IEC_WAIT, &arg)) return -errno;
+    return arg;
 }
 
 void opencbm_plugin_iec_setrelease(CBM_FILE f, int set, int release)
 {
-    ioctl(f, CBMCTRL_IEC_SETRELEASE, (set<<8) | release);
+    int arg = (set<<8) | release;
+    ioctl(f, CBMCTRL_IEC_SETRELEASE, &arg);
 }
