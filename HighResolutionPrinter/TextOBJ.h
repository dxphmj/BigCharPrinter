#pragma once
#include "classmessage.h"
#include <vector>

class CTextOBJ : public OBJ_Control
{
public:
	CTextOBJ(void);
	~CTextOBJ(void);

public://����
	bool m_bVecotrWord;//�Ƿ�ʸ���ֿ�
	string m_WordStockFileName; //�ֿ��ļ���
	ClassMessage m_PrinterMes;//ClassMessage��������

public://����
	/*char objbytTex5x5Line[7];
	char objbytTex7x5Line[8];
	char objbytTex12x12Line[25];
	char objbytTex16x12Line[29];*/
	vector<vector<bool>> m_dots;//����dots���к��еĴ�С�����ַ��������Χ��
	void GetVectorWordDots();
	void ReadOneVectorWord(FILE *pFile,char* strText,vector<vector<bool>>& dots,int& nWidth);//����dots���к��еĴ�С�����ַ��������Χ��
	
	//void PushBackTextOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW);

};

