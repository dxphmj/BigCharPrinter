#pragma once

#include "classmessage.h"
#include "ModuleMain.h"

class CVecTextOBJ : public OBJ_Control
{
public:
	CVecTextOBJ(void);
	CVecTextOBJ(OBJ_Control obj,CVecTextOBJ VecTextObj);
	~CVecTextOBJ(void);

public://����
	//wstring wStrFont;//�ֶε����壨�е������У��е�����û�У�
	//wstring wStrText;//�ֶε�text���ԣ�������
	int intFontSize;//�ֺ�

public://����
	void GenerateVecBmp(string strFont, string strText, int intFontSize);
};

