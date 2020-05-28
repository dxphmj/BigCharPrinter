#ifndef PRINTTHEAD_H
#define PRINTTHEAD_H

#include <QThread>
#include "ModuleMain.h"

class PrintThead : public QThread //喷墨打印线程
{
	Q_OBJECT

public:
	PrintThead(QObject *parent);
	~PrintThead();

	void closeThread();

protected:
    virtual void run(); 

private:
    volatile bool m_isStop; 
	bool m_bUsingPhotoESwitch;//�ù�翪��
	bool m_bTriggerByHigh;//�ߵ�ƽ����
	bool m_bPhotoESwitchState;//��翪��״̬
	bool m_bPhotoESwitchStatePre;//��翪��ǰһ��״̬
	bool m_bTrigger; //�Ƿ񴥷���ӡ��
	int m_SwitchHande;
	int m_SynchronizerHande;
	int m_bUsingSynchronizer;//�Ƿ�ʹ��ͬ����
	unsigned char* strTempCmd;

private:
	
};

#endif // PRINTTHEAD_H
