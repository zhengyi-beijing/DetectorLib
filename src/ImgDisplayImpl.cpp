#include "StdAfx.h"
#include "ImgDisplayImpl.h"
#include "ImgControllerImpl.h"
//#include "ImgDisplay.h"

void ImgDisplayImpl::init_LUT ()
{
	m_MapStart = 0;
	m_MapEnd = 1000;
	set_LUT ();
}
void ImgDisplayImpl::set_LUT ()
{
	for (int i = 0; i<m_MapStart; i++)
	{
		m_LUT[i] = 0;
	}
	for (int i=m_MapStart; i<= m_MapEnd;i++)
	{
		m_LUT[i] = (BYTE)MAX_GRAY* (((float)i-m_MapStart)/(m_MapEnd-m_MapStart));
	}

	for (int i = m_MapEnd; i<LUT_SIZE; i++)
	{
		m_LUT[i] = 255;
	}
	if(m_Parent)
		FrameReady (); 
}
ImgDisplayImpl::ImgDisplayImpl()
{
	m_Parent = NULL;
	m_Opened = FALSE;
	init_LUT ();
}

ImgDisplayImpl::~ImgDisplayImpl(void)
{
	Close();
}

//redraw Whole Frame
void ImgDisplayImpl::Refresh()
{
	ATLTRACE ("DRAW img\n");
	HDC hdc = ::GetDC(m_Parent);
	m_DIB.Draw(hdc,&m_Rect);
	ReleaseDC(m_Parent, hdc);
}

 //Only update the latest frame
void ImgDisplayImpl::FrameReady () 
{
	//Get image data and do LUT map to display imgobject
	map_LUT(0,m_Height);//Refresh WHole Frame
	PostMessageA(m_Parent, WM_DISPLAY_REFRESH,0,0);
	//Draw display object
}

void ImgDisplayImpl::map_LUT(int StartLine, int EndLine)
{

	//LONG * pIndex;

	int NumLines = EndLine - StartLine  ;
	int YBase = StartLine;

	ImgObjectImpl* ImgSrc = m_pImgSrc->GetImgObject();
	int depth = ImgSrc->GetDepth();
	if(depth == 2)
	{
		for(int j = 0;j<NumLines;j++)
		{
			LONG pSrcRow;
			LONG pDstRow;
			pSrcRow = ImgSrc->GetImageLineAddress( j+YBase);
			pDstRow = m_ImageObject.GetImageLineAddress(j+YBase);
	//		ATLTRACE ("*****%dth line*******\n", j);
			//for(int i= 0;i<m_Width;i+=128)
			for(int i= 0;i<m_Width;i++)
			{
				//((BYTE*)pDstRow)[i] = m_LUT[((WORD*)pSrcRow)[i]];
				//((BYTE*)pDstRow)[i+32] = m_LUT[((WORD*)pSrcRow)[i+32]];
				//((BYTE*)pDstRow)[i+64] = m_LUT[((WORD*)pSrcRow)[i+64]];
				//((BYTE*)pDstRow)[i+96] = m_LUT[((WORD*)pSrcRow)[i+96]];
				((BYTE*)pDstRow)[i] = m_LUT[((WORD*)pSrcRow)[i]];
	//			ATLTRACE ("%dth pixel Src is %d, Dst is %d\n",i, ((WORD*)pSrcRow)[i],((BYTE*)pDstRow)[i] );
			}

		}
	}
}
void ImgDisplayImpl::SetImgSrc(ImgControllerImpl* src)
{
		m_pImgSrc = src;
		m_pImgSrc->AddDisplay(this);
};
ImgControllerImpl* ImgDisplayImpl::GetImgSrc ()
{
	return m_pImgSrc;

}

void ImgDisplayImpl::SetRect(RECT rect)
{ 
	m_Rect = rect;
}
void ImgDisplayImpl::SetMapStart (int start)
{
	m_MapStart = start;
	set_LUT ();
}

int ImgDisplayImpl::GetMapStart ()
{
	return m_MapStart;
}

void ImgDisplayImpl::SetMapEnd (int end)
{
	m_MapEnd = end;
	set_LUT ();
}

int ImgDisplayImpl::GetMapEnd ()
{
	return m_MapEnd;
}

int  ImgDisplayImpl::Open(int width, int height, int buf_num)
{
	//Create the 
	m_ImageObject.Open(width, height,1);
	m_Height = height;
	m_Width =width;
	m_Opened = TRUE;
	m_DIB.SetImgSrc(&m_ImageObject);
	return 0;
}

void  ImgDisplayImpl::Close()
{
	m_ImageObject.Close();
	m_Opened = FALSE;
}
BOOL ImgDisplayImpl::IsOpened()
{
	return m_Opened;
}

void  ImgDisplayImpl::SetWnd (HWND hWnd) 
{
	m_Parent = hWnd;
}