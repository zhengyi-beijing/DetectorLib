// Engine.h : CEngine 的声明

#pragma once
#include "resource.h"       // 
#include "DetectorLib_i.h"
#include "_IEngineEvents_CP.h"
#include "src/EngineIF.h"
#include "src/EngineImpl.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CEngine

class ATL_NO_VTABLE CEngine :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CEngine, &CLSID_Engine>,
	public IConnectionPointContainerImpl<CEngine>,
	public CProxy_IEngineEvents<CEngine>,
	public IDispatchImpl<IEngine, &IID_IEngine, &LIBID_DetectorLibLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public DataConsumerIF,
	public ConnectionStatusIF
{
private:
	EngineIF* m_Engine;
public:
	CEngine()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ENGINE)


BEGIN_COM_MAP(CEngine)
	COM_INTERFACE_ENTRY(IEngine)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CEngine)
	CONNECTION_POINT_ENTRY(__uuidof(_IEngineEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		m_Engine = new (EngineImpl);
		m_Engine->SetMonitor (this);
		m_Engine->AddConsumer(this);
		return S_OK;
	}

	void FinalRelease()
	{
		if (m_Engine)
		{
			delete m_Engine;
			m_Engine = NULL;
		}
	}

public:

	STDMETHOD(Start)(void);
	STDMETHOD(Stop)(void);
	STDMETHOD(get_ChannelHandle)(ULONG* pVal);
	STDMETHOD(put_ChannelHandle)(ULONG newVal);
	STDMETHOD(get_ObjectHandle)(ULONG* pVal);

	virtual void OnNotify (BYTE* buf, int size);
	virtual void OnConnect () ;
	virtual void OnDisConnect ();
	STDMETHOD_(void, OnDataReady)(BYTE* buf, int size);
};

OBJECT_ENTRY_AUTO(__uuidof(Engine), CEngine)
