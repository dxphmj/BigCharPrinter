#pragma once

#include <stdio.h> 

typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef int                 BOOL;
typedef char CHAR;
typedef short SHORT;
typedef long LONG;

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif


#define x_con   100       //�̶��ĺ�����Ӿ��ο��
#define y_con   100       //�̶��ĺ�����Ӿ��θ߶�

struct hzPoint
{ 	
	short x;
	short y;

	hzPoint(short initX,short initY)
	{
		x = initX;
		y = initY;
	}
};

typedef struct tagRECT2
{
	LONG    left;
	LONG    top;
	LONG    right;
	LONG    bottom;
} RECT2, *PRECT2;

#ifndef HZTOOL
#define DllExport   __declspec( dllexport )
#else
#define DllExport   __declspec( dllimport )

#endif

class CGetHZinfo
{
public:
	CGetHZinfo(void);
	CGetHZinfo(FILE* pFile,unsigned char* hzChar,hzPoint& topleft);

	~CGetHZinfo(void);

public:
	RECT2 m_position;
	hzPoint* 	pointsall;      //��������������������
	hzPoint* 	pointsv;        //�������������������
	int numofcontour;    //�����������������Ƿ����������
	int* numpercontour;  //ÿ�������ĵ�����

public:

	hzPoint FindRect(WORD* hzdata,int numofpoint);
	BOOL  Convert(WORD* hzdata,int numofpoint); 
	int   decode(BYTE* sourceBuf, WORD* denstBuf,int num);


};

