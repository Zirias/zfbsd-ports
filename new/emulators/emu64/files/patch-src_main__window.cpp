--- src/main_window.cpp.orig	2019-11-08 13:57:03 UTC
+++ src/main_window.cpp
@@ -38,11 +38,9 @@ MainWindow::MainWindow(QWidget *parent,CustomSplashScr
 
 #ifdef _WIN32
     setWindowTitle("Emu64 Version " + QString(VERSION_STRING) + " --- [Windows " + QString(ARCHITECTURE_STRING) + "]");
+#else
+    setWindowTitle("Emu64 Version " + QString(VERSION_STRING) + " --- [POSIX " + QString(ARCHITECTURE_STRING) + "]");
 #endif
-
-#ifdef __linux__
-    setWindowTitle("Emu64 Version " + QString(VERSION_STRING) + " --- [Linux " + QString(ARCHITECTURE_STRING) + "]");
-#endif
 }
 
 MainWindow::~MainWindow()
@@ -155,8 +153,7 @@ void MainWindow::OnInit()
         dataPath = QApplication::applicationDirPath();
     else
         dataPath = custom_dataPath;
-#endif
-#ifdef __linux__
+#else
     if(custom_dataPath == "")
     {
         dataPath = DATA_PATH;
