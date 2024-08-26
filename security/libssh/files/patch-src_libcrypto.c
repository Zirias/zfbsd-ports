--- src/libcrypto.c.orig	2024-08-25 17:32:43 UTC
+++ src/libcrypto.c
@@ -83,6 +83,12 @@
 #endif /* OPENSSL_VERSION_NUMBER */
 #endif /* HAVE_OPENSSL_EVP_KDF_CTX */
 
+#ifdef LIBRESSL_VERSION_NUMBER
+#  ifndef EVP_PKEY_POLY1305
+#    define EVP_PKEY_POLY1305 NID_chacha20_poly1305
+#  endif
+#endif
+
 #include "libssh/crypto.h"
 
 static int libcrypto_initialized = 0;
