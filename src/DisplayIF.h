#pragma once
#include "ImgObjectImpl.h"
class ImgControllerImpl;
class DisplayIF
{
public:

	DisplayIF(void);
public:
	virtual ~DisplayIF(void);
public:
	virtual void Refresh () = 0;
	virtual void FrameReady () = 0;
	virtual void SetImgSrc (ImgControllerImpl* src) = 0;
	virtual BOOL IsOpened() = 0;
	virtual int Open(int width, int height, int buf_num) = 0;
	virtual void Close() = 0;
	virtual void SetWnd (HWND hWnd)=0 ;
	virtual void SetRect(RECT rect) = 0;
};
