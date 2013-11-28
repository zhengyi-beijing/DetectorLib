#pragma once
#include "DataConsumerIF.h"
#include "ChannelIF.h"
class EngineIF
{
public:
	EngineIF(void);
	virtual int Start ()=0;
	virtual void Stop ()=0;
	virtual void SetUpdateInterval (int interval)=0;
	virtual int GetUpdateInterval ()=0;
	virtual void SetChannel (ChannelIF* channel)=0;
	virtual ChannelIF* GetChannel ()=0;
	virtual void AddConsumer (DataConsumerIF*) = 0;
	virtual void RemoveConsumer (DataConsumerIF*) = 0;
	virtual void SetMonitor (ConnectionStatusIF*){};
public:
	virtual ~EngineIF(void);
};
