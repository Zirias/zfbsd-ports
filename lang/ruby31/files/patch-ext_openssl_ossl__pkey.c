--- ext/openssl/ossl_pkey.c.orig	2023-03-22 07:56:55 UTC
+++ ext/openssl/ossl_pkey.c
@@ -710,7 +710,7 @@ ossl_pkey_export_traditional(int argc, VALUE *argv, VA
 	}
     }
     else {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
 	if (!PEM_write_bio_PrivateKey_traditional(bio, pkey, enc, NULL, 0,
 						  ossl_pem_passwd_cb,
 						  (void *)pass)) {
