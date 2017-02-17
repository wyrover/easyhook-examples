// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "real_api.h"

#include <string>

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved
                     )
{
   
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        OutputDebugString(L"DllMain::DLL_PROCESS_ATTACH\n");
        
       
        //// 准备好原始地址与目的地址
        BOOL retval = PrepareRealApiEntry();
        if (!retval) {
            OutputDebugString(L"PrepareRealApiEntry() Error\n");
            return FALSE;
        }

        //// 开始挂钩
        DoHook();
        break;
    }

    /*case DLL_THREAD_ATTACH: {
        OutputDebugString(L"DllMain::DLL_THREAD_ATTACH\n");
        break;
    }

    case DLL_THREAD_DETACH: {
        OutputDebugString(L"DllMain::DLL_THREAD_DETACH\n");
        break;
    }*/

    case DLL_PROCESS_DETACH: {
        OutputDebugString(L"DllMain::DLL_PROCESS_DETACH\n");        
        UninstallAllHookFunction();
        break;
    }
    }

    return TRUE;
}

