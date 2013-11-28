#include "StdAfx.h"
#include "ChannelStatus.h"


ChannelStatus::ChannelStatus(void)
{
	m_BytesSend = 0;
	m_BandWidth = 0;
	m_Opened = 0;//0 is false and the status is closed
}

ChannelStatus::~ChannelStatus(void)
{
}

int ChannelStatus::GetOpened()
{
	return m_Opened;
}

int ChannelStatus::GetBandWidth()
{
	return m_BandWidth;
}

int ChannelStatus::GetBytesSend()
{
	return m_BytesSend;
}

void ChannelStatus::PutOpened (long bOpen)
{
	m_Opened = bOpen;
}

void ChannelStatus::PutBandWith (long value)
{
	m_BandWidth = value;
}

void ChannelStatus::PutBytesSend (long value)
{
	m_BytesSend = value;
}