// ImgDisplay.cpp : CImgDisplay µÄÊµÏÖ
#include "stdafx.h"
#include "ImgDisplay.h"


// CImgDisplay


// CImgDisplay
LRESULT CImgDisplay::OnRefresh(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	if(m_bOpened)
	{
		m_pImgDisplay->Refresh();
	}
	return 0;
}
STDMETHODIMP CImgDisplay::Open(ULONG width, ULONG height)
{
	// TODO: Add your implementation code here
	m_pImgDisplay->Open(width,height,1);
	m_bOpened = m_pImgDisplay->IsOpened();
	
	return S_OK;
}

STDMETHODIMP CImgDisplay::Close(void)
{
	// TODO: Add your implementation code here
	m_pImgDisplay->Close();
	m_bOpened =FALSE;
	return S_OK;
}

STDMETHODIMP CImgDisplay::get_ImgHandle(ULONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = (long)m_pImgDisplay->GetImgSrc();
	return S_OK;
}

STDMETHODIMP CImgDisplay::put_ImgHandle(ULONG newVal)
{
	// TODO: Add your implementation code here
	m_pImgDisplay->SetImgSrc((ImgControllerImpl*)newVal);
	return S_OK;
}

LRESULT CImgDisplay::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default
	RECT rect;
	m_pImgDisplay->SetWnd (m_hWnd);
	GetClientRect(&rect);
	m_pImgDisplay->SetRect (rect);
	return 0;
}

LRESULT CImgDisplay::OnSize(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default
	RECT rect;
	GetClientRect(&rect);
	m_pImgDisplay->SetRect (rect);
	return 0;
}

LRESULT CImgDisplay::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: Add your message handler code here and/or call default
	if(m_pImgDisplay)
	{
		m_pImgDisplay->Close();
	}
	
	return 0;
}

STDMETHODIMP CImgDisplay::get_MapStart(ULONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_pImgDisplay->GetMapStart();
	return S_OK;
}

STDMETHODIMP CImgDisplay::put_MapStart(ULONG newVal)
{
	// TODO: Add your implementation code here
	m_pImgDisplay->SetMapStart(newVal);
	return S_OK;
}

STDMETHODIMP CImgDisplay::get_MapEnd(ULONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_pImgDisplay->GetMapEnd();
	return S_OK;
}

STDMETHODIMP CImgDisplay::put_MapEnd(ULONG newVal)
{
	// TODO: Add your implementation code here
	m_pImgDisplay->SetMapEnd (newVal);
	return S_OK;
}
