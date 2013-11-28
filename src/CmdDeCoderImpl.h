#pragma once
#include "decoder.h"
#include "ICmdConsumer.h"
class CmdDeCoderImpl :
	public DeCoder
{
	ICmdConsumer* m_pConsumer;
public:
	CmdDeCoderImpl(void);
public:
	virtual ~CmdDeCoderImpl(void);
	void Process();
	void SetCmdConsumer (ICmdConsumer* consumer);
	ICmdConsumer* GetCmdConsumer();


};
