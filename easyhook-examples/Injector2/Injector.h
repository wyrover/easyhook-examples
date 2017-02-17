#pragma once

// StealthLib
#include "StringWrap.h"

// Windows API
#include <Windows.h>

// C++ Standard Library
#include <string>

// Class to manage DLL injection into a remote process
class Injector
{
public:
	// Get singleton
	static Injector* Get();

	// Inject library
	void InjectLib(DWORD ProcID, const std::wstring& Path);
	void InjectLib(DWORD ProcID, const std::string& Path);

	// Eject library
	void EjectLib(DWORD ProcID, const std::wstring& Path);
	void EjectLib(DWORD ProcID, const std::string& Path);

	// Get fully qualified path from module name
	std::tstring GetPath(const std::tstring& ModuleName);

	// Get process id by name
	DWORD GetProcessIdByName(const std::tstring& Name);
	// Get proces id by window
	DWORD GetProcessIdByWindow(const std::tstring& Name);

	// Get SeDebugPrivilege. Needed to inject properly.
	void GetSeDebugPrivilege();

protected:
	// Enforce singleton
	Injector();
	~Injector();
	Injector(const Injector&);
	Injector& operator= (const Injector&);
private:
	// Singleton
	static Injector* m_pSingleton;
};
