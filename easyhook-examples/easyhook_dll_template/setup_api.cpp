#include "setup_api.h"
#include "real_api.h"


BOOL WINAPI MySetupDiSetClassInstallParamsA(
	__in HDEVINFO DeviceInfoSet,
	__in_opt PSP_DEVINFO_DATA DeviceInfoData,
	__in_bcount_opt(ClassInstallParamsSize) PSP_CLASSINSTALL_HEADER ClassInstallParams,
	__in DWORD ClassInstallParamsSize
)

{
	PSP_PROPCHANGE_PARAMS pPARA;
	pPARA = (PSP_PROPCHANGE_PARAMS)ClassInstallParams;

	

	return realSetupDiSetClassInstallParamsA(
		DeviceInfoSet,
		DeviceInfoData,
		(PSP_CLASSINSTALL_HEADER)ClassInstallParams,
		ClassInstallParamsSize
	);

}

BOOL WINAPI MySetupDiSetClassInstallParamsW(
	__in HDEVINFO DeviceInfoSet,
	__in_opt PSP_DEVINFO_DATA DeviceInfoData,
	__in_bcount_opt(ClassInstallParamsSize) PSP_CLASSINSTALL_HEADER ClassInstallParams,
	__in DWORD ClassInstallParamsSize
)

{
	PSP_PROPCHANGE_PARAMS pPARA;
	SP_PROPCHANGE_PARAMS PARA;
	CHAR word[50] = { 0 };

	pPARA = (PSP_PROPCHANGE_PARAMS)ClassInstallParams;
	memcpy(&PARA, pPARA, sizeof(PARA));

	if ((pPARA->StateChange == DICS_ENABLE))
	{

		return FALSE;
	}
	
	return realSetupDiSetClassInstallParamsW(
		DeviceInfoSet,
		DeviceInfoData,
		(PSP_CLASSINSTALL_HEADER)ClassInstallParams,
		ClassInstallParamsSize
	);

}

BOOL
WINAPI
MySetupDiDestroyDeviceInfoList(
	__in HDEVINFO DeviceInfoSet
)
{
	return realSetupDiDestroyDeviceInfoList(DeviceInfoSet);
}