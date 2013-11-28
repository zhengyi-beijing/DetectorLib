#include "StdAfx.h"
#include "ImgDeCoderImpl.h"

ImgDeCoderImpl::ImgDeCoderImpl(void)
{
}

ImgDeCoderImpl::~ImgDeCoderImpl(void)
{
}

void ImgDeCoderImpl::SetImgConsumer (ImgConsumerIF* consumer)
{
	m_Consumer = consumer;
}

ImgConsumerIF* ImgDeCoderImpl::GetImgConsumer ()
{
	return m_Consumer;
}

void ImgDeCoderImpl::Process ()
{
	//Process the m_Buf queue
	//if the data ready call m_ImgConsumer->On_ImgReady
	//To copy the line to img consumer
	//by default just copy the data to the consumer
	m_Consumer->PutImageLineData(m_Buf,m_End);
	m_End = 0;
}
