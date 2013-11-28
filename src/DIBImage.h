#pragma once
//CDIBImage maintain a DIB Bitmap which be used for draw image
//Include the image data buffer and Palette
#include "ImgObjectImpl.h"
class CDIBImage
{
private:
	HBITMAP m_hBMP;
	BITMAPINFO* m_pBMI;
	BYTE* m_pData_Buf;
	LONG m_iBytesPerPixel;
	LONG m_Height;
	LONG m_Width;


private:

public:
	CDIBImage(void);
	void SetImgSrc (ImgObjectImpl* imgobj);
	void Draw(HDC hDC,LPRECT pDestRect,LONG StartLine,LONG EndLine);
	void Draw(HDC hDC,LPRECT pDestRect);
	BOOL Load(LPSTR pPath);
	BOOL Save(LPSTR pPath);
	LONG GetHeight();
	LONG GetWidth();
	~CDIBImage(void);
};
