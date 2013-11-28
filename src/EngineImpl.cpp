#include "StdAfx.h"
#include "EngineImpl.h"
#include "ChannelStatusIF.h"
#include <process.h>
typedef unsigned * PBEGINTHREADEX_THREADID;
typedef unsigned (WINAPI *PBEGINTHREADEX_THREADFUNC) (LPVOID lpThreadParameter);
EngineImpl::EngineImpl(void)
{
	m_UpdateInterval = 0;
	m_Channel = NULL;
	m_hThread = NULL;
	m_ThreadID = 0;
	m_Running = FALSE;
	InitializeCriticalSection(&m_ThreadCR);
}

EngineImpl::~EngineImpl(void)
{
}

int EngineImpl::Start ()
{
	//Start the thread
	EnterCriticalSection(&m_ThreadCR);
	if (!m_Channel->GetStatus()->GetOpened())//0 is false,so open channel
	{
		m_Channel->Open();
	}
	if (!m_Channel->GetStatus()->GetOpened())//如果还是没有打开，退出
	{
		LeaveCriticalSection(&m_ThreadCR);
		return -1;
	}
	//这个有什么用，整个项目里有一个定义，一个使用
	m_Monitor->OnConnect();
	if (!m_Running)
	{
		m_Running = TRUE;
		m_hThread = (HANDLE)_beginthreadex(NULL,0,(PBEGINTHREADEX_THREADFUNC)EngineImpl::ThreadFunc,(LPVOID)this,0,(PBEGINTHREADEX_THREADID)&m_ThreadID);
	}
	LeaveCriticalSection(&m_ThreadCR);
	return 0;
}

DWORD WINAPI EngineImpl::ThreadFunc(LPVOID param)
{
	EngineImpl* pSrc = (EngineImpl*) param;
	return pSrc->ThreadMemberFunc();
}

DWORD EngineImpl::ThreadMemberFunc()
{
	ATLTRACE ("Thread start \n");
	for(;;)
	{
		if(!m_Running)
			break;
		int size = ENGINE_BUF_SIZE;
		size = m_Channel->Read(m_Buf, size);
		if(size > 0)
		{
		/*	#ifdef _DEBUG
		for (int i=0;i<size;i++)
				ATLTRACE(" %d th byte is %d \n",i, m_Buf[i]);
			ATLTRACE ("Get %d bytes data\n", size);
		#endif*/
			ATLTRACE ("Get %d bytes data\n", size);
			m_Provider.OnNotify(m_Buf, size);
		
		}
		else if (size <0)
		{
			//Some error happen;
			ATLTRACE ("size <0 \n");
			break;
		}
	}
	ATLTRACE ("Thread End \n");
	m_Monitor->OnDisConnect() ;
	m_Running = FALSE;
	return 0;
}

void EngineImpl::Stop ()
{
	//Stop the thread
	m_Running = FALSE;
	m_Channel->Close();
	if (!m_hThread)
	{
		return;
	}
	if ( WAIT_TIMEOUT == WaitForSingleObject( m_hThread, 10000 ) )
	{
		::TerminateThread( m_hThread, -1000 );
	}
	CloseHandle(m_hThread);
	m_Monitor->OnDisConnect() ;
	m_hThread = NULL;
	m_Channel->Close();
}

void EngineImpl::SetUpdateInterval (int interval)
{
	m_UpdateInterval = interval;
}

int EngineImpl::GetUpdateInterval ()
{
	return m_UpdateInterval;
}

void EngineImpl::SetChannel (ChannelIF* channel)
{
	m_Channel = channel;
}

ChannelIF* EngineImpl::GetChannel ()
{
	return m_Channel;
}

void EngineImpl::AddConsumer (DataConsumerIF* consumer)
{
	m_Provider.AddConsumer(consumer);
}

void EngineImpl::RemoveConsumer (DataConsumerIF* consumer)
{
	m_Provider.RemoveConsumer(consumer);
}

void EngineImpl::SetMonitor(ConnectionStatusIF* monitor)
{
	m_Monitor = monitor;
};