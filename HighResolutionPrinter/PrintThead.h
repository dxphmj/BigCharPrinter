#ifndef PRINTTHEAD_H
#define PRINTTHEAD_H

#include <QThread>

#include "ModuleMain.h"


struct structRowCol2
{
	int m_nRow, m_nCOl;
	structRowCol2()
	{
		m_nRow = 1;
		m_nCOl = 1;
	}
	structRowCol2(int nRow, int nCol)
	{
		m_nRow = nRow;
		m_nCOl = nCol;
	}
};

 

class PrintThead : public QThread //喷墨打印线程
{
	Q_OBJECT

public:
	PrintThead(QObject *parent);
	~PrintThead();

	void closeThread();
	void OpenCom();
	void initPrinter();
	structRowCol2 m_StructRowCol[301];

 private slots:
    void serialPort_readyRead();

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

private://������ؾ��
	int fd2; 
	int read_result;
	int write_result;
	
};

#endif // PRINTTHEAD_H
