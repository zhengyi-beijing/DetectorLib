// ImgCoder.h : CImgCoder 的声明

#pragma once
#include "resource.h"       // 主符号



#include "DetectorLib_i.h"
#include "src/ITPDeCoderImpl.h"
#include "src/ImgDeCoderImpl.h"
#include "src/EngineImpl.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CImgCoder

class ATL_NO_VTABLE CImgCoder :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CImgCoder, &CLSID_ImgCoder>,
	public IDispatchImpl<IImgCoder, &IID_IImgCoder, &LIBID_DetectorLibLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	ImgDeCoderImpl* m_pImgDeCoder;
	ITPDeCoderImpl* m_pITPDeCoder;
	EngineImpl* m_EngineCoder;
public:
	CImgCoder()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IMGCODER)


BEGIN_COM_MAP(CImgCoder)
	COM_INTERFACE_ENTRY(IImgCoder)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		m_pImgDeCoder = new ImgDeCoderImpl;
		m_pITPDeCoder = new ITPDeCoderImpl;
		m_pITPDeCoder->SetNextDeCoder(m_pImgDeCoder);
		return S_OK;
	}

	void FinalRelease()
	{
		if(m_pImgDeCoder)
			delete m_pImgDeCoder;
		if(m_pITPDeCoder)
			delete m_pITPDeCoder;
	}

public:
	STDMETHOD(get_ObjectHandle)(ULONG* pVal);
public:
	STDMETHOD(get_EngineHandle)(ULONG* pVal);
public:
	STDMETHOD(put_EngineHandle)(ULONG newVal);


};

OBJECT_ENTRY_AUTO(__uuidof(ImgCoder), CImgCoder)
