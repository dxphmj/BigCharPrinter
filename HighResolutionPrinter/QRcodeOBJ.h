#pragma once
#include "classmessage.h"

class CQRcodeOBJ : public OBJ_Control
{
public:
	CQRcodeOBJ(void);
	CQRcodeOBJ(OBJ_Control obj,CQRcodeOBJ QRcodeObj);
	~CQRcodeOBJ(void);

public://Parameters
	string strqrcodeVersion;//��ά��İ汾����
	string strqrcodeECCLevel;//��ά����ݴ��ʵȼ�
	int intqrcodeQuietZone;//��ά��հ�

	bool boQRBig;
	int intQRVersion;
	int intQRErrLevel;
	int intQREncodingMode;


	//ʱ�䣬��̬�ı������к� �Գ�Ա��������ʽ
	//CTextOBJ m_StaticTextOBJ;
	//CSerialOBJ m_SerialOBJ;
	//CTimeOBJ   m_TimeOBJ;

	vector<OBJ_Control*> OBJ_Vec;


public://Functions
	void CreateQrcode();

};

