#pragma once

class VDCmd
{
private:
	BYTE m_Code;
	BYTE* m_pBuf;
	int m_Len;
public:
	VDCmd(BYTE cmd_code,int param_count, WORD* param);
	BYTE* ConvertToBufFmt (BYTE cmd_id);
	int BufLen();
public:
	~VDCmd(void);
};
