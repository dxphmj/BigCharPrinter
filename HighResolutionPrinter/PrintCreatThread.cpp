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
			sleep(100);
			continue;
		}
		//getSerialTimeDotBuf();//�޸�bytPrintDataAll����Ӧ���ֽ�����

		theApp->boPrintNowLock.lock();
			theApp->ForPreQue.push(theApp->m_MessagePrint->bytPrintDataAll);				
		theApp->boPrintNowLock.unlock();	
	} 
}
 