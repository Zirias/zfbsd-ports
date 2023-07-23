--- src/VBox/Runtime/common/crypto/digest-builtin.cpp.orig	2023-07-23 16:41:16 UTC
+++ src/VBox/Runtime/common/crypto/digest-builtin.cpp
@@ -928,7 +928,7 @@ static PCRTCRDIGESTDESC const g_apDigestOps[] =
  * OpenSSL EVP.
  */
 
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
 /** @impl_interface_method{RTCRDIGESTDESC::pfnNew} */
 static DECLCALLBACK(void*) rtCrDigestOsslEvp_New(void)
 {
@@ -964,7 +964,7 @@ static DECLCALLBACK(int) rtCrDigestOsslEvp_Init(void *
     if (fReInit)
     {
         pEvpType = EVP_MD_CTX_md(pThis);
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
         EVP_MD_CTX_reset(pThis);
 # else
         EVP_MD_CTX_cleanup(pThis);
@@ -972,7 +972,7 @@ static DECLCALLBACK(int) rtCrDigestOsslEvp_Init(void *
     }
 
     AssertPtrReturn(pEvpType, VERR_INVALID_PARAMETER);
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
     Assert(EVP_MD_block_size(pEvpType));
 # else
     Assert(pEvpType->md_size);
@@ -987,7 +987,7 @@ static DECLCALLBACK(int) rtCrDigestOsslEvp_Init(void *
 static DECLCALLBACK(void) rtCrDigestOsslEvp_Delete(void *pvState)
 {
     EVP_MD_CTX *pThis = (EVP_MD_CTX *)pvState;
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
     EVP_MD_CTX_reset(pThis);
 # else
     EVP_MD_CTX_cleanup(pThis);
@@ -1032,13 +1032,13 @@ static RTCRDIGESTDESC const g_rtCrDigestOpenSslDesc =
     NULL,
     RTDIGESTTYPE_UNKNOWN,
     EVP_MAX_MD_SIZE,
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
     0,
 # else
     sizeof(EVP_MD_CTX),
 # endif
     0,
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
     rtCrDigestOsslEvp_New,
     rtCrDigestOsslEvp_Free,
 # else
@@ -1100,7 +1100,7 @@ RTDECL(PCRTCRDIGESTDESC) RTCrDigestFindByObjIdString(c
                 /*
                  * Return the OpenSSL provider descriptor and the EVP_MD address.
                  */
-# if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+# if OPENSSL_VERSION_NUMBER >= 0x10100000
                 Assert(EVP_MD_block_size(pEvpMdType));
 # else
                 Assert(pEvpMdType->md_size);
