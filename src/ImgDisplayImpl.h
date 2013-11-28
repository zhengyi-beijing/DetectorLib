#pragma once
#include "DisplayIf.h"
#include "ImgObjectImpl.h"
#include "DIBImage.h"

class ImgControllerImpl;
class ImgDisplayImpl :
	public DisplayIF
{

private:
	int m_FrameNum; //The times of the frame buffer size. at least 1, equal the size of frame buffer.
	int m_Width; // Pixel Number
	int m_Height;
	ImgObjectImpl	m_ImageObject;
	ImgControllerImpl* m_pImgSrc;
	HWND m_Parent;

	BYTE m_LUT [LUT_SIZE];
	int m_MapStart;
	int m_MapEnd;

	BOOL m_Opened;
	CDIBImage m_DIB;
	RECT m_Rect;
private: 
	void init_LUT ();
	void set_LUT ();
	void map_LUT(int startline, int endline);
public:
	enum DisplayMode {FRAME, SCAN, MOVE} ;
public:
	ImgDisplayImpl();
public:
	virtual ~ImgDisplayImpl(void);
	virtual void Refresh();//Get data from ImgController and redraw Whole Frame
	virtual void FrameReady () ; //Only update the latest frame

	int Open(int width, int height, int buf_num);
	void  SetWnd (HWND hWnd);
	void Close();
	BOOL IsOpened();
	//int SetDisplayMode (int mode);
	void SetImgSrc(ImgControllerImpl* src);
	void SetRect(RECT rect) ;
	ImgControllerImpl* GetImgSrc ();

	void SetMapStart (int start);
	int GetMapStart ();

	void SetMapEnd (int end);
	int GetMapEnd ();
	
};

	