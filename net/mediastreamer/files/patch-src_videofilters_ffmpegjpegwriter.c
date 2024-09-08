--- src/videofilters/ffmpegjpegwriter.c.orig	2024-08-26 10:10:02 UTC
+++ src/videofilters/ffmpegjpegwriter.c
@@ -211,6 +211,7 @@ static void jpg_process_frame_task(void *obj) {
 		freemsg(jpegm);
 	}
 
+end:
 	freemsg(m);
 }
 
