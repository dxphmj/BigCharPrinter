#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QQueue>
 
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef unsigned char BYTE;

class FilemanageForm;
class ParamSettingForm;
class ClassMessage;
class PrintThead;
class PrintShowThread;
class PrintCreatThread;

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
 	ClassMessage* m_PrinterMes; //��ӡ�����
    queue<vector<BYTE>> queCtr;//������� 
	queue<vector<BYTE>> ForPreQue;//����ӡ����

	bool m_bPrintNow;
	bool m_bDynamicPrint;

	void RefreshWindow();

private:
    Ui::MainWindow *ui;
	FilemanageForm *m_fileManage;
	ParamSettingForm *m_paramsetting;

private slots:
	void fileManageBut_clicked();
	void paraManageBut_clicked();
	void closeBut_clicked();
	void PrintBut_clicked();

	bool eventFilter(QObject *watched, QEvent *event);

	void GetDateTime();

public:
	QTimer  *myTimer;
	PrintThead *m_pPrintThread;
	PrintCreatThread *m_pPrintCreateThread;
	PrintShowThread *m_pPrintShowThread;
};

#endif // MAINWINDOW_H
