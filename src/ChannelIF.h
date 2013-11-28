#pragma once

class ChannelStatusIF;
/** ChannelIF Class
*
*/
class ChannelIF
{
public:
	ChannelIF(void);
	virtual int Write (BYTE* src, int size) = 0;
	virtual int Read (BYTE* dst, int& size) = 0;
	virtual int Open () = 0;
	virtual int Close () = 0;
	virtual ChannelStatusIF* GetStatus() = 0;
public:
	virtual ~ChannelIF(void);
};
