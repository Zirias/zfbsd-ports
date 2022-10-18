--- src/modules/rlm_pap/rlm_pap.c.orig	2024-07-08 20:29:24 UTC
+++ src/modules/rlm_pap/rlm_pap.c
@@ -934,7 +934,7 @@ static inline rlm_rcode_t CC_HINT(nonnull) pap_auth_pb
 		digest_len = SHA512_DIGEST_LENGTH;
 		break;
 
-#  if OPENSSL_VERSION_NUMBER >= 0x10101000L
+#  if OPENSSL_VERSION_NUMBER >= 0x10101000L && !defined(LIBRESSL_VERSION_NUMBER)
 	case PW_SSHA3_224_PASSWORD:
 		evp_md = EVP_sha3_224();
 		digest_len = SHA224_DIGEST_LENGTH;
