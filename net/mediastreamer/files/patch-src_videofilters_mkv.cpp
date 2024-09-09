--- src/videofilters/mkv.cpp.orig	2024-08-26 10:10:02 UTC
+++ src/videofilters/mkv.cpp
@@ -1690,7 +1690,7 @@ static matroska_block *matroska_write_block(Matroska *
 			codecPrivateElt = (ebml_binary *)EBML_MasterAddElt(blockGroup, &MATROSKA_ContextCodecState, FALSE);
 			EBML_BinarySetData(codecPrivateElt, codecPrivateData, codecPrivateDataSize);
 		}
-		MATROSKA_BlockSetTrackNum(block, trackNum);
+		MATROSKA_BlockGetFrameEnd(block, trackNum);
 		MATROSKA_LinkBlockWithReadTracks(block, obj->tracks, TRUE);
 		MATROSKA_LinkBlockWriteSegmentInfo(block, obj->info);
 		MATROSKA_BlockSetKeyframe(block, isKeyFrame);
