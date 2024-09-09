--- console/linphonec.c.orig	2024-09-08 07:29:54 UTC
+++ console/linphonec.c
@@ -921,7 +921,7 @@ static void lpc_apply_video_params(void) {
  *  - LPC_AUTH_STACK auth_stack;
  *
  */
-static int linphonec_idle_call() {
+static int linphonec_idle_call(void) {
 	LinphoneCore *opm = linphonec;
 
 	/* Uncomment the following to verify being called */
@@ -1170,7 +1170,7 @@ static int linphonec_parse_cmdline(int argc, char **ar
  *	 1 if it migrated successfully
  *	-1 on error
  */
-static int handle_configfile_migration() {
+static int handle_configfile_migration(void) {
 #if !defined(_WIN32_WCE)
 	char *old_cfg_gui;
 	char *old_cfg_cli;
