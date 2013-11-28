#pragma once

class ChannelStatusIF
{
public:
	ChannelStatusIF(void);
	virtual int GetOpened() = 0;
	virtual int GetBandWidth() = 0;
	virtual int GetBytesSend() = 0;
public:
	virtual ~ChannelStatusIF(void);
};
