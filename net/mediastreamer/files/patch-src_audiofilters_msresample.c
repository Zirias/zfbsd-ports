--- src/audiofilters/msresample.c.orig	2024-09-08 05:55:03 UTC
+++ src/audiofilters/msresample.c
@@ -24,7 +24,6 @@
 #include <malloc.h>
 #endif
 
-#include <speex/speex.h>
 #include <speex/speex_resampler.h>
 
 #ifdef __ANDROID__
