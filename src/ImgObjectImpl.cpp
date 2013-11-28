#include "StdAfx.h"
#include "ImgObjectImpl.h"

ImgObjectImpl::ImgObjectImpl(void)
{
	m_Width = 0;;
	m_Height = 0;
	m_BytesPerPixel = 0;
	m_XTable = 0;
	m_YTable = 0;
	m_DataBase = 0;
}

ImgObjectImpl::~ImgObjectImpl(void)
{
	Close();
}

void ImgObjectImpl::Open(LONG Width, LONG Height, LONG BytesPerPixel)
{
	//TODO Set the max Limitation of Width Height and BytesPerPixel
	
	if (m_DataBase)
	{
		return;
	}
	if (Width > 8192)
		Width = 8192;
	m_Width = Width;
	if (Height > 8192*10)
		Height = 8192 * 10;
	m_Height = Height;
	if (BytesPerPixel >= 3)
		BytesPerPixel = 4;
	m_BytesPerPixel = BytesPerPixel;
	//TODO Check the pointer value NULL
	m_DataBase = new BYTE[Width*Height*BytesPerPixel];

	m_XTable = new LONG [m_Width];
	m_YTable = new LONG [m_Height];

	for(int i = 0; i<m_Width;i++)
	{
		m_XTable[i] = i*m_BytesPerPixel; 
	}
	for(int i = 0; i<m_Height;i++)
	{
		m_YTable[i] = i*m_Width*m_BytesPerPixel;
	}
}

void ImgObjectImpl::Close ()
{
	if (m_DataBase)
	{
		delete [] m_DataBase;
		m_DataBase = NULL;
	}
	if (m_YTable)
	{
		delete [] m_YTable;
		m_YTable = NULL;
	}

	if (m_XTable)
	{
		delete [] m_XTable;
		m_XTable = NULL;
	}
}

long ImgObjectImpl::GetWidth ()
{
	return m_Width;
}	

long ImgObjectImpl::GetHeight ()
{
	return m_Height;
}

long ImgObjectImpl::GetDepth ()
{
	return m_BytesPerPixel;
}

LONG ImgObjectImpl::GetPixel (LONG X, LONG Y)
{
	LONG rt=0;
	if((X<m_Width)&&(Y<m_Height))
	{
		switch(m_BytesPerPixel)
		{
		case 4:
			rt = *((DWORD*)(m_DataBase+m_YTable[Y]*m_XTable[X]));
			break;
		case 2:
			rt = *((WORD*)(m_DataBase+m_YTable[Y]*m_XTable[X]));
			break;
		case 1:
			rt = *((BYTE*)(m_DataBase+m_YTable[Y]*m_XTable[X]));
			break;
		} 
	}
	else
	{
		rt = -1;
	}
	return rt;
}

void ImgObjectImpl::PutPixel (LONG X, LONG Y, LONG newVal)
{
	switch(m_BytesPerPixel)
	{
	case 4:
		*(DWORD*)(&(m_DataBase[m_YTable[Y]+m_XTable[X]])) = (WORD)newVal;
		break;
	case 2:
		*(WORD*)(&(m_DataBase[m_YTable[Y]+m_XTable[X]])) = (WORD)newVal;
		break;
	case 1:
		m_DataBase[m_YTable[Y]+m_XTable[X]] = (BYTE)newVal;
		break;
	}
}

LONG ImgObjectImpl::GetImageLineAddress (LONG Index)
{
		return m_YTable[Index]+(LONG)m_DataBase;
}