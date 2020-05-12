#include "PrintThead.h"

//#define RUN_BY_DEVICE 

#ifdef RUN_BY_DEVICE
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

#endif
#include "mainwindow.h"
#include "ClassMessage.h"


PrintThead::PrintThead(QObject *parent)	: QThread(parent)
{
 	m_isStop = false;

	m_bUsingPhotoESwitch = true;
	m_bTriggerByHigh = false;
	m_bPhotoESwitchState = false;
	m_bPhotoESwitchStatePre = false;
	m_bTrigger = false;
	m_bUsingSynchronizer = true;

	#ifdef RUN_BY_DEVICE
		//���ʹ�ù�翪�������Ӧ���豸
		//���ʹ��ͬ���������Ӧ���豸
	    //Ӳ���豸��������һ���������򣬰���ѹ������������翪�أ�ͬ��������ͷ����IO��

		char gpio[MAX],cmd[MAX];
		char *leds = "/dev/leds";
		LedOnOffTimes = MAX;
		 
		if((m_SynchronizerHande = open(leds, O_RDWR|O_NOCTTY|O_NDELAY))<0)
			printf("open %s failed\n",leds);   
		else
    		printf("open %s success\r\n",leds);	

	#endif

}

PrintThead::~PrintThead()
{
	#ifdef RUN_BY_DEVICE
		close(m_SynchronizerHande);
	#endif

}

void PrintThead::closeThread()
{    
	m_isStop = true;
} 

void PrintThead::run()
{    
	int strTempCmdLen = 0;
	MainWindow* theApp = (MainWindow*)(this->parent());

	//������


	while (1) 
	{
		if(m_isStop) 
			continue; 

		if(!theApp->m_bPrintNow) 
			continue; 

		//��ù�翪�ص�״̬
		#ifdef RUN_BY_DEVICE
			close(m_SynchronizerHande);
	    #endif
		//���ʹ�ù�翪�أ����Ҵ��������ӡ�������������ж��ǣ���ǰ״̬��ǰһ��״̬��һ���������ػ��½��أ�
        if (theApp->queCtr.size()>0) //��tempQueVec���ݷ��͸���ؿ���IO
		{
			vector<BYTE> tempQueVec = theApp->queCtr.front();
			theApp->queCtr.pop();
			strTempCmdLen = tempQueVec.size();
			//strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
		}
		else if (theApp->m_MessagePrint->boPrintNow) //��ӡ��һ������
		{
 			if (theApp->m_MessagePrint->bytPrintDataAllOrder.size() > 11) //��bytPrintDataAllOrder���ݷ��͸���ͷ����IO
			{
			//	strTempCmd=(LPTSTR)VEC2ARRAY(theApp.myclassMessage.bytPrintDataAllOrder,theApp.myclassMessage.bytPrintDataAllOrder.size());
			    strTempCmdLen = theApp->m_MessagePrint->bytPrintDataAllOrder.size();
				theApp->m_MessagePrint->boPrintNow = false;
			}			 
		}
		else if(!theApp->m_MessagePrint->boPrintNow) //��ӡ�ڶ���������������
		{
			if (theApp->m_MessagePrint->boDynamic) //����ж�̬���ݣ����ӡ��̬����
			{
				if (theApp->ForPreQue.size()>0)
				{
					vector<BYTE> tempQueVec = theApp->ForPreQue.front();
					theApp->ForPreQue.pop();
					strTempCmdLen = tempQueVec.size();
					//strTempCmd = (LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
					if (strTempCmdLen > 11)
					{
						//��̬��ʾ���										
						theApp->m_MessagePrint->intMesDis = tempQueVec;										 
					} 
					else //����Ĭ�ϵ�ָ������
					{
						//strTempCmd=(LPTSTR)readArr;
						//strTempCmdLen=8;
					}
				} 
				else //����Ĭ�ϵ�ָ������
				{
					//strTempCmd=(LPTSTR)readArr;
					//strTempCmdLen=8;
				}
			} 
			else //���û�ж�̬�������ӡ��̬����
			{
				if (theApp->m_MessagePrint->bytPrintDataAll.size()>11)
				{
					//strTempCmd = (LPTSTR)VEC2ARRAY(theApp.m_MessageEdit.bytPrintDataAll,theApp.m_MessagePrint.bytPrintDataAll.size());
					strTempCmdLen = theApp->m_MessagePrint->bytPrintDataAll.size();
					if (strTempCmdLen < 12) //����Ĭ�ϵ�ָ������
					{
						//strTempCmd=(LPTSTR)readArr;
						//strTempCmdLen=8;
						
					}
					theApp->m_MessagePrint->intMesDis = theApp->m_MessagePrint->bytPrintDataAll;
					theApp->update();
				}
			}
		}
		

		//���ղɼ����ٶȽ��д�ӡ����ÿ�����ݰ�˳��ͨ����������IO���򴮿������
		//Ϊ�򻯿��ƣ�ÿ�β��õĴ�ӡ�ٶȲ���
		//�ٶȷŵ����߳�MainWindow��ʱ���н��вɼ�������ֻ�ǲ���
			 
	    //��strTempCmd д������ Ŀǰ��֪��unsigned char���Դ��ֽ� 0x11 == 00010001  bool a[8]
		//����Ĺ�������ͷ������ʵ��

		//1 ����翪�ص��ն� ��ȡ��翪���½��� �����������
		
		//2 ���ٶȿ���ʱ�жϣ����ж��д�ӡÿһ��
		 

 		msleep(1);  
	}
}
 