// CmdController.cpp : CCmdController µÄÊµÏÖ

#include "stdafx.h"
#include "CmdController.h"


// CCmdController
STDMETHODIMP CCmdController::get_CoderHandle(ULONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = (long) m_CmdController.GetCoder();
	return S_OK;
}

STDMETHODIMP CCmdController::put_CoderHandle(ULONG newVal)
{
	// TODO: Add your implementation code here
	m_CmdController.SetCoder((CmdCoderImpl*) newVal);
	return S_OK;
}

STDMETHODIMP CCmdController::get_IntegrationTime(long* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_CmdController.GetIntTime();
	return S_OK;
}

STDMETHODIMP CCmdController::put_IntegrationTime(long newVal)
{
	// TODO: Add your implementation code here
	m_CmdController.SetIntTime(newVal);
	return S_OK;
}

STDMETHODIMP CCmdController::get_FrameOut(LONG* pVal)
{
	// TODO: Add your implementation code here
	*pVal = m_CmdController.GetFrameOut();
	return S_OK;
}

STDMETHODIMP CCmdController::put_FrameOut(LONG newVal)
{
	// TODO: Add your implementation code here
	m_CmdController.SetFrameOut(newVal);
	return S_OK;
}


