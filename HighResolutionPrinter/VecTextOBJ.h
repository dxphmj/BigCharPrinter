#pragma once

#include "classmessage.h"

class CVecTextOBJ : public OBJ_Control
{
public:
	CVecTextOBJ(void);
	CVecTextOBJ(OBJ_Control obj,CVecTextOBJ VecTextObj);
	~CVecTextOBJ(void);

public://����
	wstring wStrFont;//�ֶε����壨�е������У��е�����û�У�
	wstring wStrText;//�ֶε�text���ԣ�������
	int intFontSize;//�ֺ�
	

public://����
};

