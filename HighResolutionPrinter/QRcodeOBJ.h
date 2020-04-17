#pragma once
#include "classmessage.h"

class CQRcodeOBJ : public OBJ_Control
{
public:
	CQRcodeOBJ(void);
	~CQRcodeOBJ(void);

public://Parameters
	string strqrcodeVersion;//��ά��İ汾����
	string strqrcodeECCLevel;//��ά����ݴ��ʵȼ�
	int intqrcodeQuietZone;//��ά��հ�

	bool boQRBig;
	int intQRVersion;
	int intQRErrLevel;
	int intQREncodingMode;

public://Functions
	void CreateQrcode();

};

