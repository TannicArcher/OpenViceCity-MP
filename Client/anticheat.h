#pragma once

#include "main.h"
#include "md5.h"

struct mdFile
{
	char szFileLocation[128];
	uint32 iCorrectDigestArray[4];
	unsigned char szRawLocalDigest[16];
};


// if anticheat functions return FALSE they have failed, otherwise TRUE

BOOL MemoryModificationCheck();
BOOL FileCheckSum();
BOOL CheckFile(mdFile* mdChkFile);
