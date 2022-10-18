--- src/modules/rlm_eap/libeap/mppe_keys.c.orig	2024-08-15 10:20:50 UTC
+++ src/modules/rlm_eap/libeap/mppe_keys.c
@@ -34,7 +34,7 @@ USES_APPLE_DEPRECATED_API	/* OpenSSL API has been depr
 #include <openssl/provider.h>
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L && !defined(LIBRESSL_VERSION_NUMBER)
 #include <openssl/kdf.h>
 
 void TLS_PRF(SSL *ssl,
