#include "PrintShowThread.h"
#include "mainwindow.h"
#include "ClassMessage.h"

PrintShowThread::PrintShowThread(QObject *parent)
	: QThread(parent)
{

}

PrintShowThread::~PrintShowThread()
{

}

void PrintShowThread::run()
{    
	int strTempCmdLen = 0;
	MainWindow* theApp = (MainWindow*)(this->parent());

	//�綯̬��ӡ��̬��ʾ��������߼������Ż�

	int pixSize = 4; 
	
	while(theApp->mythreadDynamicBoo)
	{
		while(theApp->boDrawMainPic)
		{
			//if(theApp->ForPreQue.size() >= 2)///////�Ժ�ɾ��
			//{
			//	theApp->m_MessagePrint->intMesDis = theApp->ForPreQue.front();;
			//	theApp->ForPreQue.pop();
			//}

			//theApp->m_MessagePrint->DrawAllDynamic(theApp->m_painter);	
			theApp->update();
			msleep(10);
		}
	}
}
 