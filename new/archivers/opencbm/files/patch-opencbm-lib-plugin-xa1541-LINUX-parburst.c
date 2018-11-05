--- opencbm/lib/plugin/xa1541/LINUX/parburst.c.orig	2017-09-06 18:59:00.000000000 +0200
+++ opencbm/lib/plugin/xa1541/LINUX/parburst.c	2018-11-05 17:27:20.669693000 +0100
@@ -30,46 +30,36 @@
 
 unsigned char opencbm_plugin_parallel_burst_read(CBM_FILE f)
 {
-    return ioctl(f, CBMCTRL_PARBURST_READ);
+    unsigned char val;
+    if (ioctl(f, CBMCTRL_PARBURST_READ, &val)) return -errno;
+    return val;
 }
 
 void opencbm_plugin_parallel_burst_write(CBM_FILE f, unsigned char c)
 {
-    ioctl(f, CBMCTRL_PARBURST_WRITE, c);
+    ioctl(f, CBMCTRL_PARBURST_WRITE, &c);
 }
 
 int opencbm_plugin_parallel_burst_read_track(CBM_FILE f, unsigned char *buffer, unsigned int length)
 {
-    int retval;
-
     PARBURST_RW_VALUE mv;
     mv.buffer=buffer;
     mv.length=length; /* only needed in write_track */
-    retval=ioctl(f, CBMCTRL_PARBURST_READ_TRACK, &mv);  /* we have to catch retval to check on EFAULT */
-    if(retval==(-EFAULT)) {printf("cbm4linux: cbm.c: cbm_parallel_burst_read_track: ioctl returned -EFAULT"); return 0;}
-    return retval;
+    return ioctl(f, CBMCTRL_PARBURST_READ_TRACK, &mv) ? -errno : 0;
 }
 
 int opencbm_plugin_parallel_burst_read_track_var(CBM_FILE f, unsigned char *buffer, unsigned int length)
 {
-    int retval;
-
     PARBURST_RW_VALUE mv;
     mv.buffer=buffer;
     mv.length=length; /* only needed in write_track */
-    retval=ioctl(f, CBMCTRL_PARBURST_READ_TRACK_VAR, &mv);  /* we have to catch retval to check on EFAULT */
-    if(retval==(-EFAULT)) {printf("cbm4linux: cbm.c: cbm_parallel_burst_read_track_var: ioctl returned -EFAULT"); return 0;}
-    return retval;
+    return ioctl(f, CBMCTRL_PARBURST_READ_TRACK_VAR, &mv) ? -errno : 0;
 }
 
 int opencbm_plugin_parallel_burst_write_track(CBM_FILE f,  unsigned char *buffer, unsigned int length)
 {
-    int retval;
-
     PARBURST_RW_VALUE mv;
     mv.buffer=buffer;
     mv.length=length;
-    retval=ioctl(f, CBMCTRL_PARBURST_WRITE_TRACK, &mv);
-    if(retval==(-EFAULT)) {printf("cbm4linux: cbm.c: cbm_parallel_burst_write_track: ioctl returned -EFAULT"); return 0;}
-    return retval;
+    return ioctl(f, CBMCTRL_PARBURST_WRITE_TRACK, &mv) ? -errno : 0;
 }
