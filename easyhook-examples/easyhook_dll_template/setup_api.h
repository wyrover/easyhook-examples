#pragma once

#include <Windows.h>
#include <SetupAPI.h>

BOOL WINAPI MySetupDiSetClassInstallParamsA(
	__in HDEVINFO DeviceInfoSet,
	__in_opt PSP_DEVINFO_DATA DeviceInfoData,
	__in_bcount_opt(ClassInstallParamsSize) PSP_CLASSINSTALL_HEADER ClassInstallParams,
	__in DWORD ClassInstallParamsSize
);

typedef BOOL (WINAPI *ptrSetupDiSetClassInstallParamsA)(
	__in HDEVINFO DeviceInfoSet,
	__in_opt PSP_DEVINFO_DATA DeviceInfoData,
	__in_bcount_opt(ClassInstallParamsSize) PSP_CLASSINSTALL_HEADER ClassInstallParams,
	__in DWORD ClassInstallParamsSize
);



BOOL WINAPI MySetupDiSetClassInstallParamsW(
	__in HDEVINFO DeviceInfoSet,
	__in_opt PSP_DEVINFO_DATA DeviceInfoData,
	__in_bcount_opt(ClassInstallParamsSize) PSP_CLASSINSTALL_HEADER ClassInstallParams,
	__in DWORD ClassInstallParamsSize
);
typedef BOOL(WINAPI *ptrSetupDiSetClassInstallParamsW)(
	__in HDEVINFO DeviceInfoSet,
	__in_opt PSP_DEVINFO_DATA DeviceInfoData,
	__in_bcount_opt(ClassInstallParamsSize) PSP_CLASSINSTALL_HEADER ClassInstallParams,
	__in DWORD ClassInstallParamsSize
);


BOOL
WINAPI
MySetupDiDestroyDeviceInfoList(
	__in HDEVINFO DeviceInfoSet
);

typedef BOOL(WINAPI *ptrSetupDiDestroyDeviceInfoList)(
	__in HDEVINFO DeviceInfoSet
);
