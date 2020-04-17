#pragma once
#include "classmessage.h"
#include <vector>

class CTextOBJ : public OBJ_Control
{
public:
	CTextOBJ(void);
	CTextOBJ(OBJ_Control obj,CTextOBJ TextObj);
	~CTextOBJ(void);

public://����
	bool m_bVecotrWord;//�Ƿ�ʸ���ֿ�
	string m_WordStockFileName; //�ֿ��ļ���
	vector<vector<bool>> m_dots;//����dots���к��еĴ�С�����ַ��������Χ��
 
public://����
	 
	void GetVectorWordDots();
	void ReadOneVectorWord(FILE *pFile,char* strText,vector<vector<bool>>& dots,int& nWidth);//����dots���к��еĴ�С�����ַ��������Χ��
	
	//void PushBackTextOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW);
};

