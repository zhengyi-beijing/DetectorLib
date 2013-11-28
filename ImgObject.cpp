// ImgObject.cpp : CImgObject 的实现

#include "stdafx.h"
#include "ImgObject.h"


// CImgObject



STDMETHODIMP CImgObject::get_Width(ULONG* pVal)
{
	// TODO: 在此添加实现代码
	if (m_pImgObject)
	{
		*pVal = m_pImgObject->GetWidth();
	}
	else
		*pVal = 0;
	return S_OK;
}


STDMETHODIMP CImgObject::get_Height(ULONG* pVal)
{
	// TODO: 在此添加实现代码
	if (m_pImgObject)
	{
		*pVal = m_pImgObject->GetHeight();
	} 
	else
	{
		*pVal = 0;
	}
	return S_OK;
}


STDMETHODIMP CImgObject::get_Deepth(ULONG* pVal)
{
	// TODO: 在此添加实现代码
	if (m_pImgObject)
	{
		*pVal = m_pImgObject->GetDepth();
	}
	else
	{
		*pVal = 0;
	}
	return S_OK;
}


STDMETHODIMP CImgObject::get_Pixel(ULONG x, ULONG y, ULONG* pVal)
{
	// TODO: 在此添加实现代码
	if (m_pImgObject)
	{
		*pVal = m_pImgObject->GetPixel(x,y);
	} 
	return S_OK;
}


STDMETHODIMP CImgObject::put_Pixel(ULONG x, ULONG y, ULONG newVal)
{
	// TODO: 在此添加实现代码
	if (m_pImgObject)
	{
		m_pImgObject->PutPixel(x, y, newVal);
	} 
	return S_OK;
}


STDMETHODIMP CImgObject::get_ImageLineAddress(ULONG line, ULONG* pVal)
{
	// TODO: 在此添加实现代码
	if (m_pImgObject)
	{
		*pVal = m_pImgObject->GetImageLineAddress(line);
	} 
	else
	{
		*pVal = 0;
	}

	return S_OK;
}
