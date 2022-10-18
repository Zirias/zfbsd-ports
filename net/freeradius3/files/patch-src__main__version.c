--- src/main/version.c.orig	2022-10-03 21:51:59 UTC
+++ src/main/version.c
@@ -82,8 +82,7 @@ int ssl_check_consistency(void)
 		ERROR("libssl version mismatch.  built: %lx linked: %lx",
 		      (unsigned long) ssl_built,
 		      (unsigned long) ssl_linked);
-
-		return -1;
+		return 0;
 	}
 
 	/*
