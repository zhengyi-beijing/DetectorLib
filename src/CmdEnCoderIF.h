#pragma once
#include "ChannelIF.h"
class CmdEnCoderIF
{
public:
	CmdEnCoderIF(void);
public:
	virtual ~CmdEnCoderIF(void);
	virtual void AddChannel (ChannelIF* channel) = 0;
	virtual void RemoveChannel (ChannelIF* channel) = 0;
	void Encode (BYTE* src, int size);
};
