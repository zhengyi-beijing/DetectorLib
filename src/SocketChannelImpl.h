#pragma once
#include "channelif.h"
#include "ChannelStatus.h"
/*
@ Use socket API to implement the SocketChannelImpl
*/
#define MAX_IP_LEN		50
#define BUF_SIZE		4096
#define DEF_PORT		9000
#define DEF_IP			"127.0.0.1"

class SocketChannelImpl :
	public ChannelIF
{
private:
	SOCKET m_socket;
	char m_ip [MAX_IP_LEN];
	long m_port;

	BOOL m_bConnected;
	char m_buffer [BUF_SIZE];
	ChannelStatus m_Status;

public:
	SocketChannelImpl(void);
	void SetRemoteIP (char* ip);
	char* GetRemoteIP ();
	void SetRemotePort (int port);
	int GetRemotePort ();
public:
	virtual int Write (BYTE* src, int size);
	virtual int Read (BYTE* dst, int& size);
	virtual int Open ();
	virtual int Close ();
	virtual ChannelStatusIF* GetStatus();
public:
	virtual ~SocketChannelImpl(void);
};
