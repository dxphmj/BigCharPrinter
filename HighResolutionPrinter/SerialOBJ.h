#pragma once
#include "classmessage.h"

class CSerialOBJ : public OBJ_Control
{
public:
	CSerialOBJ(void);
	~CSerialOBJ(void);

public://Parameters
	int intSerialFirstLimit;//�ֶε�FirstLimit���ԣ������кŵ�һ����
	int intSerialSecondLimit;//�ֶε�SecondLimit���ԣ������кŵڶ�����
	int intSerialStartValue;//�ֶε�StartValue���ԣ������к���ʼֵ
	int intSerialStep;//�ֶε�StepSize���ԣ������кŲ���ֵ
	int intSerialRepeat;//�ֶε�RepeatCount���ԣ������к��ظ�ֵ
	BYTE intSerialDigits;//�ֶε�Digital���ԣ������к�λ��ֵ
	int intSerialCounter;//�ڼ������к�
	BYTE bytSerialFormat;//�ֶε�SerialFormat���ԣ������кŸ�ʽ
	int counter;//���кŵļ�����

public://Functions

};

