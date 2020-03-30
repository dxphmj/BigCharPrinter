#include "TextOBJ.h"
#include "wordStock\\GetHZinfo.h"

CTextOBJ::CTextOBJ(void)
{
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