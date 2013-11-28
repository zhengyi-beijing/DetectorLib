#pragma once
#include "EngineIF.h"
#include "CmdDeCoderImpl.h"
#include "ITPDeCoderImpl.h"
#include "CmdEnCoderImpl.h"


class CmdCoderImpl
{
private:
	ITPDeCoderImpl* m_ITPDeCoder;
	CmdDeCoderImpl* m_CmdDeCoder;
	CmdEnCoderImpl* m_CmdEnCoder;
	EngineIF* m_Engine;


public:
	void SetEngineHandle (EngineIF* engine);
	EngineIF* GetEngineHandle ();

	CmdDeCoderImpl* GetCmdDeCoder ();
	CmdEnCoderImpl* GetCmdEnCoder ();

	
	CmdCoderImpl(void);
public:
	~CmdCoderImpl(void);
};
