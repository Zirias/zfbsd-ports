--- src/VBox/Runtime/common/crypto/key-openssl.cpp.orig	2023-07-23 16:43:29 UTC
+++ src/VBox/Runtime/common/crypto/key-openssl.cpp
@@ -250,7 +250,7 @@ DECLHIDDEN(int) rtCrKeyToOpenSslKeyEx(RTCRKEY hKey, bo
                                    "Unknown public key algorithm [OpenSSL]: %s", pszAlgoObjId);
     const char *pszAlgoSn = OBJ_nid2sn(iAlgoNid);
 
-# if OPENSSL_VERSION_NUMBER >= 0x10001000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10001000
     int idAlgoPkey = 0;
     int idAlgoMd = 0;
     if (!OBJ_find_sigid_algs(iAlgoNid, &idAlgoMd, &idAlgoPkey))
@@ -281,7 +281,7 @@ DECLHIDDEN(int) rtCrKeyToOpenSslKeyEx(RTCRKEY hKey, bo
         return RTERRINFO_LOG_SET_F(pErrInfo, VERR_NO_MEMORY, "EVP_PKEY_new(%d) failed", iAlgoNid);
 
     int rc;
-# if OPENSSL_VERSION_NUMBER >= 0x10001000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10001000
     if (EVP_PKEY_set_type(pEvpNewKey, idAlgoPkey))
     {
         int idKeyType = EVP_PKEY_base_id(pEvpNewKey);
@@ -302,7 +302,7 @@ DECLHIDDEN(int) rtCrKeyToOpenSslKeyEx(RTCRKEY hKey, bo
             }
         }
         else
-# if OPENSSL_VERSION_NUMBER < 0x10001000 || defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER < 0x10001000
             rc = RTERRINFO_LOG_SET(pErrInfo, VERR_CR_PKIX_OSSL_EVP_PKEY_TYPE_ERROR, "EVP_PKEY_type() failed");
 # else
             rc = RTERRINFO_LOG_SET(pErrInfo, VERR_CR_PKIX_OSSL_EVP_PKEY_TYPE_ERROR, "EVP_PKEY_base_id() failed");
