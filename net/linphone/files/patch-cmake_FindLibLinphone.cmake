--- cmake/FindLibLinphone.cmake.orig	2024-09-08 18:13:33 UTC
+++ cmake/FindLibLinphone.cmake
@@ -27,7 +27,7 @@ if(NOT TARGET liblinphone)
 if(NOT TARGET liblinphone)
     set(EXPORT_PATH ${LINPHONE_OUTPUT_DIR})
     include(GNUInstallDirs)
-    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/linphone/cmake/linphoneTargets.cmake)
+    include(${EXPORT_PATH}/${CMAKE_INSTALL_DATADIR}/LibLinphone/cmake/LibLinphoneTargets.cmake)
 endif()
 
 set(_LibLinphone_REQUIRED_VARS LibLinphone_TARGET LibLinphone_PLUGINS_DIR)
@@ -35,7 +35,7 @@ if(TARGET liblinphone)
 
 if(TARGET liblinphone)
 	set(LibLinphone_TARGET liblinphone)
-	get_target_property(LibLinphone_PLUGINS_DIR ${LibLinphone_TARGET} LIBLINPHONE_PLUGINS_DIR)
+	set(LibLinphone_PLUGINS_DIR ${CMAKE_INSTALL_PREFIX}/lib/liblinphone/plugins)
 endif()
 
 include(FindPackageHandleStandardArgs)
