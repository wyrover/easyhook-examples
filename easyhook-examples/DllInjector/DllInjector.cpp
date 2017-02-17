// DllInjector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <tchar.h>
#include <TlHelp32.h>
#include <iostream>

/*
    Get the PID of a given process name, such as calc.exe
    Note: Do not specify a full path, such as C:\Windows\System32\calc.exe
*/
DWORD GetPidByName(LPTSTR name)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 ppe;
    ppe.dwSize = sizeof(PROCESSENTRY32);
    Process32First(hSnapshot, &ppe);
    DWORD dwReturnable = 0;

    do {
        if (_tcscmp(ppe.szExeFile, name) == 0) {
            dwReturnable = ppe.th32ProcessID;
            break;
        }
    } while (Process32Next(hSnapshot, &ppe));

    CloseHandle(hSnapshot);
    return dwReturnable;
}

#ifdef _DEBUG
void PrintDebugMessage(LPTSTR message)
{
    _tprintf(message);
    OutputDebugString(message);
}
#else
#define PrintDebugMessage(str)
#endif

int _tmain(int argc, _TCHAR* argv[])
{
    /* Specify our DLL that we are going to inject */
    char szPayloadDll[] = "D:\\Documents\\Code\\InjectableDLL\\Debug\\InjectableDll.dll";
    int dwPayloadPathLength = strlen(szPayloadDll) + 1;
    TCHAR buffer[1024];
    /* Get the PID of the target we want to inject into */
    DWORD dwTargetPid = GetPidByName(_T("TargetApplication.exe"));

    if (!dwTargetPid) {
        PrintDebugMessage(_T("Please start the target application.\n"));
        return -1;
    }

    /* Open our target process */
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, dwTargetPid);

    if (!hProcess) {
        PrintDebugMessage(_T("Couldn't get handle to process.\n"));
        RtlZeroMemory(buffer, 1024);
        _sntprintf(buffer, 1024, _T("Error: %d\n"), GetLastError());
        PrintDebugMessage(buffer);
        return -1;
    }

    /* Allocate some memory in our target process */
    LPVOID lpAddr = VirtualAllocEx(hProcess, 0, dwPayloadPathLength, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    if (!lpAddr) {
        PrintDebugMessage(_T("Couldn't do VirtualAllocEx.\n"));
        RtlZeroMemory(buffer, 1024);
        _sntprintf(buffer, 1024, _T("Error: %d\n"), GetLastError());
        PrintDebugMessage(buffer);
        return -1;
    }

    /* Write the path of our payload into the target DLL */
    DWORD dwBytesWritten = 0;
    BOOL bWritten = WriteProcessMemory(hProcess, lpAddr, szPayloadDll, dwPayloadPathLength, (SIZE_T *)&dwBytesWritten);

    if (!bWritten) {
        PrintDebugMessage(_T("WriteProcessMemory failed.\n"));
        RtlZeroMemory(buffer, 1024);
        _sntprintf(buffer, 1024, _T("Error: %d\n"), GetLastError());
        PrintDebugMessage(buffer);
        return -1;
    }

    /* Get an HMODULE for kernel32 */
    HMODULE hKernel32 = GetModuleHandle(_T("kernel32.dll"));

    if (!hKernel32) {
        PrintDebugMessage(_T("GetModuleHandle failed.\n"));
        RtlZeroMemory(buffer, 1024);
        _sntprintf(buffer, 1024, _T("Error: %d\n"), GetLastError());
        PrintDebugMessage(buffer);
        return -1;
    }

    /* Get a function pointer for LoadLibraryA */
    LPTHREAD_START_ROUTINE fpLoadLibrary = (LPTHREAD_START_ROUTINE)GetProcAddress(hKernel32, "LoadLibraryA");

    if (!fpLoadLibrary) {
        PrintDebugMessage(_T("GetProcAddress failed.\n"));
        RtlZeroMemory(buffer, 1024);
        _sntprintf(buffer, 1024, _T("Error: %d\n"), GetLastError());
        PrintDebugMessage(buffer);
        return -1;
    } else {
        RtlZeroMemory(buffer, 1024);
        _sntprintf(buffer, 1024, _T("fpLoadLibrary: %08X\n"), (int)fpLoadLibrary);
        PrintDebugMessage(buffer);
    }

    /* Create a remote thread in the target process. It will call LoadLibraryA with our DLL as an argument, thus loading our payload DLL */
    DWORD dwThreadId = 0;
    HANDLE hRemoteThread = CreateRemoteThread(hProcess, 0, 0, fpLoadLibrary, lpAddr, 0, &dwThreadId);

    if (!hRemoteThread) {
        PrintDebugMessage(_T("CreateRemoteThread failed.\n"));
        RtlZeroMemory(buffer, 1024);
        _sntprintf(buffer, 1024, _T("Error: %d\n"), GetLastError());
        PrintDebugMessage(buffer);
        return -1;
    }

    /* Wait for the remote thread to complete */
    WaitForSingleObject(hRemoteThread, INFINITE);
    /* Get the exit code from the remote thread */
    DWORD dwExitCode;
    GetExitCodeThread(hRemoteThread, &dwExitCode);
    /* Free the remote thread's handle */
    CloseHandle(hRemoteThread);
    /* Free up the our dll path was in */
    VirtualFreeEx(hProcess, lpAddr, dwPayloadPathLength, MEM_RELEASE);
    return 0;
}

