#pragma once
#include "classmessage.h"

class CTimeOBJ : public OBJ_Control
{
public:
	CTimeOBJ(void);
	~CTimeOBJ(void);

public://Parameters
	string strTime;//�ֶε�time���ԣ���ʱ���ʽ
	int booETimeOffSet;//�ֶε�ʱ��ƫ�ƿ��أ�faulseΪ�رգ�trueΪ������
	int intTimeOffSet;//�ֶε�ʱ��ƫ��ֵ
	int strTimeOffSet;//�ֶε�ʱ��ƫ������
	//string strETimeOffSet;//�ֶε�ʱ��ƫ�ƿ��أ�faulseΪ�رգ�trueΪ������
	//int intTimeOffSet;//�ֶε�ʱ��ƫ��ֵ
	//string strTimeOffSet;//�ֶε�ʱ��ƫ������

public://Functions

};

