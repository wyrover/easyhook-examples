#include "real_api.h"

#include <easyhook.h>
#include <map>
#include <sstream>




ptrSetFileTime realSetFileTime = NULL;
ptrCopyFileW realCopyFileW = NULL;
ptrMoveFileW realMoveFileW = NULL;
ptrDeleteFileW realDeleteFileW = NULL;
ptrCreateFileW realCreateFileW = NULL;
ptrCreateFileA realCreateFileA = NULL;
ptrMessageBoxW realMessageBoxW = NULL;

std::map<void*, TRACED_HOOK_HANDLE> HookHandleMap;
ULONG ThreadList = 0;



BOOL PrepareRealApiEntry()
{
	OutputDebugString(L"PrepareRealApiEntry()\n");

	BOOL retval = FALSE;
	do
	{
 
		HMODULE hKernel32 = LoadLibrary(L"Kernel32.dll");
		if (hKernel32 == NULL)
		{
			OutputDebugString(L"LoadLibrary(L\"Kernel32.dll\") Error\n");
			break;
		}

		HMODULE hUser32 = LoadLibrary(L"user32.dll");
		if (hUser32 == NULL) {
			OutputDebugString(L"LoadLibrary(L\"user32.dll\") Error\n");
			break;
		}

		realSetFileTime = (ptrSetFileTime)GetProcAddress(hKernel32, "SetFileTime");
		if (!realSetFileTime) {
			OutputDebugString(L"realSetFileTime Error\n");
			break;
		}

		realDeleteFileW = (ptrDeleteFileW)GetProcAddress(hKernel32, "DeleteFileW");
		if (!realDeleteFileW) {
			OutputDebugString(L"realDeleteFileW Error\n");
			break;
		}

		realCreateFileW = (ptrCreateFileW)GetProcAddress(hKernel32, "CreateFileW");
		if (!realCreateFileW) {
			OutputDebugString(L"realCreateFileW Error\n");
			break;
		}

		realCreateFileA = (ptrCreateFileA)GetProcAddress(hKernel32, "CreateFileA");
		if (!realCreateFileA) {
			OutputDebugString(L"realCreateFileA Error\n");
			break;
		}


		realMessageBoxW = (ptrMessageBoxW)GetProcAddress(hUser32, "MessageBoxW");
		if (!realMessageBoxW) {
			OutputDebugString(L"realMessageBoxW Error\n");
			break;
		}

		retval = TRUE;

		OutputDebugString(L"PrepareRealApiEntry successful.\n");
	} while (0);

	return retval;
}






void InstallHookFunction(void* OriginFunction, void* HookFunction)
{
	TRACED_HOOK_HANDLE handle = new HOOK_TRACE_INFO();
	HookHandleMap.insert(std::pair<void*, TRACED_HOOK_HANDLE>(OriginFunction, handle));
	LhInstallHook(OriginFunction, HookFunction, NULL, handle);
}


void DoHook()
{
	OutputDebugString(L"DoHook.\n");
	InstallHookFunction(realDeleteFileW, MyDeleteFileW);
	InstallHookFunction(realMessageBoxW, MyMessageBoxW);
	EnableAllHookFunction();
}

void EnableAllHookFunction()
{
	for each (std::pair<void*, TRACED_HOOK_HANDLE> element in HookHandleMap)
	{
		LhSetExclusiveACL(&ThreadList, 1, element.second);
	}
}

void DisableHookFunction(void* OriginFunction)
{
	HookHandleMap.erase(OriginFunction);
	for each (std::pair<void*, TRACED_HOOK_HANDLE> element in HookHandleMap)
	{
		LhSetExclusiveACL(&ThreadList, 1, element.second);
	}
}

void UninstallAllHookFunction()
{
	LhUninstallAllHooks();
}