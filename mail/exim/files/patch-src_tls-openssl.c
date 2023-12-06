--- src/tls-openssl.c.orig	2023-11-04 12:55:49 UTC
+++ src/tls-openssl.c
@@ -69,12 +69,14 @@ crypto provider for libtls instead of continuing to ti
 into even twistier knots.  If LibreSSL gains the same API, we can just
 change this guard and punt the issue for a while longer. */
 
-#ifndef LIBRESSL_VERSION_NUMBER
+#if !defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER >= 0x3080200fL
 # if OPENSSL_VERSION_NUMBER >= 0x010100000L
 #  define EXIM_HAVE_OPENSSL_CHECKHOST
 #  define EXIM_HAVE_OPENSSL_DH_BITS
 #  define EXIM_HAVE_OPENSSL_TLS_METHOD
-#  define EXIM_HAVE_OPENSSL_KEYLOG
+#  ifndef LIBRESSL_VERSION_NUMBER
+#   define EXIM_HAVE_OPENSSL_KEYLOG
+#  endif
 #  define EXIM_HAVE_OPENSSL_CIPHER_GET_ID
 #  define EXIM_HAVE_SESSION_TICKET
 #  define EXIM_HAVE_OPESSL_TRACE
@@ -2605,7 +2607,7 @@ if (!(bs = OCSP_response_get1_basic(rsp)))
     asking for certificate-status under DANE, so this callback won't run for
     that combination. It still will for non-DANE. */
 
-#ifdef EXIM_HAVE_OPENSSL_OCSP_RESP_GET0_SIGNER
+#if defined(EXIM_HAVE_OPENSSL_OCSP_RESP_GET0_SIGNER) && defined(SUPPORT_DANE)
     X509 * signer;
 
     if (  tls_out.dane_verified
