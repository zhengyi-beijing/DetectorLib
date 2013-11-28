#pragma once

class CmdConsumerIF
{
public:
	CmdConsumerIF(void);
public:
	virtual ~CmdConsumerIF(void);
	void On_Cmd (BYTE CmdID, BYTE );
};
