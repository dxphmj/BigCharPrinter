#pragma once
#include "classmessage.h"

class CBarcodeOBJ : public OBJ_Control
{
public:
	CBarcodeOBJ(void);
	~CBarcodeOBJ(void);

public://Parameters
	int intBarcodeType;//���������������
	int intBarType;//������������
	string strCodeContent;//���������������
	int intBarWhite;//����������հ׿��

public://Functions
	void Create2Dcode();

};

