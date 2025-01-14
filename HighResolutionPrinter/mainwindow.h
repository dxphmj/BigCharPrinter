﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QQueue>
 
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <QMutex>

#include "ParamSetting.h"

#define BIG_CHAR

#define vsPath  //vs上的点阵字库、多语言字库路径
//#define qtPath   //ubuntu上的点阵字库、多语言字库路径

//用于计算的常量值π
#define PAI 3.1415926535897;

using namespace std;
typedef unsigned char BYTE;

class FilemanageForm;
class FileEditChild;
class ParamSettingForm;
class NozzleClean;
class ClassMessage;
class PrintThead;
class PrintShowThread;
class PrintCreatThread;
class roll;

namespace Ui {
	class MainWindow;
}

struct structRowCol
{
	int m_nRow, m_nCOl;
	structRowCol()
	{
		m_nRow = 1;
		m_nCOl = 1;
	}
	structRowCol(int nRow, int nCol)
	{
		m_nRow = nRow;
		m_nCOl = nCol;
	}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
 	ClassMessage* m_MessagePrint; //打印监控用
    queue<vector<BYTE> > queCtr;//命令队列 
	queue<vector<BYTE> > ForPreQue;//欲打印队列
	CParamSetting m_ParamSetting;
	bool mythreadDynamicBoo;//动态线程开关
	bool boDrawMainPic;//主界面动态绘制开关
	bool m_bPrintNow;
	bool m_bDynamicPrint;

	QMutex boPrintNowLock;

	void RefreshWindow();
	void getCurParam();
	void getSerialTimeDotBuf();

public:
    Ui::MainWindow *ui;
	FilemanageForm *m_fileManage;
	ParamSettingForm *m_paramsetting;
	NozzleClean *m_NozzleClean;

	void DownloadPrintData();
	void CreateCtrlCmd();
	void CreatePrintData();
	void getMessageDot();

	void initPrinter();
	structRowCol m_StructRowCol[301];

public:
	void printerCode(char* writeArr);
	int pulseDelay(int printDelay, int wheelDiameter, int encoderRes); //计算打印开始前的延迟脉冲数
	int pulsePerCol(int colWidth, int wheelDiameter, int encoderRes); //计算每列之间的脉冲数
	
private slots:
    void serialPort_readyRead();
	void fileManageBut_clicked();
	void paraManageBut_clicked();
	void closeBut_clicked();
	void PrintBut_clicked();

	bool eventFilter(QObject *watched, QEvent *event);

	void GetDateTime();
	void showNozzleCleanWidget();

public:
	QTimer  *myTimer;
	PrintThead *m_pPrintThread;
	PrintCreatThread *m_pPrintCreateThread;
	PrintShowThread *m_pPrintShowThread;
};

#endif // MAINWINDOW_H
