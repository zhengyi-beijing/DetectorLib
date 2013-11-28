#pragma once
#include "decoder.h"

class ITPDeCoderImpl :
	public DeCoder
{
private:
	int GetITPLen();
public:
	ITPDeCoderImpl(void);
protected:
	virtual void Process ();
public:
	virtual ~ITPDeCoderImpl(void);
};
