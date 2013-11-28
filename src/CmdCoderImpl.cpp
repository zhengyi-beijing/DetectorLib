#include "StdAfx.h"
#include "CmdCoderImpl.h"


CmdCoderImpl::CmdCoderImpl(void)
{
	m_CmdDeCoder = new CmdDeCoderImpl;
	m_ITPDeCoder = new ITPDeCoderImpl;
	m_ITPDeCoder->SetNextDeCoder(m_CmdDeCoder);
	m_CmdEnCoder = new CmdEnCoderImpl;
	m_Engine = NULL;
}

CmdCoderImpl::~CmdCoderImpl(void)
{
	delete m_CmdDeCoder;
	delete m_CmdEnCoder;
	delete m_ITPDeCoder;
}

void CmdCoderImpl::SetEngineHandle (EngineIF* engine)
{
	if (m_Engine)
	{
		m_Engine->RemoveConsumer (m_ITPDeCoder);
		m_CmdEnCoder->SetChannel (NULL);
	}
	
	m_Engine = engine;
	if (m_Engine)
	{
		m_Engine->AddConsumer (m_ITPDeCoder);

		m_CmdEnCoder->SetChannel(m_Engine->GetChannel());
	}

}

EngineIF* CmdCoderImpl::GetEngineHandle ()
{
	return m_Engine;
}

CmdDeCoderImpl* CmdCoderImpl::GetCmdDeCoder ()
{
	return m_CmdDeCoder;
}

CmdEnCoderImpl* CmdCoderImpl::GetCmdEnCoder ()
{
	return m_CmdEnCoder;
}