#pragma once
#include "channelstatusif.h"

class ChannelStatus :
	public ChannelStatusIF
{
public:
	ChannelStatus(void);
	int GetOpened();
	int GetBandWidth();
	int GetBytesSend();
public:
	void PutOpened (long bOpen);
	void PutBandWith (long value);
	void PutBytesSend (long value);
public:
	virtual ~ChannelStatus(void);
private:
	long m_BytesSend;
	long m_BandWidth;
	long m_Opened;
};
