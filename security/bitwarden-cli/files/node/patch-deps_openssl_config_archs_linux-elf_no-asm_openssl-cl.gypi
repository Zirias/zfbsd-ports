--- deps/openssl/config/archs/linux-elf/no-asm/openssl-cl.gypi.orig	2023-03-05 06:42:52 UTC
+++ deps/openssl/config/archs/linux-elf/no-asm/openssl-cl.gypi
@@ -13,7 +13,7 @@
       '-Wall -O3 -fomit-frame-pointer',
     ],
     'openssl_ex_libs_linux-elf': [
-      '-ldl -pthread',
+      '-pthread',
     ],
     'openssl_cli_srcs_linux-elf': [
       'openssl/apps/lib/cmp_mock_srv.c',
