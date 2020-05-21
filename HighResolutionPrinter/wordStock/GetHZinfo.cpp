#include "GetHZinfo.h"
#include "Dom.h"
#include <memory.h>
//#include <windows.h>
//#include <windowsx.h>
//
//typedef struct tagRECT
//{
//	LONG    left;
//	LONG    top;
//	LONG    right;
//	LONG    bottom;
//} RECT, *PRECT;
//

struct index
{
	unsigned long offset;
	unsigned short length;
};


CGetHZinfo::CGetHZinfo(void)
{
}

CGetHZinfo::~CGetHZinfo(void)
{
}

CGetHZinfo::CGetHZinfo(FILE* fp,unsigned char* hzChar,hzPoint& topleft)
{
/*	unsigned char qmv;
	unsigned char wmv;

 	//qmv = 4; //HZKSLE������ ��1-5��20���� ���� 4
 	//wmv = 20;
 	qmv = (unsigned char)hzChar[0]-0xa0;//������-0xa0������λ�룬���ӿ��е����ֺ���ĸ��ȫ�ǵ�
 	wmv = hzChar[1]-0xa0;
	
	int numofpoint = 0;            //the tatal points num
	int numofcontour = 0;          //the tatal contour num
	short* numpercontour = NULL;      //ptr:the points num array of single contour 

	//h_data = NULL;
	//h_hzdata = NULL;
	//h_pointsall = NULL;
	//h_pointsv = NULL;

	//hzdata=NULL;
	//pointsall=NULL;          //ptr:points array for the contour
	//pointsv=NULL;
	 
	 
	//WORD* hzdata = new WORD(64*1016);//(WORD*)::GlobalLock(temphz);
	//BYTE* buf = new BYTE(2000*sizeof(WORD));
    //��ʱ���� 
    HGLOBAL 	h_data;         //����:hzdata,pointsall,pointsv
	HGLOBAL 	h_hzdata;       //handle:���ֵ�ԭʼ��������,x,y,flag,��������ϵ
	WORD*   	hzdata;         //ptr
	HANDLE temphz,tempbuf;
	temphz=::GlobalAlloc(GHND,(long)64*1016);    //��ѹ������,��DOM���������
	hzdata=(WORD*)::GlobalLock(temphz);
	tempbuf=::LocalAlloc(LHND,2000*sizeof(WORD)); //���ѹ���ֿ�����
	BYTE* buf=(BYTE*)::LocalLock(tempbuf);
	if(hzdata==NULL) return;
	//CFile fp;
	if(buf==NULL) return;
	int num;
	long offset;
	index slindex;
	//��ʱ����
		 
	if(qmv>=16)
	{
		//ʹ�ú���ͨ��
		offset = ((unsigned long)(qmv-16)*94+wmv-1)*6;
	}
	else 
	{ 			
		offset = ((unsigned long)(qmv-1)*94+wmv-1)*6;
	}

   //offset = ((unsigned long)(qmv-32))*6;

	fseek(fp,offset,SEEK_SET);         
	fread(&slindex,sizeof(index),1,fp); //�ļ��е��ֽ���ǰ�����ֽ��ں�
	fseek(fp,slindex.offset,SEEK_SET);
	fread(buf,slindex.length,1,fp);
	 
		
	num = decode(buf,hzdata,slindex.length); 
	//����dom��ĵ���  
	numofpoint = DM_Dom((char*)hzdata,(short)num,2);

 
	//hzdata��ʱ��Ч
	FindRect(hzdata,numofpoint);              //������Ӿ��Σ������������������m_position,constrect
	//hzdata��ʱ��Ч
	Convert(hzdata,numofpoint);//ת������Ϊcpoints������ʽ���������pointsall,pointsv
*/
	/*delete  buf;
	delete  hzdata;  */
/*
	::LocalUnlock(tempbuf);
	::LocalFree(tempbuf);
	::GlobalUnlock(temphz);
	::GlobalFree(temphz);
	hzdata=NULL;                //�ָ�hzdata,��ʱֻ��h_data��Ч
    fp=NULL;
*/
}

hzPoint CGetHZinfo::FindRect(WORD* hzdata,int numofpoint)
{
	WORD x_max,y_max,x_min,y_min;
	int i;

	x_max=hzdata[0];         //initial the max and min
	y_max=hzdata[1];
	x_min=hzdata[0];
	y_min=hzdata[1];

	for(i=1;i<numofpoint;i++)   //get the relative max,min (x,y)
	{
		if(hzdata[3*i]>x_max)   x_max=hzdata[3*i];
		if(hzdata[3*i+1]>y_max) y_max=hzdata[3*i+1];
		if(hzdata[3*i]<x_min)   x_min=hzdata[3*i];
		if(hzdata[3*i+1]<y_min) y_min=hzdata[3*i+1];
	}
	//set the m_position (around rect) use the local and max,min

	if(x_max>=x_con)
	{
		m_position.right = m_position.left+x_max-x_min+20;     //x_max ����Ԥ����Σ�����ƫ�ҵ���ȡ�Գ� ����
		for(i=0;i<numofpoint;i++) hzdata[3*i]=hzdata[3*i]-(x_min-10); //�޸�ԭ���ݣ�ʹ���ִ�����Ӿ��ε��м�
	}
	else if(x_min+x_max>x_con&&x_max<x_con)               //x_max û����Ԥ����Σ�ȡ��ԭ����ƫ�ң��Գ�ȡ ����
	{ 
		m_position.right=m_position.left+2*x_con-x_min-x_max; //�޸�ԭ���ݣ�ʹ���ִ�����Ӿ��ε��м�
		for(i=0;i<numofpoint;i++) hzdata[3*i]=hzdata[3*i]-(x_min+x_max-x_con);
		 
	}
	else if(x_min+x_max<=x_con)                           //����ƫ�� ��������
	{
		m_position.right=m_position.left+x_min+x_max;
	}
	//decide the bottom:m_position.bottom
	if(y_max>=y_con)                                     //y_max ����������10����λ
	{
		m_position.bottom=m_position.top-y_max-10;
	}
	else if(y_min+y_max>y_con&&y_max<y_con)              //ͬ��
	{ 
		m_position.bottom=m_position.top-y_max-10;
	}
	else if(y_min+y_max<=y_con)                          //����ƫ�� ��������
	{
		m_position.bottom=m_position.top-y_min-y_max;
	}
	//constrect = m_position;                    //����̶���Ӿ��γߴ�

	return hzPoint(m_position.right+2,m_position.top);  ///�������ϵ� b������2��λ
}

BOOL  CGetHZinfo::Convert(WORD* hzdata,int numofpoint)           //���pointsall,pointv
{
	int num,pointofcontour,flag; //the num of contour:local ver

	numofcontour = 0;
	num = 0;
	pointofcontour=0;
	//���㵥������:����numofcontour       
	int i;
	for(i=0;i<numofpoint;i++)
	{
		if((flag=hzdata[3*i+2]&0x0002)==0x0002) num++;
	} 
	if(num==0) return FALSE;
	numofcontour = num;

	//��new����������
	numpercontour = new int[numofcontour];

	////���������ݵ��ڴ�
	//h_data=::GlobalAlloc(GHND,2000*sizeof(WORD)+2*(numofcontour+numofpoint)*sizeof(CPoint));
	//if(h_data==NULL) return FALSE;


	BYTE* ptr = new BYTE(2000*sizeof(WORD)+2*(numofcontour+numofpoint)*sizeof(hzPoint));

	 pointsall = (hzPoint*)(ptr+2000*sizeof(WORD));
	 pointsv = (hzPoint*)(ptr+2000*sizeof(WORD)+(numofcontour+numofpoint)*sizeof(hzPoint));

	num=0;
	int beginend,polyall,polyv;
	beginend=0;                 //��ŵ������������
	polyall=0;                  //index of pointsall
	polyv=0;                    //index of pointsv

	for(i=0;i<numofpoint;i++)
	{ 
		if((flag=hzdata[3*i+2])==0x0001) 
		{
			//work out the ������꣺pointsall   ԭ��Ϊtopleft,����ϵΪx�����ң�y������
			pointsall[polyall].x=hzdata[3*i];
			pointsall[polyall++].y=hzdata[3*i+1];
			// work out the �������꣺pointv
			pointsv[polyv].x=m_position.left+hzdata[3*i];   // ��������
			pointsv[polyv++].y=m_position.top-hzdata[3*i+1];  // ��������??

			pointofcontour++;
		}  
		if((flag=hzdata[3*i+2]&0x0002)==0x0002)
		{
			//work out the ������꣺pointsall
			pointsall[polyall].x=hzdata[3*i];
			pointsall[polyall++].y=hzdata[3*i+1];
			// work out the �������꣺pointv
			pointsv[polyv].x=m_position.left+hzdata[3*i];
			pointsv[polyv++].y=m_position.top-hzdata[3*i+1];

			pointofcontour++;
			//Ϊ��ʹ��polypolygon������һ����ʼ�㣬ʹ�����պ�,����hzdata�е����Ϊbegin
			pointsall[polyall].x=hzdata[3*beginend];                //
			pointsall[polyall++].y=hzdata[3*beginend+1];
			//the index of the contour
			pointsv[polyv].x=m_position.left+hzdata[3*beginend];
			pointsv[polyv++].y=m_position.top-hzdata[3*beginend+1];

			numpercontour[num++]=pointofcontour+1;
			//��ʼ��һ������ļ���
			beginend=i+1;         //��һ��������ʼ��
			pointofcontour=0;     //��һ������������
		}
	}	 
	return TRUE;
}

int  CGetHZinfo::decode(BYTE* sourceBuf, WORD* denstBuf,int num)
{
	BYTE ch1,ch2,loopNum,subMode,x,y,dx,dy;
	int sourcePtr, denstPtr, saveDenstPtr, denstPointNum,totalPoint;
	int j,k;
	sourcePtr=0;
	denstPtr=0;
	saveDenstPtr=denstPtr;
	denstPointNum=0;
	totalPoint=0;
	//AfxMessageBox("decode init is finished");
	for(;;)
	{
		ch1=sourceBuf[sourcePtr++];
		if((ch1&0xc0)==0xc0)                         //11 00 0000 mode
		{                                            //0xc0=11 00 00 00
			//AfxMessageBox("outline begin"); 
			//denstBuf[saveDenstPtr]=denstPointNum%256;
			//denstBuf[saveDenstPtr+1]=denstPointNum/256;
			//denstPointNum=0;
			//saveDenstPtr=denstPtr;
			//denstPtr+=2;
			if(denstPtr>0) denstBuf[denstPtr-1]=0x0003;
			ch2=sourceBuf[sourcePtr++];
			//totalPoint++;
			x=((ch1&0x3f)<<1)|(ch2>>7);                //
			y=ch2&0x7f;                                //0x7f=0111 1111,0x3f=0011 1111
			denstBuf[denstPtr++]=(WORD)x;               //0<x,y<128
			denstBuf[denstPtr++]=(WORD)y;               
			denstBuf[denstPtr++]=0x0001;               //online point
			denstPointNum++;
			totalPoint++;
			if(sourcePtr==num)
			{
				//denstBuf[saveDenstPtr]=denstPointNum%256;
				//denstBuf[saveDenstPtr+1]=denstPointNum/256;
				denstBuf[denstPtr-1]=0x0003;
				return(totalPoint);
			}
			continue;
		}

		if((ch1&0xc0)==0x40)               //  01 00 0000 mode
		{     
			subMode=ch1&0x30;                 //child mode 0x30=0011 0000
			loopNum=ch1&0x0f;                 //loop number point 0x0f=0000 1111
			denstPointNum+=loopNum;
			totalPoint+=loopNum;
			for(j=0;j<loopNum;j++)
			{
				ch1=sourceBuf[sourcePtr++];
				dx=ch1>>4;                       //ǰ��λ 0<dx,dy<16
				dy=ch1&0x0f;                     //����Χ
				switch(subMode)
				{                                  //x,y����������
				case 0x00:
					x+=dx; y+=dy;
					break;
				case 0x10:
					x-=dx; y+=dy;
					break;
				case 0x20:
					x-=dx; y-=dy;
					break;
				case 0x30:
					x+=dx;
					y-=dy;
					break;
				}
				denstBuf[denstPtr++]=(WORD)x;     //x,y��һ����0��128
				denstBuf[denstPtr++]=(WORD)y;
				denstBuf[denstPtr++]=0x0001;
			}
			if(sourcePtr==num)
			{
				//denstBuf[saveDenstPtr]=denstPointNum%256;
				//denstBuf[saveDenstPtr+1]=denstPointNum/256;
				denstBuf[denstPtr-1]=0x0003;
				return(totalPoint);
			}	
			continue;
		}

		if((ch1&0xc0)==0x00)                     //00 00 0000 mode
		{
			loopNum=ch1&0x3f;                     //����λΪѭ������
			denstPointNum+=loopNum;
			totalPoint+=loopNum;
			for(k=0;k<loopNum;k++)
			{
				ch1=sourceBuf[sourcePtr++];
				dx=ch1>>4;
				dy=ch1&0x0f;
				if((dx&0x08)==0x00)                  //0x08=0000 1000
					x+=dx;
				if((dx&0x08)==0x08)
					x-=(dx&0x07);                   //����λΪx����
				if((dy&0x08)==0x00)
					y+=dy;
				if((dy&0x08)==0x08)
					y-=(dy&0x07);
				denstBuf[denstPtr++]=(WORD)x;      //x,y may not 0~128
				denstBuf[denstPtr++]=(WORD)y;
				denstBuf[denstPtr++]=0x0001;
			} 
			if(sourcePtr==num)
			{
				//denstBuf[saveDenstPtr]=denstPointNum%256;
				//denstBuf[saveDenstPtr+1]=denstPointNum/256;
				denstBuf[denstPtr-1]=0x0003;
				return (totalPoint);
			}
			continue;
		}

		if((ch1&0xc0)==0x80)	                 //10 00,0000 mode
		{
			subMode=ch1&0x30;
			switch(subMode)
			{
			case 0x00:                         //
				dx=ch1&0x0f;
				dy=sourceBuf[sourcePtr++];
				if((dx&0x08)==0x00)
					x+=dx;                     //0>dx>16
				if((dx&0x08)==0x08)
					x-=(dx&0x07);
				if((dy&0x80)==0x00)
					y+=dy;                     //0>dy>128
				if((dy&0x80)==0x80)
					y-=(dy&0x7f);              //x,y may not 0~128
				denstBuf[denstPtr++]=x;
				denstBuf[denstPtr++]=y;
				denstBuf[denstPtr++]=0x0001;
				denstPointNum++;
				totalPoint++;
				if(sourcePtr==num)
				{
					//denstBuf[saveDenstPtr]=denstPointNum%256;
					//denstBuf[saveDenstPtr+1]=denstPointNum/256;
					denstBuf[denstPtr-1]=0x0003;
					return(totalPoint);
				} 
				break;
			case 0x10:
				dy=ch1&0x0f;
				dx=sourceBuf[sourcePtr++];
				if((dx&0x80)==0x00)            //0<dx>128
					x+=dx;
				if((dx&0x80)==0x80)
					x-=(dx&0x7f);
				if((dy&0x08)==0x00)            //0>dy>16
					y+=dy;
				if((dy&0x08)==0x08)
					y-=(dy&0x07);
				denstBuf[denstPtr++]=(WORD)x;
				denstBuf[denstPtr++]=(WORD)y;
				denstBuf[denstPtr++]=0x0001;
				denstPointNum++;
				totalPoint++ ;
				if(sourcePtr==num)
				{
					//denstBuf[saveDenstPtr]=denstPointNum%256;
					//denstBuf[saveDenstPtr+1]=denstPointNum/256;
					denstBuf[denstPtr-1]=0x0003;
					return(totalPoint);
				}
				break;
			default:
				dx=sourceBuf[sourcePtr++];
				dy=sourceBuf[sourcePtr++];
				if((dx&0x80)==0x00)                  //0>dx>128
					x+=dx;                         //0>dy>128
				if((dx&0x80)==0x80)
					x-=(dx&0x7f);
				if((dy&0x80)==0x00)
					y+=dy;
				if((dy&0x80)==0x80)
					y-=(dy&0x7f);
				denstBuf[denstPtr++]=(WORD)x;
				denstBuf[denstPtr++]=(WORD)y;
				denstBuf[denstPtr++]=0x0001;
				denstPointNum++;
				totalPoint++;
				if(sourcePtr==num)
				{
					//denstBuf[saveDenstPtr]=denstPointNum%256;
					//denstBuf[saveDenstPtr+1]=denstPointNum/256;
					denstBuf[denstPtr-1]=0x0003;
					return(totalPoint);
				}
				break;
			}
			continue;
		}
	}
}
