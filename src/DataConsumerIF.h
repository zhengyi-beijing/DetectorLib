#pragma once

class DataConsumerIF
{
public:
	DataConsumerIF(void);
	virtual void OnNotify (BYTE* buf, int size)=0;
public:
	virtual ~DataConsumerIF(void);
};

class ConnectionStatusIF
{
public:
	ConnectionStatusIF (void)
	{

	};
	virtual ~ConnectionStatusIF (void){};
	virtual void OnConnect () {};
	virtual void OnDisConnect (){};
};