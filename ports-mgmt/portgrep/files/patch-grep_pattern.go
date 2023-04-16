--- grep/pattern.go.orig	2023-04-16 08:03:00 UTC
+++ grep/pattern.go
@@ -188,31 +188,31 @@ var (
 		opt:  'd',
 		pref: "",
 		desc: "search by *_DEPENDS",
-		pat:  `(?:.*\n){0,%d}\b(?P<q>(\w+_)?DEPENDS)\s*(\+|\?)?(=|=.*?[\s/}])(?P<r>%s)((\n|\z)|[\s@:>\.].*(\n|\z))(?:.*\n){0,%d}`,
+		pat:  `(?:.*\n){0,%d}\b(?P<q>(\w+_)?DEPENDS(_OFF)?)\s*(\+|\?)?(=|=.*?[\s/}])(?P<r>%s)((\n|\z)|[\s@:>\.].*(\n|\z))(?:.*\n){0,%d}`,
 	}
 	buildDepends = &stringPattern{
 		opt:  'b',
 		pref: "",
 		desc: "search by BUILD_DEPENDS",
-		pat:  `(?:.*\n){0,%d}\b(?P<q>(\w+_)?BUILD_DEPENDS)\s*(\+|\?)?(=|=.*?[\s/}])(?P<r>%s)((\n|\z)|[\s@:>\.].*(\n|\z))(?:.*\n){0,%d}`,
+		pat:  `(?:.*\n){0,%d}\b(?P<q>(\w+_)?BUILD_DEPENDS(_OFF)?)\s*(\+|\?)?(=|=.*?[\s/}])(?P<r>%s)((\n|\z)|[\s@:>\.].*(\n|\z))(?:.*\n){0,%d}`,
 	}
 	libDepends = &stringPattern{
 		opt:  'l',
 		pref: "",
 		desc: "search by LIB_DEPENDS",
-		pat:  `(?:.*\n){0,%d}\b(?P<q>(\w+_)?LIB_DEPENDS)\s*(\+|\?)?(=|=.*?[\s/}])(?P<r>%s)((\n|\z)|[\s@:\.].*(\n|\z))(?:.*\n){0,%d}`,
+		pat:  `(?:.*\n){0,%d}\b(?P<q>(\w+_)?LIB_DEPENDS(_OFF)?)\s*(\+|\?)?(=|=.*?[\s/}])(?P<r>%s)((\n|\z)|[\s@:\.].*(\n|\z))(?:.*\n){0,%d}`,
 	}
 	runDepends = &stringPattern{
 		opt:  'r',
 		pref: "",
 		desc: "search by RUN_DEPENDS",
-		pat:  `(?:.*\n){0,%d}\b(?P<q>(\w+_)?RUN_DEPENDS)\s*(\+|\?)?(=|=.*?[\s/}])(?P<r>%s)((\n|\z)|[\s@:>\.].*(\n|\z))(?:.*\n){0,%d}`,
+		pat:  `(?:.*\n){0,%d}\b(?P<q>(\w+_)?RUN_DEPENDS(_OFF)?)\s*(\+|\?)?(=|=.*?[\s/}])(?P<r>%s)((\n|\z)|[\s@:>\.].*(\n|\z))(?:.*\n){0,%d}`,
 	}
 	testDepends = &stringPattern{
 		opt:  't',
 		pref: "",
 		desc: "search by TEST_DEPENDS",
-		pat:  `(?:.*\n){0,%d}\b(?P<q>(\w+_)?TEST_DEPENDS)\s*(\+|\?)?(=|=.*?[\s/}])(?P<r>%s)((\n|\z)|[\s@:>\.].*(\n|\z))(?:.*\n){0,%d}`,
+		pat:  `(?:.*\n){0,%d}\b(?P<q>(\w+_)?TEST_DEPENDS(_OFF)?)\s*(\+|\?)?(=|=.*?[\s/}])(?P<r>%s)((\n|\z)|[\s@:>\.].*(\n|\z))(?:.*\n){0,%d}`,
 	}
 	onlyForArchs = &stringPattern{
 		opt:  'a',
@@ -224,13 +224,13 @@ var (
 		opt:  'u',
 		pref: "",
 		desc: "search by USES",
-		pat:  `(?:.*\n){0,%d}\b(?P<q>([\w_]+_)?USES)\s*(\+|\?)?(=|=.*?\s)(?P<r>%s)((\n|\z)|[\s:,].*(\n|\z))(?:.*\n){0,%d}`,
+		pat:  `(?:.*\n){0,%d}\b(?P<q>([\w_]+_)?USES(_OFF)?)\s*(\+|\?)?(=|=.*?\s)(?P<r>%s)((\n|\z)|[\s:,].*(\n|\z))(?:.*\n){0,%d}`,
 	}
 	plist = &stringPattern{
 		opt:  'p',
 		pref: "",
 		desc: "search by PLIST_FILES",
-		pat:  `(?:.*\n){0,%d}\b(?P<q>([\w_]+_)?PLIST_FILES)\s*(\+|\?)?=.*?(?P<r>%s).*(\n|\z)(?:.*\n){0,%d}`,
+		pat:  `(?:.*\n){0,%d}\b(?P<q>([\w_]+_)?PLIST_FILES(_OFF)?)\s*(\+|\?)?=.*?(?P<r>%s).*(\n|\z)(?:.*\n){0,%d}`,
 	}
 	broken = &boolPattern{
 		opt:  'X',
