#include "StdAfx.h"
#include "VDCmd.h"

VDCmd::VDCmd(BYTE cmd_code,int param_count, WORD* param)
{
	m_Code = cmd_code;
	m_Len = param_count*2 + 2;
	m_pBuf = new BYTE[m_Len ];

	memcpy (m_pBuf+2, param, m_Len-2);
}

VDCmd::~VDCmd(void)
{

	delete [] m_pBuf;
}

BYTE* VDCmd::ConvertToBufFmt (BYTE cmd_id)
{
	m_pBuf[0] = cmd_id;
	m_pBuf[1] = m_Code;
	return m_pBuf;
}

int VDCmd::BufLen()
{
	return m_Len;
}
