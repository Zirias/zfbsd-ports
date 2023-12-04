--- src/lib/crypt_ops/crypto_openssl_mgt.h.orig	2023-12-07 13:00:11 UTC
+++ src/lib/crypt_ops/crypto_openssl_mgt.h
@@ -17,6 +17,7 @@
 
 #ifdef ENABLE_OPENSSL
 #include <openssl/opensslv.h>
+#include <openssl/opensslconf.h>
 /*
   Macro to create an arbitrary OpenSSL version number as used by
   OPENSSL_VERSION_NUMBER or SSLeay(), since the actual numbers are a bit hard
