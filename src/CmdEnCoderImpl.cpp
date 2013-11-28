#include "StdAfx.h"
#include "CmdEnCoderImpl.h"

CmdEnCoderImpl::CmdEnCoderImpl(void)
{
}

CmdEnCoderImpl::~CmdEnCoderImpl(void)
{
}

void CmdEnCoderImpl::SetChannel (ChannelIF* channel)
{
	m_pChannel = channel;
}

ChannelIF* CmdEnCoderImpl::GetChannel ()
{
	return m_pChannel;
}

void  CmdEnCoderImpl::Encode (BYTE* buf, int len)
{
	if (m_pChannel)
	{
		ATLTRACE ("Write %d bytes\n", len);
		m_pChannel->Write(buf, len);
	}
}


