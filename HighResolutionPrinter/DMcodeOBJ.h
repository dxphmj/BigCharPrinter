#pragma once
#include "classmessage.h"
class CDMcodeOBJ :
	public OBJ_Control
{
public:
	CDMcodeOBJ(void);
	~CDMcodeOBJ(void);

public://Parameters
	int intDMsize;//����DM���С
	int intDMrow;//����DM���С��ǰ��
	string strDMContent;//����DM�������

public://Functions
};

