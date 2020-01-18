#ifndef FILEEDITCHILD_H
#define FILEEDITCHILD_H

#include <QWidget>
#include "ClassMessage.h"
#include <QLineEdit>

class keyboard;
class language;
class FileManageChild;

namespace Ui {
	class FileEditChild;
}

class FileEditChild : public QWidget
{
	Q_OBJECT

public:
	FileEditChild(QWidget *parent = 0);
	~FileEditChild();
	ClassMessage m_PrinterMes;
	FileManageChild *m_FileMangeChild;
	//int QrecodeMatrix[25][25];

	void mousePressEvent(QMouseEvent *event);
	void Create2Dcode(int nType,QString strContent);
	void CreateQrcode(int nType,QString strContent);
	void CreateDMcode(int nType,QString strContent);
	void ReadBmp(char* strFileName);
	void LoadLocalFile();
	void PushBackTextOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent,
		int txtRowSize, int txtLineSize, int txtLineStart, int txtRowStart, int txtSS, int txtSW);
	void GetSelObjNum();
	void ShowText();
	
	QString aaaa;	
	int degreenum;
	int degreenumQr;
	int degreenumDM;
	float Zoomfactor; 
	float ZoomfactorQr;
	float ZoomfactorDM;

	keyboard  *keyboardWidget;

private:
	Ui::FileEditChild* ui;
	
	language  *languageWidget;
	//keyboard* key;
	QString str1;

private slots:
	void variableTextBut_clicked();
	void customTimeBut_clicked();
	void selBmpBut_clicked();
	void delBut_clicked();
	void wordLineEdit_clicked();
	void barCodeLineEdit_clicked();
	void QRCodeLineEdit_clicked();
	void DMCodeLineEdit_clicked();
	void newTextBut_clicked();
	void newBarCodeBut_clicked();
	void newQRBut_clicked();
	void newDMBut_clicked();
	void saveasBut_clicked();
	void saveBut_clicked();
	void moveUpBut_clicked();
	void moveDownBut_clicked();
	void moveLeftBut_clicked();
	void moveRightBut_clicked();
	void showNumCheckBox_clicked();
	void degreeBarCodeAddBut_clicked();
	void degreeBarCodeRedButt_clicked();
	void heightBarCodeAddBut_clicked();
	void heightBarCodeRedButt_clicked();
	void degreeQRAddBut_clicked();
	void degreeQRRedButt_clicked();
	void degreeDMAddBut_clicked();
	void degreeDMRedButt_clicked();

	void newBmpBut_clicked();

	void zoomBarCodeAddBut_clicked();
	void zoomBarCodeRedBut_clicked();
	void zoomQRAddBut_clicked();
	void zoomQRRedBut_clicked();
	void zoomDMAddBut_clicked();
	void zoomDMRedBut_clicked();
	
protected:
	//void paintEvent(QPaintEvent *event);
	void paintDot();
	bool eventFilter(QObject *watched, QEvent *event);

public:
	void hideKB();
	void languageWidgetCall();
	void returnKB();
	void deleteChar();

	//void getValA(QString str);
};

#endif // FILEEDITCHILD_H
