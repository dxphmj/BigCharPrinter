#pragma once
#include "classmessage.h"

class CTimeOBJ : public OBJ_Control
{
public:
	CTimeOBJ(void);
	CTimeOBJ(OBJ_Control obj,CTimeOBJ TimeObj);
	~CTimeOBJ(void);

public: 
	string strTime;//�ֶε�time���ԣ���ʱ���ʽ
	int booETimeOffSet;//�ֶε�ʱ��ƫ�ƿ��أ�falseΪ�رգ�trueΪ������
	int intTimeOffSet;//�ֶε�ʱ��ƫ��ֵ
	int strTimeOffSet;//�ֶε�ʱ��ƫ������
	

public://Functions
	void CreateTimeDynamic(vector<BYTE>& bytPrintDataAll,bool boReverse, bool boInverse,int matrixMesdis,int pixelMesdis,
							map<string,vector<BYTE>> bytdigital5x5LineMap,map<string,vector<BYTE>> bytdigital7x5LineMap,
							map<string,vector<BYTE>> bytdigital12x12LineMap,map<string,vector<BYTE>> bytdigital16x12LineMap,UINT32 *IntMes,int intRowMax);

};

