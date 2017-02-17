// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "HookDll.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("PROCESS_ATTACH\n");
		InstallHookFunction(MessageBoxW, MessageBoxWHook);
		InstallHookFunction(TextOutW, TextOutWHook);
		EnableAllHookFunction();
		break;
	case DLL_PROCESS_DETACH:
		printf("PROCESS_DETACH\n");
		UninstallAllHookFunction();
		break;
	}
	return TRUE;
}

