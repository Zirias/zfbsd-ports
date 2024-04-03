--- vendor/openssl-sys-0.9.92/build/main.rs.orig	2025-02-17 18:17:27 UTC
+++ vendor/openssl-sys-0.9.92/build/main.rs
@@ -273,6 +273,14 @@ See rust-openssl documentation for more information:
             (3, 7, 1) => ('3', '7', '1'),
             (3, 7, _) => ('3', '7', 'x'),
             (3, 8, 0) => ('3', '8', '0'),
+            (3, 8, 1) => ('3', '8', '1'),
+            (3, 8, 2) => ('3', '8', '2'),
+            (3, 8, 3) => ('3', '8', '3'),
+            (3, 8, 4) => ('3', '8', '4'),
+            (3, 9, 0) => ('3', '9', '0'),
+            (3, 9, 1) => ('3', '9', '1'),
+            (3, 9, 2) => ('3', '9', '2'),
+            (4, 0, 0) => ('4', '0', '0'),
             _ => version_error(),
         };
 
@@ -315,7 +323,7 @@ This crate is only compatible with OpenSSL (version 1.
         "
 
 This crate is only compatible with OpenSSL (version 1.0.1 through 1.1.1, or 3.0.0), or LibreSSL 2.5
-through 3.8.0, but a different version of OpenSSL was found. The build is now aborting
+through 4.0.0, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
