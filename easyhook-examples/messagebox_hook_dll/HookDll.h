#pragma once

#include <stdio.h>



void InstallHookFunction(void* OriginFunction, void* HookFunction);
void UninstallAllHookFunction();

void EnableAllHookFunction();
void DisableHookFunction(void* OriginFunction);

BOOL  WINAPI TextOutWHook(_In_ HDC hdc, _In_ int x, _In_ int y, _In_reads_(c) LPCWSTR lpString, _In_ int c);
int WINAPI MessageBoxWHook(_In_opt_ HWND hWnd,	_In_opt_ LPCWSTR lpText,_In_opt_ LPCWSTR lpCaption,	_In_ UINT uType);