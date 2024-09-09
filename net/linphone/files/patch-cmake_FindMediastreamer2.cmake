--- cmake/FindMediastreamer2.cmake.orig	2024-09-08 18:06:19 UTC
+++ cmake/FindMediastreamer2.cmake
@@ -37,7 +37,7 @@ if(TARGET mediastreamer2)
 
 if(TARGET mediastreamer2)
 	set(Mediastreamer2_TARGET mediastreamer2)
-	get_target_property(Mediastreamer2_PLUGINS_DIR ${Mediastreamer2_TARGET} MS2_PLUGINS_DIR)
+	set(Mediastreamer2_PLUGINS_DIR ${CMAKE_INSTALL_PREFIX}/lib/mediastreamer/plugins)
 endif()
 
 include(FindPackageHandleStandardArgs)
