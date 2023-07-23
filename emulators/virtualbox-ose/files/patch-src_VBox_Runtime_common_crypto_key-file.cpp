--- src/VBox/Runtime/common/crypto/key-file.cpp.orig	2024-08-14 08:14:26 UTC
+++ src/VBox/Runtime/common/crypto/key-file.cpp
@@ -184,7 +184,7 @@ static int rtCrKeyDecryptPkcs8Info(PRTCRPKCS8ENCRYPTED
     if (!pszPassword)
         return VERR_CR_KEY_ENCRYPTED;
 
-#ifdef IPRT_WITH_OPENSSL /** @todo abstract encryption & decryption. */
+#if defined(IPRT_WITH_OPENSSL) && !defined(LIBRESSL_VERSION_NUMBER) /** @todo abstract encryption & decryption. */
 
     /*
      * Query the EncryptionAlgorithm bytes so we can construction a X509_ALGOR
