// ImgController.h : CImgController 的声明

#pragma once
#include "resource.h"       // 主符号
#include "DetectorLib_i.h"
#include "_IImgControllerEvents_CP.h"
#include "src/ImgControllerImpl.h"
#include "src/ImgDeCoderImpl.h"
#include "ImgObject.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CImgController

class ATL_NO_VTABLE CImgController :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CImgController, &CLSID_ImgController>,
	public IConnectionPointContainerImpl<CImgController>,
	public CProxy_IImgControllerEvents<CImgController>,
	public IDispatchImpl<IImgController, &IID_IImgController, &LIBID_DetectorLibLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
private:
	ImgDeCoderImpl* m_pImgDecoder;
	ImgControllerImpl m_ImgController;
	CImgObject* m_pImgObject;

public:
	CImgController():m_ImgController(this)
	{
		m_pImgObject = NULL;
		m_pImgDecoder  = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_IMGCONTROLLER)


BEGIN_COM_MAP(CImgController)
	COM_INTERFACE_ENTRY(IImgController)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CImgController)
	CONNECTION_POINT_ENTRY(__uuidof(_IImgControllerEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{

		return S_OK;
	}

	void FinalRelease()
	{
		m_pImgObject->Release();
	}

	void FrameReady () 
	{
		Fire_FrameReady();
	};
};

OBJECT_ENTRY_AUTO(__uuidof(ImgController), CImgController)
