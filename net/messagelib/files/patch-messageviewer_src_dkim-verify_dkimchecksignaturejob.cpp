--- messageviewer/src/dkim-verify/dkimchecksignaturejob.cpp.orig	2025-03-10 08:21:41 UTC
+++ messageviewer/src/dkim-verify/dkimchecksignaturejob.cpp
@@ -19,8 +19,10 @@
 #include <QRegularExpression>
 
 #include <openssl/bn.h>
+#ifndef LIBRESSL_VERSION_NUMBER
 #include <openssl/core_names.h>
 #include <openssl/decoder.h>
+#endif
 #include <openssl/err.h>
 #include <openssl/evp.h>
 #include <openssl/rsa.h>
@@ -509,6 +511,10 @@ EVPPKeyPtr loadRSAPublicKey(const QByteArray &der)
 
 EVPPKeyPtr loadRSAPublicKey(const QByteArray &der)
 {
+#ifdef LIBRESSL_VERSION_NUMBER
+    qCWarning(MESSAGEVIEWER_DKIMCHECKER_LOG) << "Loading RSA public key not supported with LibreSSL";
+    return {nullptr, EVP_PKEY_free};
+#else
     EVP_PKEY *pubKey = nullptr;
     std::unique_ptr<OSSL_DECODER_CTX, decltype(&OSSL_DECODER_CTX_free)> decoderCtx(
         OSSL_DECODER_CTX_new_for_pkey(&pubKey, "DER", nullptr, "RSA", EVP_PKEY_PUBLIC_KEY, nullptr, nullptr),
@@ -527,6 +533,7 @@ EVPPKeyPtr loadRSAPublicKey(const QByteArray &der)
     }
 
     return {pubKey, EVP_PKEY_free};
+#endif
 }
 
 const EVP_MD *evpAlgo(DKIMInfo::HashingAlgorithmType algo)
@@ -573,6 +580,16 @@ std::optional<bool> doVerifySignature(EVP_PKEY *key, c
     return true;
 }
 
+#ifdef LIBRESSL_VERSION_NUMBER
+
+void DKIMCheckSignatureJob::verifyRSASignature()
+{
+    qCWarning(MESSAGEVIEWER_DKIMCHECKER_LOG) << "RSA signature verification not supported with LibreSSL";
+    return verificationFailed(DKIMError::ImpossibleToVerifySignature);
+}
+
+#else
+
 uint64_t getKeyE(EVP_PKEY *key)
 {
     BIGNUM *bne = nullptr;
@@ -638,6 +655,7 @@ void DKIMCheckSignatureJob::verifyRSASignature()
     Q_EMIT result(createCheckResult());
     deleteLater();
 }
+#endif
 
 void DKIMCheckSignatureJob::verificationFailed(DKIMError error)
 {
