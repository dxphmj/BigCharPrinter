#pragma once

typedef unsigned char BYTE;

class CParamSetting
{
public:
	CParamSetting(void);
	virtual ~CParamSetting(void);

public:
	//pcf����0X00
	BYTE pcf0X00bit1_bit0 ;// �д�����ʽ��0Ϊ������1�࣬1Ϊ������2�࣬2Ϊ�ڲ�һ�е�����������64K/�����ʣ�
	BYTE pcf0X00bit2 ; //ͬ�������࣬0��A->B��1:B->A
	BYTE pcf0X00bit4 ; //�������У����ڴ�ӡ��������ʱ�Ĵ���0��ӡֹͣ��1 ��ӡ��������ī��û�������
	BYTE pcf0X00bit5; //��Ʒ���������ã�0 �����ã�1 ���õ��趨ֵ
	BYTE pcf0X00bit6 ; //��ӡ���������ã�0 �����ã�1 ���õ��趨ֵ

	//pcf����0X01
	BYTE pcf0X01bit0 ; //�Ƿ����õ��ۣ�0Ϊ�رգ�1Ϊ����
	BYTE pcf0X01bit2 ; //������Ч��ƽ��0Ϊ�͵�ƽ��1Ϊ�ߵ�ƽ
	BYTE pcf0X01bit3 ; //��ӡģʽΪ���λ���������0Ϊ���Σ�1Ϊ����


public:
	void SaveParam2Xml();
	void OpenParamFromXml();

};

