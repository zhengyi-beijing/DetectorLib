#pragma once
#include <list>
#include "ImgConsumerIF.h"
#include "DisplayIF.h"
#include "ImgObjectImpl.h"
using namespace std;
class CImgController;
class ImgControllerImpl:public ImgConsumerIF
{
private:
	list<DisplayIF*>  m_DisplayList;

	ImgObjectImpl	m_ImageObject;
	int			m_CurRow;
	int			m_FrameLen;//Height
	CImgController* m_Parent;
public:
	ImgControllerImpl(CImgController* parent);
public:
	~ImgControllerImpl(void);
	 void Reset ();
	 void PutImageLineData (BYTE* src, int len);
	 void AddDisplay (DisplayIF* display);
	 void RemoveDisplay (DisplayIF* display);
	 int Open(int width, int height, int byte_per_pixel);
	 int Close();
	ImgObjectImpl* GetImgObject();
};
