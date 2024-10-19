--- src/mail.c.orig	2020-03-13 12:13:31 UTC
+++ src/mail.c
@@ -355,7 +355,7 @@ static gint		style_id;
 #ifndef HAVE_GNUTLS
 static GMutex		**ssl_locks;
 
-#if defined(OPENSSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#if defined(OPENSSL_VERSION_NUMBER) && ((OPENSSL_VERSION_NUMBER < 0x10100000L) || defined(LIBRESSL_VERSION_NUMBER))
 static void
 ssl_locking_cb(int mode, int n, const char *file, int line)
 	{
