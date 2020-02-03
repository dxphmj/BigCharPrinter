#pragma once

typedef unsigned char BYTE;

class CParamSetting
{
public:
	CParamSetting(void);
	virtual ~CParamSetting(void);

public:
	//pcf控制0X00
	BYTE pcf0X00bit1_bit0 ;// 列触发方式：0为编码器1相，1为编码器2相，2为内部一列点数（即等于64K/划速率）
	BYTE pcf0X00bit2 ; //同步器反相，0：A->B，1:B->A
	BYTE pcf0X00bit4 ; //故障运行，正在打印遇到故障时的处理，0打印停止，1 打印继续，但墨点没有喷出来
	BYTE pcf0X00bit5; //产品计数器重置，0 不重置，1 重置到设定值
	BYTE pcf0X00bit6 ; //打印计数器重置，0 不重置，1 重置到设定值

	//pcf控制0X01
	BYTE pcf0X01bit0 ; //是否启用电眼，0为关闭，1为启用
	BYTE pcf0X01bit2 ; //电眼有效电平，0为低电平，1为高电平
	BYTE pcf0X01bit3 ; //喷印模式为单次还是连续，0为单次，1为连续


public:
	void SaveParam2Xml();
	void OpenParamFromXml();

};

