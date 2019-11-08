--- src/src.pro.orig	2019-11-08 14:00:40 UTC
+++ src/src.pro
@@ -26,8 +26,7 @@ TEMPLATE = app
 
 CONFIG += c++11
 
-# Versionsnummer ermitteln aus Git Tag Nummer
-GIT_VERSION = $$system(git --git-dir \"../.git\" describe --always --tags)
+GIT_VERSION = 5.0.17
 DEFINES += VERSION_STRING=\\\"$$GIT_VERSION\\\"
 
 message("Emu64 Version: " $$GIT_VERSION)
@@ -43,6 +42,17 @@ linux-g++{
    }
 }
 
+# FreeBSD
+freebsd-clang{
+   !contains(QT_ARCH, x86_64){
+       DEFINES += ARCHITECTURE_STRING=\\\"32Bit\\\"
+       message("Compiling for FreeBSD 32bit system")
+    } else {
+       DEFINES += ARCHITECTURE_STRING=\\\"64Bit\\\"
+       message("Compiling for FreeBSD 64bit system")
+   }
+}
+
 # Windows Architecture
 win32{
    !contains(QT_ARCH, x86_64){
@@ -238,6 +248,15 @@ win32{
 }
 
 linux-g++{
+    target.path = $$PREFIX/bin
+    roms.path = $$PREFIX/share/$$TARGET/roms
+    floppy_sounds.path = $$PREFIX/share/$$TARGET/floppy_sounds
+    gfx.path = $$PREFIX/share/$$TARGET/gfx
+    txt.path = $$PREFIX/share/$$TARGET
+    languages.path = $$PREFIX/share/$$TARGET/languages
+}
+
+freebsd-clang{
     target.path = $$PREFIX/bin
     roms.path = $$PREFIX/share/$$TARGET/roms
     floppy_sounds.path = $$PREFIX/share/$$TARGET/floppy_sounds
