#pragma once

class ICmdConsumer
{
public:
	ICmdConsumer(void);
public:
	virtual ~ICmdConsumer(void);
	virtual void On_CmdReady (BYTE CmdID, BYTE RT, WORD* param, int count) = 0;
};
