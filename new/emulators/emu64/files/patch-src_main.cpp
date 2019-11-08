--- src/main.cpp.orig	2019-11-08 13:56:14 UTC
+++ src/main.cpp
@@ -104,9 +104,7 @@ int main(int argc, char *argv[])
 #ifdef _WIN32
     FreeConsole();
     QFile LogFile("emu64.log");
-#endif
-
-#ifdef __linux__
+#else
     if(!config_dir.exists())
     {
         QDir dir = QDir::root();
@@ -128,10 +126,8 @@ int main(int argc, char *argv[])
 
 #ifdef _WIN32
     if(log) *log << "*** Emu64 Win32 Binary File ***\n\n";
-#endif
-
-#ifdef __linux__
-    if(log) *log << "*** Emu64 Linux Binary File ***\n\n";
+#else
+    if(log) *log << "*** Emu64 POSIX Binary File ***\n\n";
 #endif
 
     if(log != nullptr) *log << "Emu64 Version: " << VERSION_STRING << "\n\n";
