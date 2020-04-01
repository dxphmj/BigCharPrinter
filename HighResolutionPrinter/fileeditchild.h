#ifndef FILEEDITCHILD_H
#define FILEEDITCHILD_H

#include <QWidget>
#include <QLineEdit>
#include "ClassMessage.h"
#include "TextOBJ.h"
#include "backend\zint.h"

class keyboard;
class numkeyboard;
class language;
class FileManageChild;

#include "ModuleMain.h"
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
	CTextOBJ m_TextObj;
	FileManageChild *m_FileMangeChild;
	ModuleMain m_TimeShow;

	/*enum LineeditChangeEnum{ WordLineedit = 0,barLineEdit = 1,QRLineEdit = 2,DMLineEdit = 3};
	int m_LineeditChange;
	void lineeditChange();*/

	void DrawBackFrame(QPainter *qFramePainter);
	void MouseBeenPressed(QMouseEvent *event);
	void MouseBeenReleased(QMouseEvent *event);
	void MouseMoved(QMouseEvent *event);
	void GetObjSettingsFromScreen();
	void Create2Dcode(int nType,QString strContent);
	void CreateQrcode(int nType,QString strContent);
	void CreateDMcode(int nType,QString strContent);
	void ReadBmp(char* strFileName);
	void LoadLocalFile();
	int  GetCharLenFromFont(string txtFont, bool LineOrRow); //�������壬����õ�ÿ���ַ�����ʾ����
	void PushBackTextOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW);
	QString getChinese(QString &str);
	void PushBackSerialNumberOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent, int txtLineStart, int txtRowStart, int txtSS, int txtSW,int countnumber);
	void ShowText();
	void ChangeTime();
	string TimeFormatToText(QString InPutTimeFormat,int tempstrETimeOffSet, int tempintTimeOffSet, int tempstrTimeOffSetUint);
	
	zint_symbol resetQRCode();
	zint_symbol resetDMCode();
	void GenerateBarCodeBmp();
	
	QString getNum(QString str);//��ȡlabel�ؼ�����

	void ChangeBmpWH(QImage& pImage,double nS);//����ͼƬ�ĳ��ȺͿ��
	
	void informationMessage(string errortext);//zint���󵯴�

	QString bmpFileRelativePath;//��ȡbmpͼƬ�����·��
	int degreenum;
	int degreenumQr;
	int degreenumDM;
	float Zoomfactor; 
	float ZoomfactorQr;
	float ZoomfactorDM;
	//bool boolObjBnSel;
 	keyboard  *keyboardWidget;
	language *languageWidget;
	numkeyboard *numkeyboardWidget;
	QString SerialNumber_string;
	int SerialNumber_number;
	int SerialNumber_length;
	int Serialfirst;
	int serialcount;
	int Barheight;
	int nW;
	int nH;
	QPoint pointMousePressed;//��¼����
	bool boolMousePressed;//�ж�����Ƿ񱻰���
	bool boolHWchange;//�жϸı���Ǹ߶Ȼ��ǿ��

	//Arabicϵ��
	QString disposeinputtext( QString inputtext );//����������
	QString ConvertWCHARToHex(QString Data, long nDataLength);//QStringת16����
	void W2C(wchar_t w_cn , char c_cn[]);
	QString HexStrToCString(QString HexStr);//16����תQString
	QString ArabicLan(QString inputstring);
	QVector<QString> Arabicsplit(QString str);
	void ClickChooseLanguage();

	//���ϵ��
	int m_ShiftLineEditType;//��ǰ��εı༭��ѡ��

	QString fileName;

public:
	Ui::FileEditChild* ui;
	
	QString str1;
public slots:
	void wordLineEdit_clicked();
	void barCodeLineEdit_clicked();
	void QRCodeLineEdit_clicked();
	void DMCodeLineEdit_clicked();
	void ChangeTabLineEdit();
	/*void ChineseTabLineEdit();*/
	void KeyboardConceal_clicked();

	//void ChangeBmpWH(QImage& pImage,double nS);//����ͼƬ�ĳ��ȺͿ��
	void PreviewBmpChange();
	void OnEnChangeEditInput_clicked();//arabic����
private slots:
	void variableTextBut_clicked();
	void variableBarCodeBut_clicked();
	void variableQRBut_clicked();
	void variableDMBut_clicked();
	void customTimeBut_clicked();
	void selBmpBut_clicked();
	void delBut_clicked();

	void newTextBut_clicked();
	void newBarCodeBut_clicked();
	void newQRBut_clicked();
	void newDMBut_clicked();
	void newSerialNumber_click();
	void SerialNumberstartchange();
	void saveasBut_clicked();
	void saveBut_clicked();
	void internalTextAddBut_clicked();
	void internalTextRedBut_clicked();
	void moveUpBut_clicked();
	void moveDownBut_clicked();
	void moveLeftBut_clicked();
	void moveRightBut_clicked();
	void showNumCheckBox_clicked();
	void heightBarCodeAddBut_clicked();
	void heightBarCodeRedButt_clicked();
	void newBmpBut_clicked();
	void addTimeBut_clicked();
	void concelTimeBut_clicked();
	void SkewComBox_clicked();
	void refreshTimeBut_clicked();
	void newTimeBut_clicked();

	void SkewSkewValueEdit_clicked();
	void initialValSerialLineEdit_clicked();
	void termValSerialLineEdit_clicked();
	void startValSerialLineEdit_clicked();
	void stepLenSerialLineEdit_clicked();
	void reptCountSerialLineEdit_clicked();
	void digitSerialLineEdit_clicked();
	void heightBmpShowBmpLineEdit_clicked();
	void widthShowBmpLineEdit_clicked();
	void ScrollBarChanged(int);
	void rimwideAddBut_clicked();
	void rimwideRedButt_clicked();
	void whitespaceAddBut_clicked();
	void whitespaceRedButt_clicked();

	void ChangePixel();

	void shiftNumShowLineEdit_clicked();
	void textLenShowLineEdit_clicked();
	void startTimeShowSft1LineEdit_clicked();
	void textIDShowSft1LineEdit_clicked();
	void startTimeShowSft2LineEdit_clicked();
	void textIDShowSft2LineEdit_clicked();
	void startTimeShowSft3LineEdit_clicked();
	void textIDShowSft3LineEdit_clicked();
	void startTimeShowSft4LineEdit_clicked();
	void textIDShowSft4LineEdit_clicked();


protected:
	//void paintEvent(QPaintEvent *event);
	void paintDot();
	bool eventFilter(QObject *watched, QEvent *event);

public:
	void deleteChar();
	void setText2wordLineEdit();
	void setText2shiftNumShowLineEdit();
	void setText2barCodeLineEdit();
	void setText2QRCodeLineEdit();
	void setText2DMCodeLineEdit();

	void PreviewBmp(QString fileNameAAA,int nW,int nH);

};

#endif // FILEEDITCHILD_H
