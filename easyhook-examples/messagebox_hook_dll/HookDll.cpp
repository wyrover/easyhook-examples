// HookDll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "easyhook.h"
#include "HookDll.h"
#include <map>

std::map<void*, TRACED_HOOK_HANDLE> HookHandleMap;
ULONG ThreadList = 0;


void InstallHookFunction(void* OriginFunction, void* HookFunction)
{
	TRACED_HOOK_HANDLE handle = new HOOK_TRACE_INFO();
	HookHandleMap.insert(std::pair<void*,TRACED_HOOK_HANDLE>(OriginFunction, handle));
	LhInstallHook(OriginFunction, HookFunction, NULL, handle);
}

void UninstallAllHookFunction()
{
	LhUninstallAllHooks();
}

void EnableAllHookFunction()
{
	for each (std::pair<void*,TRACED_HOOK_HANDLE> element in HookHandleMap)
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


BOOL  WINAPI TextOutWHook(_In_ HDC hdc, _In_ int x, _In_ int y, _In_reads_(c) LPCWSTR lpString, _In_ int c)
{
	Sleep(1000);
	MessageBoxW(NULL,lpString,L"From TextOutW",MB_OK);
	return TextOutW(hdc, x, y, lpString, c);
}

int WINAPI MessageBoxWHook(_In_opt_ HWND hWnd, _In_opt_ LPCWSTR lpText, _In_opt_ LPCWSTR lpCaption, _In_ UINT uType)
{
	return MessageBoxW(hWnd, L"Modified Content", lpCaption, uType);
}


