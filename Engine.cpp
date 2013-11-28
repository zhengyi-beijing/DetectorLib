// Engine.cpp : CEngine 的实现

#include "stdafx.h"
#include "Engine.h"


// CEngine



STDMETHODIMP CEngine::Start(void)
{
	// TODO: 在此添加实现代码 
	m_Engine->Start();
	return S_OK;
}


STDMETHODIMP CEngine::Stop(void)
{
	// TODO: 在此添加实现代码
	m_Engine->Stop();
	return S_OK;
}


STDMETHODIMP CEngine::get_ChannelHandle(ULONG* pVal)
{
	// TODO: 在此添加实现代码
	*pVal = (ULONG) m_Engine->GetChannel(); 
	return S_OK;
}


STDMETHODIMP CEngine::put_ChannelHandle(ULONG newVal)
{
	// TODO: 在此添加实现代码
	m_Engine->SetChannel((ChannelIF*) newVal);
	return S_OK;
}


STDMETHODIMP CEngine::get_ObjectHandle(ULONG* pVal)
{
	// TODO: 在此添加实现代码
	*pVal = (ULONG) m_Engine;
	return S_OK;
}

STDMETHODIMP_(void) CEngine::OnDataReady(BYTE* buf, int size)
{
	// TODO: Add your implementation code here
}

void CEngine::OnNotify ( BYTE* buf, int size)
{
	Fire_OnDataReady(buf, size);
}

void CEngine::OnConnect () 
{
	Fire_OnConnect ();
}
void CEngine::OnDisConnect ()
{
   Fire_OnDisconnect ();
}
