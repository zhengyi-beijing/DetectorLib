#pragma once
#include "EngineIf.h"
#include "DataProvider.h"

class EngineImpl :
	public EngineIF 
{
private:
	CRITICAL_SECTION m_ThreadCR;
	int m_UpdateInterval;
	ChannelIF* m_Channel;
	HANDLE	m_hThread;
	DWORD	m_ThreadID;
	BOOL m_Running;
	BYTE m_Buf [ENGINE_BUF_SIZE];
	DataProvider m_Provider;
	

	/************************************************************************/
	/* DataProvider(void);
	void AddConsumer (DataConsumerIF* consumer);
	void RemoveConsumer (DataConsumerIF* consumer);
	void OnNotify (BYTE* buf, int size);                                                                     */
	/************************************************************************/

	ConnectionStatusIF* m_Monitor;

	/************************************************************************/
	/* 	virtual ~ConnectionStatusIF (void){};
	virtual void OnConnect () {};
	virtual void OnDisConnect (){};                                                                     */
	/************************************************************************/
public:
	EngineImpl(void);

	int Start ();
	void Stop ();

	void SetUpdateInterval (int interval);
	int GetUpdateInterval ();

	void SetChannel (ChannelIF* channel);
	ChannelIF* GetChannel ();

	static DWORD WINAPI ThreadFunc(LPVOID param);
	DWORD ThreadMemberFunc();

	void AddConsumer (DataConsumerIF*);
	void RemoveConsumer (DataConsumerIF*);

	void SetMonitor(ConnectionStatusIF* monitor);

public:
	virtual ~EngineImpl(void);
};
