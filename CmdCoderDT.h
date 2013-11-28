// CmdCoderDT.h : CCmdCoderDT 的声明

#pragma once
#include "resource.h"       // 主符号



#include "DetectorLib_i.h"
#include "_ICmdCoderDTEvents_CP.h"
#include "src/CmdCoderImpl.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CCmdCoderDT

class ATL_NO_VTABLE CCmdCoderDT :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCmdCoderDT, &CLSID_CmdCoderDT>,
	public IConnectionPointContainerImpl<CCmdCoderDT>,
	public CProxy_ICmdCoderDTEvents<CCmdCoderDT>,
	public IDispatchImpl<ICmdCoderDT, &IID_ICmdCoderDT, &LIBID_DetectorLibLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	CmdCoderImpl* m_pCmdCoder;

public:
	CCmdCoderDT()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CMDCODERDT)


BEGIN_COM_MAP(CCmdCoderDT)
	COM_INTERFACE_ENTRY(ICmdCoderDT)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CCmdCoderDT)
	CONNECTION_POINT_ENTRY(__uuidof(_ICmdCoderDTEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		m_pCmdCoder = new CmdCoderImpl;
		return S_OK;
	}

	void FinalRelease()
	{
		if (m_pCmdCoder)
			delete m_pCmdCoder;
	}

public:
	STDMETHOD(get_ObjectHandle)(ULONG* pVal);
public:
	STDMETHOD(get_EngineHandle)(ULONG* pVal);
public:
	STDMETHOD(put_EngineHandle)(ULONG newVal);
};


OBJECT_ENTRY_AUTO(__uuidof(CmdCoderDT), CCmdCoderDT)
