#pragma once

class ImgObjectImpl
{
public:
	ImgObjectImpl(void);
public:
	~ImgObjectImpl(void);
	long GetWidth ();
	long GetHeight ();
	long GetDepth ();
	void Open(LONG Width, LONG Height, LONG BytesPerPixel);
	void Close ();
	LONG GetPixel (LONG X, LONG Y);
	void PutPixel (LONG X, LONG Y, LONG newVal);
	LONG GetImageLineAddress (LONG LineIndex);
private:
	LONG m_Width;
	LONG m_Height;
	LONG m_BytesPerPixel;
	LONG* m_XTable;
	LONG* m_YTable;
	BYTE* m_DataBase;

	//LONG* m_ColAvg;
	//LONG* m_ColMax;
	//LONG* m_ColMin;
	//float* m_ColNoise;

	//LONG* m_RowAvg;
	//LONG* m_RowMax;
	//LONG* m_RowMin;
	//float* m_RowNoise;

};
