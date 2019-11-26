#include "StdAfx.h"
#include "CharObject.h"
#include <iostream>    
#include <fstream>      
using namespace std;

CCharObject::CCharObject(void)
{
	m_xPos = 0;
	m_yPos = 0;
}


CCharObject::~CCharObject(void)
{
}

void CCharObject::DrawObject(CDC* pDC,int nStepPixels)
{	  
	//��ȡÿ���ַ��ĵ�����Ϣ
	int startCol = m_xPos;	 

	int nCharNum = strlen(m_texts);
	for(int k = 0; k < nCharNum; k++)
	{
		startCol = m_xPos + k*8;
		char c = m_texts[k];

		wchar_t ttt = c;
		int unicodeNum = (int)ttt;

		int lonTextUniSetOffT = (unicodeNum)*8+64;
		char readfnt[8];
		readBin("7x5.fnt",lonTextUniSetOffT,readfnt,8);
        int nCol = readfnt[7];
		for(int i = 0; i < nCol; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				bool bDraw = ((readfnt[i]>>j) & 0x01);
				if(bDraw)
				{
					int row = 7-j+m_yPos;
					int col = startCol+i;
					CBrush cbrush;
					CBrush* pBrush; //�ɱ�ˢ					
					cbrush.CreateSolidBrush(RGB(0,0,0)); 
					pBrush = pDC->SelectObject(&cbrush); //�����ˢ

					CRect rect(col*nStepPixels,row*nStepPixels,(col+1)*nStepPixels,(row+1)*nStepPixels);
					pDC->Ellipse(&rect); 

					pDC->SelectObject(pBrush); //�ָ���ˢ
					cbrush.DeleteObject();
					pBrush->DeleteObject();
				}
			}
		}
	}	  	 
}

bool CCharObject::readBin(char* FontName,int offset,char *arr, int DataLen )
{
	ifstream file;
 
	file.open(FontName,ios::binary);
	file.seekg(offset,ios::beg);
	file.read(arr,DataLen);
	return true;
}


