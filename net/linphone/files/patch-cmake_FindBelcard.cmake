--- cmake/FindBelcard.cmake.orig	2024-09-08 17:49:51 UTC
+++ cmake/FindBelcard.cmake
@@ -26,7 +26,7 @@ if(NOT TARGET belcard)
 if(NOT TARGET belcard)
     set(EXPORT_PATH ${LINPHONE_OUTPUT_DIR})
     include(GNUInstallDirs)
-    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/Belcard/cmake/BelcardTargets.cmake)
+    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/BelCard/cmake/BelCardTargets.cmake)
 endif()
 
 set(_Belcard_REQUIRED_VARS Belcard_TARGET)
