#pragma once

#include <Windows.h>

BOOL WINAPI MySetFileTime(_In_ HANDLE hFile, _In_opt_ CONST FILETIME * lpCreationTime, _In_opt_ CONST FILETIME * lpLastAccessTime, _In_opt_ CONST FILETIME * lpLastWriteTime);
typedef BOOL(WINAPI *ptrSetFileTime)(_In_ HANDLE hFile, _In_opt_ CONST FILETIME * lpCreationTime, _In_opt_ CONST FILETIME * lpLastAccessTime, _In_opt_ CONST FILETIME * lpLastWriteTime);

BOOL WINAPI MySetFileValidData(_In_ HANDLE hFile, _In_ LONGLONG ValidDataLength);
typedef BOOL(WINAPI *ptrSetFileValidData)(_In_ HANDLE hFile, _In_ LONGLONG ValidDataLength);

BOOL WINAPI MySetEndOfFile(_In_ HANDLE hFile);
typedef BOOL(WINAPI *ptrSetEndOfFile)(_In_ HANDLE hFile);

BOOL WINAPI MyCreateHardLinkW(_In_ LPCWSTR lpFileName, _In_ LPCWSTR lpExistingFileName, _Reserved_ LPSECURITY_ATTRIBUTES lpSecurityAttributes);
typedef BOOL(WINAPI *ptrCreateHardLinkW)(_In_ LPCWSTR lpFileName, _In_ LPCWSTR lpExistingFileName, _Reserved_ LPSECURITY_ATTRIBUTES lpSecurityAttributes);

BOOL WINAPI MySetFileAttributesW(_In_ LPCWSTR lpFileName, _In_ DWORD dwFileAttributes);
typedef BOOL(WINAPI *ptrSetFileAttributesW)(_In_ LPCWSTR lpFileName, _In_ DWORD dwFileAttributes);

BOOL WINAPI MyFindNextFileW(_In_ HANDLE hFindFile, _Out_ LPWIN32_FIND_DATAW lpFindFileData);
typedef BOOL(WINAPI *ptrFindNextFileW)(_In_ HANDLE hFindFile, _Out_ LPWIN32_FIND_DATAW lpFindFileData);

HANDLE WINAPI MyFindFirstFileW(_In_ LPCWSTR lpFileName, _Out_ LPWIN32_FIND_DATAW lpFindFileData);
typedef HANDLE(WINAPI *ptrFindFirstFileW)(_In_ LPCWSTR lpFileName, _Out_ LPWIN32_FIND_DATAW lpFindFileData);

BOOL WINAPI MyDeleteFileW(_In_ LPCWSTR lpFileName);
typedef BOOL(WINAPI *ptrDeleteFileW)(_In_ LPCWSTR lpFileName);

BOOL WINAPI MyCopyFileW(_In_ LPCWSTR lpExistingFileName, _In_ LPCWSTR lpNewFileName, _In_ BOOL bFailIfExists);
typedef BOOL(WINAPI *ptrCopyFileW)(_In_ LPCWSTR lpExistingFileName, _In_ LPCWSTR lpNewFileName, _In_ BOOL bFailIfExists);


BOOL WINAPI MyMoveFileW(
	_In_ LPCWSTR lpExistingFileName,
	_In_ LPCWSTR lpNewFileName
);

typedef BOOL(WINAPI *ptrMoveFileW)(
	_In_ LPCWSTR lpExistingFileName,
	_In_ LPCWSTR lpNewFileName
	);

HANDLE WINAPI MyCreateFileW(
	__in     LPCWSTR lpFileName,
	__in     DWORD dwDesiredAccess,
	__in     DWORD dwShareMode,
	__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	__in     DWORD dwCreationDisposition,
	__in     DWORD dwFlagsAndAttributes,
	__in_opt HANDLE hTemplateFile
);
typedef HANDLE(WINAPI *ptrCreateFileW)(
	__in     LPCWSTR lpFileName,
	__in     DWORD dwDesiredAccess,
	__in     DWORD dwShareMode,
	__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	__in     DWORD dwCreationDisposition,
	__in     DWORD dwFlagsAndAttributes,
	__in_opt HANDLE hTemplateFile
	);


HANDLE WINAPI MyCreateFileA(
	__in     LPCSTR lpFileName,
	__in     DWORD dwDesiredAccess,
	__in     DWORD dwShareMode,
	__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	__in     DWORD dwCreationDisposition,
	__in     DWORD dwFlagsAndAttributes,
	__in_opt HANDLE hTemplateFile
);

typedef HANDLE(WINAPI *ptrCreateFileA)(
	__in     LPCSTR lpFileName,
	__in     DWORD dwDesiredAccess,
	__in     DWORD dwShareMode,
	__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	__in     DWORD dwCreationDisposition,
	__in     DWORD dwFlagsAndAttributes,
	__in_opt HANDLE hTemplateFile
	);

BOOL WINAPI MyReadFile(_In_        HANDLE       hFile,
	_Out_       LPVOID       lpBuffer,
	_In_        DWORD        nNumberOfBytesToRead,
	_Out_opt_   LPDWORD      lpNumberOfBytesRead,
	_Inout_opt_ LPOVERLAPPED lpOverlapped);

typedef BOOL(WINAPI *ptrReadFile)(_In_        HANDLE       hFile,
	_Out_       LPVOID       lpBuffer,
	_In_        DWORD        nNumberOfBytesToRead,
	_Out_opt_   LPDWORD      lpNumberOfBytesRead,
	_Inout_opt_ LPOVERLAPPED lpOverlapped);


HANDLE WINAPI MyCreateFileMappingW(
	HANDLE hFile,
	LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
	DWORD flProtect,
	DWORD dwMaximumSizeHigh,
	DWORD dwMaximumSizeLow,
	LPCWSTR lpName
);
typedef HANDLE(WINAPI *ptrCreateFileMappingW) (
	HANDLE hFile,
	LPSECURITY_ATTRIBUTES lpFileMappingAttributes,
	DWORD flProtect,
	DWORD dwMaximumSizeHigh,
	DWORD dwMaximumSizeLow,
	LPCWSTR lpName
	);

HANDLE WINAPI MyOpenFileMappingW(_In_ DWORD dwDesiredAccess, _In_ BOOL bInheritHandle, _In_ LPCWSTR lpName);
typedef HANDLE(WINAPI *ptrOpenFileMappingW)(_In_ DWORD dwDesiredAccess, _In_ BOOL bInheritHandle, _In_ LPCWSTR lpName);

HFILE WINAPI MyOpenFile(
	_In_  LPCSTR     lpFileName,
	_Out_ LPOFSTRUCT lpReOpenBuff,
	_In_  UINT       uStyle
);
typedef HFILE(WINAPI *ptrOpenFile)(
	_In_  LPCSTR     lpFileName,
	_Out_ LPOFSTRUCT lpReOpenBuff,
	_In_  UINT       uStyle
	);


int WINAPI MyMessageBoxW(
	__in_opt HWND hWnd,
	__in_opt LPCWSTR lpText,
	__in_opt LPCWSTR lpCaption,
	__in UINT uType);

typedef int(WINAPI *ptrMessageBoxW)(
	__in_opt HWND hWnd,
	__in_opt LPCWSTR lpText,
	__in_opt LPCWSTR lpCaption,
	__in UINT uType);

