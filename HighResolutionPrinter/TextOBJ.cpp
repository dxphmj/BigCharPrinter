#include "TextOBJ.h"
#include "wordStock\\GetHZinfo.h"

CTextOBJ::CTextOBJ(void)
{
}

CTextOBJ::CTextOBJ(OBJ_Control obj,CTextOBJ TextObj)
{
	strType1 = obj.strType1;
	strType2 = obj.strType2;
	intX = obj.intX;
	intY = obj.intY;
	intSW = obj.intSW;
	intSS = obj.intSS;

	booNEG = obj.booNEG;
	booBWDx = obj.booBWDx;
	booBWDy = obj.booBWDy;
	strFont = obj.strFont;
	strText = obj.strText;
	intLineSize = obj.intLineSize;
	intRowSize = obj.intRowSize;
	intLineStart = obj.intLineStart;
	intRowStart = obj.intRowStart;
	booFocus = obj.booFocus;

	m_bVecotrWord = TextObj.m_bVecotrWord;
	m_WordStockFileName = TextObj.m_WordStockFileName;
}

CTextOBJ::~CTextOBJ(void)
{
}

void CTextOBJ::GetVectorWordDots()
{
	//char* strFileName = new char[256];
	//sprintf(strFileName,"%s","..\\Debug\\HZKSLKTJ");
	FILE *pFile = fopen(m_WordStockFileName.c_str(),"rb");

	char* oneWord = new char[2];
	//sprintf(strText,"%s","��");

	//ѭ������strText���ַ��Ĺ켣,����strFont��С�����Ӧ������Ϣ 
	for(int i = 0; i < strText.length(); i++)
	{
		vector<vector<bool>> dots;//��¼һ���ַ��ĵ�����Ϣ�����и߶���strFont�������ʵ��������ء�
		int nWidth;
		char* oneWord = new char[2];
		sprintf(oneWord,"%s",strText.c_str()[i]);
		ReadOneVectorWord(pFile,oneWord,dots,nWidth);
		delete oneWord;
		//��dots�ϲ���m_dots��
	}

	fclose(pFile);
}

void CTextOBJ::ReadOneVectorWord(FILE *pFile,char* strText,vector<vector<bool>>& dots,int& nWidth)
{ 
	hzPoint topleft(20,20); 
	CGetHZinfo hzInfo(pFile,(unsigned char*)strText,topleft);

}