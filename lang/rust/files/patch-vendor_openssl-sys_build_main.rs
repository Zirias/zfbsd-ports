--- vendor/openssl-sys/build/main.rs.orig	2023-12-04 07:25:46 UTC
+++ vendor/openssl-sys/build/main.rs
@@ -274,6 +274,8 @@ See rust-openssl documentation for more information:
             (3, 7, 1) => ('3', '7', '1'),
             (3, 7, _) => ('3', '7', 'x'),
             (3, 8, 0) => ('3', '8', '0'),
+            (3, 8, 1) => ('3', '8', '1'),
+            (3, 8, 2) => ('3', '8', '2'),
             _ => version_error(),
         };
 
