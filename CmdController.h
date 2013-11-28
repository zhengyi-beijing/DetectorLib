// CmdController.h : CCmdController 的声明

#pragma once
#include "resource.h"       // 主符号



#include "DetectorLib_i.h"
#include "src/CmdControllerImpl.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CCmdController

class ATL_NO_VTABLE CCmdController :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCmdController, &CLSID_CmdController>,
	public IDispatchImpl<ICmdController, &IID_ICmdController, &LIBID_DetectorLibLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	CmdControllerImpl m_CmdController;
public:
	CCmdController()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CMDCONTROLLER)


BEGIN_COM_MAP(CCmdController)
	COM_INTERFACE_ENTRY(ICmdController)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

public:
	STDMETHOD(get_CoderHandle)(ULONG* pVal);
public:
	STDMETHOD(put_CoderHandle)(ULONG newVal);
public:
	STDMETHOD(get_IntegrationTime)(long* pVal);//ST
public:
	STDMETHOD(put_IntegrationTime)(long newVal);
public:
	STDMETHOD(get_FrameOut)(LONG* pVal);//SF
public:
	STDMETHOD(put_FrameOut)(LONG newVal);

};

OBJECT_ENTRY_AUTO(__uuidof(CmdController), CCmdController)
