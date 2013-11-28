#include "StdAfx.h"
#include "ImgControllerImpl.h"
#include "../ImgController.h"

ImgControllerImpl::ImgControllerImpl(CImgController* parent)
{
	m_CurRow = 0;
	m_FrameLen =0;
	m_Parent = parent;

}

ImgControllerImpl::~ImgControllerImpl(void)
{
	Close();
}


void ImgControllerImpl::PutImageLineData (BYTE* src, int len)
{
	//Call ImgObject put image line data
	//check the frame line if frame ready generate the frame event and  
	int pixel_num = m_ImageObject.GetWidth();
	int byte_per_pixel = m_ImageObject.GetDepth();
	int cplen = pixel_num*byte_per_pixel;
	len = ((cplen>len)?len:cplen);//choose the smaller one

	memcpy ((void*)m_ImageObject.GetImageLineAddress(m_CurRow), src, len);
	m_CurRow++;
	ATLTRACE("Line Num %d\n", m_CurRow);
	if (m_CurRow == m_FrameLen)
	{
		ATLTRACE("Frame Ready\n");
		m_CurRow = 0;
		list <DisplayIF*>::iterator Iter;
		for ( Iter = m_DisplayList.begin( ); Iter != m_DisplayList.end( ); Iter++ )
			(*Iter)->FrameReady();
		if (m_Parent)
			m_Parent->FrameReady();
	}

}

void ImgControllerImpl::AddDisplay (DisplayIF* display)
{
	m_DisplayList.push_back(display);
}

void ImgControllerImpl::RemoveDisplay (DisplayIF* display)
{
	m_DisplayList.remove(display);
}

int ImgControllerImpl::Open(int width, int height, int byte_per_pixel)
{
	m_ImageObject.Open (width, height, byte_per_pixel);
	m_FrameLen = height;
			/*
	list <DisplayIF*>::iterator Iter;

	for ( Iter = m_DisplayList.begin( ); Iter != m_DisplayList.end( ); Iter++ )
	{
		if(!(*Iter)->IsOpened())
			(*Iter)->Open(width, height,1);
	}*/
	return 0;
}

int ImgControllerImpl::Close()
{
	m_ImageObject.Close();
	/*
	list <DisplayIF*>::iterator Iter;
	for ( Iter = m_DisplayList.begin( ); Iter != m_DisplayList.end( ); Iter++ )
	{
		if((*Iter)->IsOpened())
			(*Iter)->Close();
	}*/
	return 0;
}
ImgObjectImpl* ImgControllerImpl::GetImgObject()
{
	return &m_ImageObject;
};