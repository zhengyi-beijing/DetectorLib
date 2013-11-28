#include "StdAfx.h"
#include ".\dibimage.h"
#include "atlimage.h"
CDIBImage::CDIBImage(void)
{
	m_iBytesPerPixel =3;
	m_pData_Buf = NULL;
	m_Height = 0;
	m_Width = 0;
	m_pBMI = (BITMAPINFO*)new BYTE[sizeof(BITMAPINFOHEADER)+256*sizeof(RGBQUAD)];
	for(int i = 0; i<256;i++)
	{
		m_pBMI->bmiColors[i].rgbBlue =i;
		m_pBMI->bmiColors[i].rgbGreen =i;
		m_pBMI->bmiColors[i].rgbRed =i;
		m_pBMI->bmiColors[i].rgbReserved = 0;
	}
}

CDIBImage::~CDIBImage(void)
{
	if(m_pBMI)
		delete [] m_pBMI;
	m_pData_Buf = NULL;
	m_pBMI = NULL;
	m_Height = 0;
	m_Width = 0;

}
void CDIBImage::SetImgSrc (ImgObjectImpl* imgobj)//Allocate the image buffer
{
	m_pData_Buf = (BYTE*)imgobj->GetImageLineAddress(0);
	ATLASSERT(m_pData_Buf);
	

	ATLASSERT(m_pBMI);
	if(NULL == m_pBMI)
	{
		ATLASSERT(0);
	}
	m_Height = imgobj->GetHeight();
	m_Width = imgobj->GetWidth();
	m_pBMI->bmiHeader.biBitCount = 8;
	m_pBMI->bmiHeader.biClrImportant = 0;
	m_pBMI->bmiHeader.biCompression = 0;
	m_pBMI->bmiHeader.biHeight = m_Height;
	m_pBMI->bmiHeader.biClrUsed =256;
	m_pBMI->bmiHeader.biPlanes = 1;
	m_pBMI->bmiHeader.biSize = 40;
	m_pBMI->bmiHeader.biSizeImage = m_Width*m_Height*m_iBytesPerPixel;//m_iHeight*m_iWidth;
	m_pBMI->bmiHeader.biWidth = m_Width;//m_iWidth;
	m_pBMI->bmiHeader.biXPelsPerMeter = 0;
	m_pBMI->bmiHeader.biYPelsPerMeter =0;
//here set the palette


}

void CDIBImage::Draw(HDC hDC,LPRECT pDestRect)
{
	Draw(hDC,pDestRect,0,m_Height);
}
void CDIBImage::Draw(HDC hDC,LPRECT pDestRect,LONG StartLine,LONG EndLine)
{
	if(hDC)
	{
		int Height = EndLine -StartLine;
		m_pBMI->bmiHeader.biHeight = Height;
		m_pBMI->bmiHeader.biSizeImage = Height*m_Width;
		ATLASSERT(Height>0);
		SetStretchBltMode(hDC, HALFTONE);
			SetBrushOrgEx(hDC, 0,0, NULL);
		::StretchDIBits(hDC,pDestRect->left,
			pDestRect->top,pDestRect->right - pDestRect->left,
			pDestRect->bottom - pDestRect->top,
			0,0,m_Width,Height,
			m_pData_Buf+(m_Height-EndLine)*m_Width,m_pBMI,
			DIB_RGB_COLORS,
			SRCCOPY);	
	}
}
BOOL CDIBImage::Save(LPSTR pPath)
{
	return TRUE;
}
BOOL CDIBImage::Load(LPSTR pPath)
{

	return TRUE;
}
LONG CDIBImage::GetHeight()
{
	return m_Height;
}
LONG CDIBImage::GetWidth()
{
	return m_Width;
}