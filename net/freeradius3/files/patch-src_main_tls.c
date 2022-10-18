--- src/main/tls.c.orig	2024-07-08 20:29:24 UTC
+++ src/main/tls.c
@@ -701,7 +701,7 @@ tls_session_t *tls_new_session(TALLOC_CTX *ctx, fr_tls
 				/*
 				 * Swap empty store with the old one.
 				 */
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 				conf->old_x509_store = SSL_CTX_get_cert_store(conf->ctx);
 				/* Bump refcnt so the store is kept allocated till next store replacement */
 				X509_STORE_up_ref(conf->old_x509_store);
@@ -2069,7 +2069,7 @@ done:
 	return 0;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 static SSL_SESSION *cbtls_get_session(SSL *ssl, unsigned char *data, int len, int *copy)
 #else
 static SSL_SESSION *cbtls_get_session(SSL *ssl, const unsigned char *data, int len, int *copy)
@@ -2453,7 +2453,7 @@ static int cbtls_cache_refresh(SSL *ssl, SSL_SESSION *
 	return 0;
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
 static SSL_SESSION *cbtls_cache_load(SSL *ssl, unsigned char *data, int len, int *copy)
 #else
 static SSL_SESSION *cbtls_cache_load(SSL *ssl, const unsigned char *data, int len, int *copy)
@@ -2985,7 +2985,7 @@ int cbtls_verify(int ok, X509_STORE_CTX *ctx)
 	char		cn_str[1024];
 	char		buf[64];
 	X509		*client_cert;
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 	const STACK_OF(X509_EXTENSION) *ext_list;
 #else
 	STACK_OF(X509_EXTENSION) *ext_list;
@@ -3220,7 +3220,7 @@ int cbtls_verify(int ok, X509_STORE_CTX *ctx)
 	}
 
 	if (lookup == 0) {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 		ext_list = X509_get0_extensions(client_cert);
 #else
 		X509_CINF	*client_inf;
@@ -3273,7 +3273,7 @@ int cbtls_verify(int ok, X509_STORE_CTX *ctx)
 				value[0] = '0';
 				value[1] = 'x';
 				const unsigned char *srcp;
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 				const ASN1_STRING *srcasn1p;
 				srcasn1p = X509_EXTENSION_get_data(ext);
 				srcp = ASN1_STRING_get0_data(srcasn1p);
@@ -3604,7 +3604,7 @@ static int set_ecdh_curve(SSL_CTX *ctx, char const *ec
 
 	if (!ecdh_curve) return 0;
 
-#if OPENSSL_VERSION_NUMBER >= 0x1000200fL
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fL && !defined(LIBRESSL_VERSION_NUMBER)
 	/*
 	 *	A colon-separated list of curves.
 	 */
@@ -3769,7 +3769,7 @@ void tls_global_cleanup(void)
 {
 #if OPENSSL_VERSION_NUMBER < 0x10000000L
 	ERR_remove_state(0);
-#elif OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#elif OPENSSL_VERSION_NUMBER < 0x10100000L
 	ERR_remove_thread_state(NULL);
 #endif
 #ifndef OPENSSL_NO_ENGINE
@@ -4346,7 +4346,7 @@ post_ca:
 		}
 	}
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L && !defined(LIBRESSL_VERSION_NUMBER)
 	if (conf->sigalgs_list) {
 		char *list;
 
@@ -4366,7 +4366,7 @@ post_ca:
 	 *	send it flowers and cake.
 	 */
 	if (min_version <= TLS1_1_VERSION) {
-#if OPENSSL_VERSION_NUMBER >= 0x10101000L
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L && !defined(LIBRESSL_VERSION_NUMBER)
 		int seclevel = SSL_CTX_get_security_level(ctx);
 		int required;;
 
@@ -4582,7 +4582,6 @@ post_ca:
 		SSL_CTX_set_verify_depth(ctx, conf->verify_depth);
 	}
 
-#ifndef LIBRESSL_VERSION_NUMBER
 	/* Load randomness */
 	if (conf->random_file) {
 		if (!(RAND_load_file(conf->random_file, 1024*10))) {
@@ -4590,7 +4589,6 @@ post_ca:
 			return NULL;
 		}
 	}
-#endif
 
 	/*
 	 *	Setup session caching
@@ -4627,14 +4625,14 @@ post_ca:
 		 */
 		SSL_CTX_sess_set_cache_size(ctx, conf->session_cache_size);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
 		SSL_CTX_set_num_tickets(ctx, 1);
 #endif
 
 	} else {
 		SSL_CTX_set_session_cache_mode(ctx, SSL_SESS_CACHE_OFF);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101000L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10101000L
 		/*
 		 *	This controls the number of stateful or stateless tickets
 		 *	generated with TLS 1.3.  In OpenSSL 1.1.1 it's also
