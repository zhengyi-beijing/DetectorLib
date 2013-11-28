#pragma once
#include "DataConsumerIf.h"

class DeCoder :
	public DataConsumerIF
{
private:

protected:
	BYTE m_Buf[DECODE_BUF_SIZE];
	int m_End;
	DeCoder* m_NextDeCoder;
		
	void virtual Process ()=0;
public:
	DeCoder(void);
	void SetNextDeCoder (DeCoder* decoder);
	DeCoder* GetNextDeCoder ();
	void OnNotify(BYTE* buf, int size);
	void Reset ();
public:
	virtual ~DeCoder(void);
};
