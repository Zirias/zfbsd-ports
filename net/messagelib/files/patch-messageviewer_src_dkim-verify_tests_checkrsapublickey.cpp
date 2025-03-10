--- messageviewer/src/dkim-verify/tests/checkrsapublickey.cpp.orig	2025-03-10 08:43:11 UTC
+++ messageviewer/src/dkim-verify/tests/checkrsapublickey.cpp
@@ -10,7 +10,9 @@
 #include <QDebug>
 #include <QStandardPaths>
 
+#ifndef LIBRESSL_VERSION_NUMBER
 #include <openssl/decoder.h>
+#endif
 #include <openssl/err.h>
 #include <openssl/evp.h>
 
