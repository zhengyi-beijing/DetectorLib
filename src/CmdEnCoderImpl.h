#pragma once
#include "ChannelIF.h"
class CmdEnCoderImpl
{
private:
	ChannelIF* m_pChannel;
public:
	CmdEnCoderImpl(void);
public:
	virtual ~CmdEnCoderImpl(void);
	void SetChannel (ChannelIF* channel);
	ChannelIF* GetChannel ();
	void Encode (BYTE* buf, int len);
};
