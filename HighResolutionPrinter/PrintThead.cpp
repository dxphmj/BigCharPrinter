#include "PrintThead.h"

//#define RUN_BY_DEVICE 

//#ifdef RUN_BY_DEVICE
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>

//#endif
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

		//����ͷ������״̬
		//æ - continue

		//���������ϸ��пռ䣩��ִ�д�ӡ���򣻷���ѭ��

		//��ù�翪�ص�״̬
		#ifdef RUN_BY_DEVICE
			close(m_SynchronizerHande);
	    #endif
        if (theApp->queCtr.size()>0) //��tempQueVec���ݷ��͸���ؿ���IO
		{
			vector<BYTE> tempQueVec = theApp->queCtr.front();
			theApp->queCtr.pop();
			strTempCmdLen = tempQueVec.size();
			//strTempCmd=(LPTSTR)VEC2ARRAY(tempQueVec,tempQueVec.size());
		}
		else if (theApp->m_MessagePrint->boPrintNow) //��ӡ��һ������
		{
			ModuleMain m_ModuleMain;
 			if (theApp->m_MessagePrint->bytPrintDataAllOrder.size() > 11) //��bytPrintDataAllOrder���ݷ��͸���ͷ����IO
			{
			    //strTempCmd = (LPTSTR) m_ModuleMain.VEC2ARRAY(theApp->m_MessagePrint->bytPrintDataAllOrder,theApp->m_MessagePrint->bytPrintDataAllOrder.size());
			    strTempCmdLen = theApp->m_MessagePrint->bytPrintDataAllOrder.size();
				//strTempCmd = new unsigned short[strTempCmdLen];
				strTempCmd = m_ModuleMain.VEC2ARRAY(theApp->m_MessagePrint->bytPrintDataAllOrder,theApp->m_MessagePrint->bytPrintDataAllOrder.size());

				/*
				unsigned char s0 = strTempCmd[0];
				unsigned char s1 = strTempCmd[1];
				unsigned char s2 = strTempCmd[2];
				unsigned char s3 = strTempCmd[3];
				unsigned char s4 = strTempCmd[4];
				unsigned char s5 = strTempCmd[5];
				unsigned char s6 = strTempCmd[6];
				unsigned char s7 = strTempCmd[7];
				unsigned char s8 = strTempCmd[8];
				unsigned char s9 = strTempCmd[9];
				unsigned char s10 = strTempCmd[10];
				unsigned char s11 = strTempCmd[11];
				*/

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
		
    char iTest[1];
    char *Nozzle_node = "/dev/Nozzle_ctl";

    /*O_RDWR��д��,O_NDELAY��������ʽ*/
    if((fd2 = open(Nozzle_node,O_RDWR))<0)
    {
        printf("Nozzle open %s failed",Nozzle_node);
    }
    else
    {
        read_result = read(fd2,iTest,1);
        if(read_result == 0)
        {
            while (1)
			{
				write_result = write(fd2,strTempCmd,8);
				if (write_result)
				{
					free(strTempCmd);
					break;
				}
				/*if(write_result == -1)
				{
					printf("Write is failed!\n");
				}
					else
				{
					printf("Write is success!\n");
				}*/
				msleep(1);
			}
			
        }
        else
        {
            printf("The system is busy now!\n");
        }
       
        //read_result = read(fd2,buffer,1);
    }
    ::close(fd2);


		//���ղɼ����ٶȽ��д�ӡ����ÿ�����ݰ�˳��ͨ����������IO���򴮿������
		//Ϊ�򻯿��ƣ�ÿ�β��õĴ�ӡ�ٶȲ���
		//�ٶȷŵ����߳�MainWindow��ʱ���н��вɼ�������ֻ�ǲ���
			 
	    //��strTempCmd д��������char�� byte��strTempCmdLen, ���ܰ��� ��ӡ�ٶ� V
		//����Ĺ�������ͷ������ʵ��
		//write(fd,strTempCmd,strTempCmdLen);
		
		//���ʹ�ù�翪�أ����Ҵ��������ӡ�������������ж��ǣ���ǰ״̬��ǰһ��״̬��һ���������ػ��½��أ�
		//1 ����翪�ص��ն� ��ȡ��翪���½��� �����������
		
		//2 ���ٶȿ���ʱ�жϣ����ж��д�ӡÿһ��
		 

 		msleep(1);  
	}
}

/*
  write() 
  {
	   1�� ͨ�� write() ��������
	   2���������ӡ�ٶȶ�ʱʱ��
	   3�� ����翪���жϣ�����½���
   }

   �ڹ�翪�ص��жϴ������� ����ʱ�жϣ�
   �ڶ�ʱ�жϴ������и��ݵ�ǰ��ӡ��д�˿ڡ�
*/
 