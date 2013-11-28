#pragma once

class ImgConsumerIF
{
public:
	ImgConsumerIF(void);
public:
	virtual ~ImgConsumerIF(void);
	virtual void PutImageLineData (BYTE* src, int len)=0;
};
