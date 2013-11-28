#pragma once
#include "decoder.h"
#include "ImgConsumerIF.h"
class ImgDeCoderImpl :
	public DeCoder
{
private:
	ImgConsumerIF* m_Consumer;
protected:
	virtual void Process ();
public:
	ImgDeCoderImpl(void);
	
	void SetImgConsumer (ImgConsumerIF* consumer);
	ImgConsumerIF* GetImgConsumer ();

public:
	virtual ~ImgDeCoderImpl(void);
};
