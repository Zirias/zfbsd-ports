--- main/iostream.c.orig	2022-01-15 15:34:35 UTC
+++ main/iostream.c
@@ -553,7 +553,7 @@ int ast_iostream_close(struct ast_iostream *stream)
 					ERR_error_string(sslerr, err), ssl_error_to_string(sslerr, res));
 			}
 
-#if !defined(LIBRESSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x10100000L)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 			if (!SSL_is_server(stream->ssl)) {
 #else
 			if (!stream->ssl->server) {
