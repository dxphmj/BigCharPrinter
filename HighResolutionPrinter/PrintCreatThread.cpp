#include "PrintCreatThread.h"
#include "mainwindow.h"
#include "ClassMessage.h"

PrintCreatThread::PrintCreatThread(QObject *parent)
	: QThread(parent)
{

}

PrintCreatThread::~PrintCreatThread()
{

} 
void PrintCreatThread::run() //��ǰ������������ӡ�����ݷ���ForPreQue������
{    
	int strTempCmdLen = 0;
	MainWindow* theApp = (MainWindow*)(this->parent());

	while(theApp->mythreadDynamicBoo)	 
	{
		if(theApp->ForPreQue.size() >= 2)
		{
			msleep(100);
			continue;
		}
		theApp->getSerialTimeDotBuf();//�޸�bytPrintDataAll����Ӧ���ֽ�����

		theApp->boPrintNowLock.lock();
			theApp->ForPreQue.push(theApp->m_MessagePrint->bytPrintDataAll);				
		theApp->boPrintNowLock.unlock();	
	} 
}
 