#pragma once
#include "classmessage.h"

class CSerialOBJ : public OBJ_Control
{
public:
	CSerialOBJ(void);
	CSerialOBJ(OBJ_Control obj,CSerialOBJ SerialObj);
	~CSerialOBJ(void);

public: 
	int intSerialFirstLimit;//�ֶε�FirstLimit���ԣ������кŵ�һ����
	int intSerialSecondLimit;//�ֶε�SecondLimit���ԣ������кŵڶ�����
	int intSerialStartValue;//�ֶε�StartValue���ԣ������к���ʼֵ
	int intSerialStep;//�ֶε�StepSize���ԣ������кŲ���ֵ
	int intSerialRepeat;//�ֶε�RepeatCount���ԣ������к��ظ�ֵ
	BYTE intSerialDigits;//�ֶε�Digital���ԣ������к�λ��ֵ
	int intSerialCounter;//�ڼ������к�
	BYTE bytSerialFormat;//�ֶε�SerialFormat���ԣ������кŸ�ʽ

	int CountNum; //���кŵ�ǰֵ�Ĵ�С
	int CountNumRep; //���кŵ�ǰ�ظ��Ĵ�С


public://Functions
	void CreateSerialDynamic(vector<BYTE>& bytPrintDataAll,bool boReverse, bool boInverse,int matrixMesdis,int pixelMesdis,map<string,
							vector<BYTE>> bytdigital5x5LineMap,map<string,vector<BYTE>> bytdigital7x5LineMap,
							map<string,vector<BYTE>> bytdigital12x12LineMap,map<string,vector<BYTE>> bytdigital16x12LineMap,UINT32 *IntMes,int intRowMax);

};

