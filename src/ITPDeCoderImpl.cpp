#include "StdAfx.h"
#include "ITPDeCoderImpl.h"

ITPDeCoderImpl::ITPDeCoderImpl(void)
{
}

ITPDeCoderImpl::~ITPDeCoderImpl(void)
{
}
//get the len of the packet
int ITPDeCoderImpl::GetITPLen()
{
	WORD* len;
	len = (WORD*)m_Buf;
	return *len;
}
void ITPDeCoderImpl::Process ()
{
	//ITP
	//Packet header: 
	//  1: LowByte of Len
	//	2: HighByte of Len
	//	3: PacketType //0:For command 1: for image
	//	4: Reserve
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
	}
	
}