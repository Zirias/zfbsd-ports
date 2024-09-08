--- src/belle_sip_internal.h.orig	2024-07-24 09:01:32 UTC
+++ src/belle_sip_internal.h
@@ -21,6 +21,7 @@
 #define belle_utils_h
 
 #include <errno.h>
+#include <netinet/in.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
