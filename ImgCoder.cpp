// ImgCoder.cpp : CImgCoder µÄÊµÏÖ

#include "stdafx.h"
#include "ImgCoder.h"


// CImgCoder

STDMETHODIMP CImgCoder::get_ObjectHandle(ULONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = (long) m_pImgDeCoder;
	return S_OK;
}

STDMETHODIMP CImgCoder::get_EngineHandle(ULONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = (long)m_EngineCoder;

	return S_OK;
}

STDMETHODIMP CImgCoder::put_EngineHandle(ULONG newVal)
{
	// TODO: Add your implementation code here
	EngineImpl* engine = (EngineImpl*) newVal;
	engine->AddConsumer(m_pITPDeCoder);
	return S_OK;
}