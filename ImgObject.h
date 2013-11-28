// ImgObject.h : CImgObject 的声明

#pragma once
#include "resource.h"       // 主符号



#include "DetectorLib_i.h"
#include "_IImgObjectEvents_CP.h"
#include "src/ImgObjectImpl.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CImgObject

class ATL_NO_VTABLE CImgObject :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CImgObject, &CLSID_ImgObject>,
	public IConnectionPointContainerImpl<CImgObject>,
	public CProxy_IImgObjectEvents<CImgObject>,
	public IDispatchImpl<IImgObject, &IID_IImgObject, &LIBID_DetectorLibLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	ImgObjectImpl* m_pImgObject;

public:
	CImgObject()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IMGOBJECT)


BEGIN_COM_MAP(CImgObject)
	COM_INTERFACE_ENTRY(IImgObject)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CImgObject)
	CONNECTION_POINT_ENTRY(__uuidof(_IImgObjectEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()
public:
	void SetImgObject (ImgObjectImpl* pImg)
	{
		m_pImgObject = pImg;

	};
	HRESULT FinalConstruct()
	{
		m_pImgObject = NULL;
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(get_Width)(ULONG* pVal);
	STDMETHOD(get_Height)(ULONG* pVal);
	STDMETHOD(get_Deepth)(ULONG* pVal);
	STDMETHOD(get_Pixel)(ULONG x, ULONG y, ULONG* pVal);
	STDMETHOD(put_Pixel)(ULONG x, ULONG y, ULONG newVal);
	STDMETHOD(get_ImageLineAddress)(ULONG line, ULONG* pVal);
};

OBJECT_ENTRY_AUTO(__uuidof(ImgObject), CImgObject)
