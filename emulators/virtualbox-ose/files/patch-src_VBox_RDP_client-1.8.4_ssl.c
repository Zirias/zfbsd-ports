--- src/VBox/RDP/client-1.8.4/ssl.c.orig	2023-07-23 17:02:26 UTC
+++ src/VBox/RDP/client-1.8.4/ssl.c
@@ -97,7 +97,7 @@ void
 rdssl_rsa_encrypt(uint8 * out, uint8 * in, int len, uint32 modulus_size, uint8 * modulus,
 		  uint8 * exponent)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
 	BN_CTX *ctx;
 	BIGNUM *mod, *exp, *x, *y;
 	uint8 inr[SEC_MAX_MODULUS_SIZE];
@@ -128,7 +128,7 @@ rdssl_rsa_encrypt(uint8 * out, uint8 * in, int len, ui
 	BN_free(exp);
 	BN_free(mod);
 	BN_CTX_free(ctx);
-#else /* OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER) */
+#else /* OPENSSL_VERSION_NUMBER < 0x10100000) */
 	BN_CTX *ctx;
 	BIGNUM mod, exp, x, y;
 	uint8 inr[SEC_MAX_MODULUS_SIZE];
@@ -159,7 +159,7 @@ rdssl_rsa_encrypt(uint8 * out, uint8 * in, int len, ui
 	BN_free(&exp);
 	BN_free(&mod);
 	BN_CTX_free(ctx);
-#endif /* OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER) */
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000 */
 }
 
 /* returns newly allocated RDSSL_CERT or NULL */
@@ -183,7 +183,7 @@ rdssl_cert_to_rkey(RDSSL_CERT * cert, uint32 * key_len
 	EVP_PKEY *epk = NULL;
 	RDSSL_RKEY *lkey;
 	int nid;
-#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
 	int ret;
 
 	/* By some reason, Microsoft sets the OID of the Public RSA key to
@@ -217,7 +217,7 @@ rdssl_cert_to_rkey(RDSSL_CERT * cert, uint32 * key_len
 		X509_PUBKEY_set0_param(key, OBJ_nid2obj(NID_rsaEncryption),
 				       0, NULL, NULL, 0);
 	}
-#else /* OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER) */
+#else /* OPENSSL_VERSION_NUMBER < 0x10100000 */
 	nid = OBJ_obj2nid(cert->cert_info->key->algor->algorithm);
 	if ((nid == NID_md5WithRSAEncryption) || (nid == NID_shaWithRSAEncryption))
 	{
@@ -225,7 +225,7 @@ rdssl_cert_to_rkey(RDSSL_CERT * cert, uint32 * key_len
 		ASN1_OBJECT_free(cert->cert_info->key->algor->algorithm);
 		cert->cert_info->key->algor->algorithm = OBJ_nid2obj(NID_rsaEncryption);
 	}
-#endif /* OPENSSL_VERSION_NUMBER < 0x10100000 || && defined(LIBRESSL_VERSION_NUMBER) */
+#endif /* OPENSSL_VERSION_NUMBER < 0x10100000 */
 	epk = X509_get_pubkey(cert);
 	if (NULL == epk)
 	{
@@ -274,7 +274,7 @@ rdssl_rkey_get_exp_mod(RDSSL_RKEY * rkey, uint8 * expo
 {
 	int len;
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000 && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000
 	const BIGNUM *e, *n;
 	RSA_get0_key(rkey, &n, &e, NULL);
 	if ((BN_num_bytes(e) > (int) max_exp_len) ||
@@ -316,12 +316,12 @@ void
 rdssl_hmac_md5(const void *key, int key_len, const unsigned char *msg, int msg_len,
 	       unsigned char *md)
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000
 	HMAC_CTX ctx;
 	HMAC_CTX_init(&ctx);
 #endif
 	HMAC(EVP_md5(), key, key_len, msg, msg_len, md, NULL);
-#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000
 	HMAC_CTX_cleanup(&ctx);
 #endif
 }
