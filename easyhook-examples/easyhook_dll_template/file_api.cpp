
#include "file_api.h"
#include "real_api.h"


BOOL WINAPI MySetFileTime(_In_ HANDLE hFile, _In_opt_ CONST FILETIME * lpCreationTime, _In_opt_ CONST FILETIME * lpLastAccessTime, _In_opt_ CONST FILETIME * lpLastWriteTime) 
{	
	return (realSetFileTime)(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime);
}


BOOL WINAPI MyDeleteFileW(_In_ LPCWSTR lpFileName) 
{
	OutputDebugString(L"MyDeleteFileW\n");
	::MessageBoxW(NULL, lpFileName, lpFileName, MB_OK);
	return (realDeleteFileW)(lpFileName);
}


BOOL WINAPI MyCopyFileW(_In_ LPCWSTR lpExistingFileName, _In_ LPCWSTR lpNewFileName, _In_ BOOL bFailIfExists) 
{	
	return (realCopyFileW)(lpExistingFileName, lpNewFileName, bFailIfExists);
}

BOOL WINAPI MyMoveFileW(_In_ LPCWSTR lpExistingFileName, _In_ LPCWSTR lpNewFileName) 
{	
	return (realMoveFileW)(lpExistingFileName, lpNewFileName);
}



HANDLE WINAPI MyCreateFileW(
	__in     LPCWSTR lpFileName,
	__in     DWORD dwDesiredAccess,
	__in     DWORD dwShareMode,
	__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	__in     DWORD dwCreationDisposition,
	__in     DWORD dwFlagsAndAttributes,
	__in_opt HANDLE hTemplateFile
)
{
	
	return (realCreateFileW)(lpFileName, dwDesiredAccess, dwShareMode,
		lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);

}

//ÎÄ¼þAPI
HANDLE WINAPI MyCreateFileA(
	__in     LPCSTR lpFileName,
	__in     DWORD dwDesiredAccess,
	__in     DWORD dwShareMode,
	__in_opt LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	__in     DWORD dwCreationDisposition,
	__in     DWORD dwFlagsAndAttributes,
	__in_opt HANDLE hTemplateFile
)
{

	return (realCreateFileA)(lpFileName, dwDesiredAccess, dwShareMode,
		lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

int WINAPI MyMessageBoxW(
	__in_opt HWND hWnd,
	__in_opt LPCWSTR lpText,
	__in_opt LPCWSTR lpCaption,
	__in UINT uType)
{
	return (realMessageBoxW)(hWnd, L"dddddddddddddddd", lpCaption, uType);
}