#pragma once

#include <Windows.h>

#include "file_api.h"


int PrepareRealApiEntry();
void DoHook();
void EnableAllHookFunction();
void InstallHookFunction(void* OriginFunction, void* HookFunction);
void DisableHookFunction(void* OriginFunction);
void UninstallAllHookFunction();

extern ptrSetFileTime realSetFileTime;
extern ptrDeleteFileW realDeleteFileW;
extern ptrCopyFileW realCopyFileW;
extern ptrMoveFileW realMoveFileW;
extern ptrCreateFileW realCreateFileW;
extern ptrCreateFileA realCreateFileA;
extern ptrMessageBoxW realMessageBoxW;