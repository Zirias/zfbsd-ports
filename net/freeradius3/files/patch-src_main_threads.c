--- src/main/threads.c.orig	2022-10-18 11:09:43 UTC
+++ src/main/threads.c
@@ -860,7 +860,7 @@ static void *request_handler_thread(void *arg)
 	 */
 #if OPENSSL_VERSION_NUMBER < 0x10000000L
 	ERR_remove_state(0);
-#elif OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#elif OPENSSL_VERSION_NUMBER < 0x10100000L
 	ERR_remove_thread_state(NULL);
 #endif
 #endif
