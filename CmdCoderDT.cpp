// CmdCoderDT.cpp : CCmdCoderDT µÄÊµÏÖ

#include "stdafx.h"
#include "CmdCoderDT.h"


// CCmdCoderDT
// CCmdCoder

STDMETHODIMP CCmdCoderDT::get_ObjectHandle(ULONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = (long) m_pCmdCoder;
	return S_OK;
}

STDMETHODIMP CCmdCoderDT::get_EngineHandle(ULONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = (long) m_pCmdCoder->GetEngineHandle();
	return S_OK;
}

STDMETHODIMP CCmdCoderDT::put_EngineHandle(ULONG newVal)
{
	// TODO: Add your implementation code here
	m_pCmdCoder->SetEngineHandle((EngineIF*) newVal);
	return S_OK;
}

