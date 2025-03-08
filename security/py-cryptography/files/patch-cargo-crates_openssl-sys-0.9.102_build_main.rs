--- cargo-crates/openssl-sys-0.9.102/build/main.rs.orig	2025-03-08 06:29:46 UTC
+++ cargo-crates/openssl-sys-0.9.102/build/main.rs
@@ -304,6 +304,7 @@ See rust-openssl documentation for more information:
             (3, 8, _) => ('3', '8', 'x'),
             (3, 9, 0) => ('3', '9', '0'),
             (3, 9, _) => ('3', '9', 'x'),
+            (4, 0, 0) => ('4', '0', '0'),
             _ => version_error(),
         };
 
@@ -346,7 +347,7 @@ This crate is only compatible with OpenSSL (version 1.
         "
 
 This crate is only compatible with OpenSSL (version 1.0.1 through 1.1.1, or 3), or LibreSSL 2.5
-through 3.9.x, but a different version of OpenSSL was found. The build is now aborting
+through 4.0.0, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
