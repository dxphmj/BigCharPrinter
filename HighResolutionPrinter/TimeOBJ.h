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

};

