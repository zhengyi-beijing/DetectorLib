#pragma once
#include "DataConsumerIF.h"
#include <list>
using namespace std;
class DataProvider
{
protected:
		list<DataConsumerIF*> m_ConsumerList;
public:
	DataProvider(void);
	void AddConsumer (DataConsumerIF* consumer);
	void RemoveConsumer (DataConsumerIF* consumer);
	void OnNotify (BYTE* buf, int size);
	
public:
	virtual ~DataProvider(void);
};
