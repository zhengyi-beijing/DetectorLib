#include "StdAfx.h"
#include "CmdDeCoderImpl.h"

CmdDeCoderImpl::CmdDeCoderImpl(void)
{
}

CmdDeCoderImpl::~CmdDeCoderImpl(void)
{
}

void CmdDeCoderImpl::SetCmdConsumer(ICmdConsumer* consumer)
{
	m_pConsumer = consumer;
}
ICmdConsumer* CmdDeCoderImpl::GetCmdConsumer()
{
	return m_pConsumer;
}
void CmdDeCoderImpl::Process()
{
	//Get Cmd ID
	//Get Return Value
	//Set Paramenter buffer
	ATLTRACE ("Decoder process ");
	//0-cmd id
	//1-cmd_opcode
	//2-return value
	//3=0
	//4,5 - first param

	//count = (m_End - 4)/2 //total bytes - cmd_id opcode and rt value len ,in words
	BYTE cmdid = m_Buf[0];
	BYTE rt = m_Buf[2];
	WORD* param = (WORD*)(m_Buf+4) ;
	int count = (m_End - 4)/2 ;
	m_pConsumer->On_CmdReady (cmdid, rt, param, count);
	m_End = 0;
}