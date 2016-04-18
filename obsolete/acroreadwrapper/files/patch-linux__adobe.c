--- linux_adobe.c.orig	2016-04-18 20:25:50 UTC
+++ linux_adobe.c
@@ -44,14 +44,16 @@ __FBSDID("$FreeBSD$");
 #ifdef COMPAT_LINUX32
 #include <machine/../linux32/linux.h>
 #include <machine/../linux32/linux32_proto.h>
+#define LXSYSENT linux32_sysent
 #else
 #include <machine/../linux/linux.h>
 #include <machine/../linux/linux_proto.h>
+#define LXSYSENT linux_sysent
 #endif
 
 #define LINUX_ADOBE_PROCNAME	"acroread"
 
-extern struct sysent linux_sysent[];
+extern struct sysent LXSYSENT[];
 #define SYS_linux_sched_setscheduler	(156)
 
 static int
@@ -111,11 +113,11 @@ linux_adobe_load(struct module *module, 
 
 	switch (cmd) {
 	case MOD_LOAD:
-		linux_sysent[SYS_linux_sched_setscheduler].sy_call =
+		LXSYSENT[SYS_linux_sched_setscheduler].sy_call =
 			(sy_call_t *)linux_adobe_linux_sched_setscheduler;
 		break;
 	case MOD_UNLOAD:
-		linux_sysent[SYS_linux_sched_setscheduler].sy_call =
+		LXSYSENT[SYS_linux_sched_setscheduler].sy_call =
 			(sy_call_t *)linux_sched_setscheduler;
 		break;
 	default:
