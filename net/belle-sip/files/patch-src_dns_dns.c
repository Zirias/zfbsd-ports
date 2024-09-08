--- src/dns/dns.c.orig	2024-09-08 06:40:37 UTC
+++ src/dns/dns.c
@@ -4661,6 +4661,7 @@ int dns_resconf_loadfromresolv(struct dns_resolv_conf 
 	union res_sockaddr_union addresses[3];
 	int i, error, write_index;
 
+	memset(&res, 0, sizeof(res));
 	if ((error = res_ninit(&res))) {
 		return error;
 	}
