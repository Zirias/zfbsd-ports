--- src/modules/rlm_eap/types/rlm_eap_fast/rlm_eap_fast.c.orig	2023-05-26 13:56:52 UTC
+++ src/modules/rlm_eap/types/rlm_eap_fast/rlm_eap_fast.c
@@ -224,7 +224,7 @@ static int _session_secret(SSL *s, void *secret, int *
 
 	RDEBUG("processing PAC-Opaque");
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 	eap_fast_session_ticket(tls_session, s->s3->client_random, s->s3->server_random, secret, secret_len);
 #else
 	uint8_t client_random[SSL3_RANDOM_SIZE];
@@ -591,7 +591,7 @@ static int mod_session_init(void *type_arg, eap_handle
 		}
 	}
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 	{
 		int i;
 		for (i = 0; ; i++) {
