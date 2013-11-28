#include "StdAfx.h"
#include "SocketChannelImpl.h"
#include "ChannelStatusIF.h"
#include <winsock2.h> 
#pragma comment(lib, "ws2_32.lib")
SocketChannelImpl::SocketChannelImpl(void)
{
	m_socket = 0;
	//strncpy (m_ip, DEF_IP, MAX_IP_LEN);
	memcpy(m_ip,DEF_IP,MAX_IP_LEN);
	m_port = DEF_PORT;
}

SocketChannelImpl::~SocketChannelImpl(void)
{
	WSACleanup();
}

void SocketChannelImpl::SetRemoteIP (char* ip)
{
	int len = strlen(ip);
	if (len > MAX_IP_LEN)
		len = MAX_IP_LEN;
	memcpy (m_ip, ip, len);
}
char* SocketChannelImpl::GetRemoteIP ()
{
	return m_ip;
}
void SocketChannelImpl::SetRemotePort (int port)
{
	m_port = port;
}
int SocketChannelImpl::GetRemotePort ()
{
	return m_port;
}

int SocketChannelImpl::Write (BYTE* src, int size)
{
	WORD send_len = 0;
	int rt;
	while(send_len < size)
	{//Should Add the head XTP
		rt= send(m_socket,(const char*)(src + send_len),size - send_len,0);
		if(SOCKET_ERROR == rt)
		{
			return -1;
		}
		send_len += rt;
	}
	return send_len;
}

int SocketChannelImpl::Read (BYTE* dst, int& size)
{
	int len = recv(m_socket,(char*)dst,size,0);
	if(len < 0)
	{
		//	m_bConnected = FALSE;
		Close();
	}
	return len;
}

int SocketChannelImpl::Open ()
{
	//TODO: make connection to remote address port
	WORD wVersionRequested = MAKEWORD( 2, 2 );
	WSADATA wsaData;
	int err = WSAStartup( wVersionRequested, &wsaData );
	//The WSAStartup function initiates use of WS2_32.DLL by a process.
	if ( err != 0 ) 
	{
		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */
		m_bConnected = FALSE;
		return FALSE;
	}

	/* Confirm that the WinSock DLL supports 2.2.*/
	/* Note that if the DLL supports versions greater    */
	/* than 2.2 in addition to 2.2, it will still return */
	/* 2.2 in wVersion since that is the version we      */
	/* requested. */

	if ( LOBYTE( wsaData.wVersion ) != 2 ||
		HIBYTE( wsaData.wVersion ) != 2 ) 
	{
			/* Tell the user that we could not find a usable */
			/* WinSock DLL.*/
			m_bConnected = FALSE;
			WSACleanup( );
			return FALSE; 
	}

	/*************************************/
	//Check Network connection
	/*************************************/
	m_socket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );
	if ( m_socket == INVALID_SOCKET ) 
	{
		WSACleanup();
		return FALSE;
	}
	sockaddr_in clientService;

	clientService.sin_family = AF_INET;
	clientService.sin_addr.s_addr = inet_addr((char*) m_ip );
	clientService.sin_port = htons( m_port);
	//Set the Socket Option
	//int TimeOut = 1000;

	if ( connect( m_socket, (SOCKADDR*) &clientService, sizeof(clientService) ) == SOCKET_ERROR) 
	{
		WSACleanup();
		m_bConnected = FALSE;
		closesocket(m_socket);
		return FALSE;
	}

	/************************************************************************/
	/* 
	Bluetooth and Socket Options
	Bluetooth for Windows supports the following socket options. Socket options are set and queried 
	using the setsockopt and getsockopt functions, respectively. All of the following options can be
	used with the setsockopt function, but only the SO_BTH_MTU option is available for use with the
	getsockopt function.


	The following settings are required for working with Bluetooth socket options:

	The s parameter must be a Bluetooth socket. 
	The level parameter must be SOL_RFCOMM.                                                                      */
	/************************************************************************/
	int bNodelay = 1; 

	err = setsockopt( m_socket, IPPROTO_TCP, TCP_NODELAY, (char *)&bNodelay, sizeof(bNodelay));//
	if (err != NO_ERROR) 
		ATLTRACE ("setsockopt failed for some reason\n");
	int bufsize =BUF_SIZE;

	err = setsockopt( m_socket, SOL_SOCKET, SO_RCVBUF, (char *)&bufsize, sizeof(bufsize));//
	if (err != NO_ERROR) 
		ATLTRACE ("setsockopt failed for some reason\n");; 



	m_bConnected = TRUE;
	m_Status.PutOpened(m_bConnected);

	return 0;
}

int SocketChannelImpl::Close ()
{
	//TODO: close the socket 
//	The shutdown function disables sends or receives on a socket.
	/*
	* WinSock 2 extension -- manifest constants for shutdown()
	
	#define SD_RECEIVE      0x00
	#define SD_SEND         0x01
	#define SD_BOTH         0x02
	*/
	shutdown(m_socket,SD_SEND);
	while(1)
	{
		int len = recv(m_socket,m_buffer,10,0);
		if(len<=0)
			break;
	}
	closesocket(m_socket);

	m_bConnected = FALSE;
	m_Status.PutOpened(m_bConnected);
	return 0;
}

ChannelStatusIF* SocketChannelImpl::GetStatus()
{
	return &m_Status;
}