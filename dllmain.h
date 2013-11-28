// dllmain.h : 模块类的声明。

class CDetectorLibModule : public ATL::CAtlDllModuleT< CDetectorLibModule >
{
public :
	DECLARE_LIBID(LIBID_DetectorLibLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_DETECTORLIB, "{8DF6F228-3EFF-4058-B15A-55425E406744}")
};

extern class CDetectorLibModule _AtlModule;
