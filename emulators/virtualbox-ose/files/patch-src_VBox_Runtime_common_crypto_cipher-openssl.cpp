--- src/VBox/Runtime/common/crypto/cipher-openssl.cpp.orig	2023-07-23 05:29:21 UTC
+++ src/VBox/Runtime/common/crypto/cipher-openssl.cpp
@@ -211,7 +211,7 @@ RTDECL(int) RTCrCipherEncrypt(RTCRCIPHER hCipher, void
      * Allocate and initialize the cipher context.
      */
     int rc = VERR_NO_MEMORY;
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
     EVP_CIPHER_CTX *pCipherCtx = EVP_CIPHER_CTX_new();
     if (pCipherCtx)
 # else
@@ -251,7 +251,7 @@ RTDECL(int) RTCrCipherEncrypt(RTCRCIPHER hCipher, void
         else
             rc = VERR_CR_CIPHER_OSSL_ENCRYPT_INIT_FAILED;
 
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
         EVP_CIPHER_CTX_free(pCipherCtx);
 # else
         EVP_CIPHER_CTX_cleanup(&CipherCtx);
@@ -295,7 +295,7 @@ RTDECL(int) RTCrCipherDecrypt(RTCRCIPHER hCipher, void
      * Allocate and initialize the cipher context.
      */
     int rc = VERR_NO_MEMORY;
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
     EVP_CIPHER_CTX *pCipherCtx = EVP_CIPHER_CTX_new();
     if (pCipherCtx)
 # else
@@ -335,7 +335,7 @@ RTDECL(int) RTCrCipherDecrypt(RTCRCIPHER hCipher, void
         else
             rc = VERR_CR_CIPHER_OSSL_DECRYPT_INIT_FAILED;
 
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
         EVP_CIPHER_CTX_free(pCipherCtx);
 # else
         EVP_CIPHER_CTX_cleanup(&CipherCtx);
