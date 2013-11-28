#include "StdAfx.h"
#include "DeCoder.h"

DeCoder::DeCoder(void)
{
	m_End = 0;
	memset(m_Buf, 0, DECODE_BUF_SIZE);
	m_NextDeCoder = NULL;
}

DeCoder::~DeCoder(void)
{
}

void DeCoder::OnNotify(BYTE* buf, int size)
{
	//Copy data to buffer
	BYTE* dst = m_Buf+m_End;
	ATLASSERT ((m_End+size) < DECODE_BUF_SIZE);//1024*10
	memcpy (dst, buf, size);
	m_End += size;
	//Process buffer
	//class ITPDeCoderImpl
	/************************************************************************/
	/* 
	BYTE temp_buf [10240];
	//HEADER_LEN ==4,所以不能大于4.它是一个区间，多出的部分是图像
	while (m_End > HEADER_LEN)
	{
	int len = GetITPLen();
	ATLTRACE ("itp len is %d m_End in IPS is %d\n",len, m_End);
	if (m_End >= GetITPLen())
	{//One Packet Ready
	m_NextDeCoder->OnNotify(m_Buf+HEADER_LEN, len-HEADER_LEN);
	int left_len = m_End - len;//相当于减于头信息，留下图像信息
	if(left_len)
	{
	//相当于把剩下的信息再放到m_buf中，再进行一次的处理
	memcpy (temp_buf, m_Buf + len, left_len);
	memcpy (m_Buf, temp_buf, left_len);
	}
	m_End = left_len;
	ATLTRACE ("left len in IPS is %d\n", left_len);
	}
	else
	{
	m_NextDeCoder->OnNotify(m_Buf+HEADER_LEN,len-HEADER_LEN);
	}
	/*	else

	break;*/
//}                                                                    
	/************************************************************************/
	Process();
}

void DeCoder::SetNextDeCoder (DeCoder* decoder)
{
	m_NextDeCoder = decoder;
}

DeCoder* DeCoder::GetNextDeCoder ()
{
	return m_NextDeCoder;
}

void DeCoder::Reset ()//什么意思，自己调用自己？递归？
{
	m_End = 0;
	//if(m_NextDeCoder)
	//	m_NextDeCoder->Reset();

	if (m_NextDeCoder)
	{
		m_NextDeCoder = NULL;
	}
}