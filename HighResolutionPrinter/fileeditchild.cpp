#include "ui_fileeditchild.h"
#include "lineedit_click.h"
#include "fileeditchild.h"
#include <QTableWidget>
#include <QMouseEvent>
#include "backend\zint.h"
#include <QFileDialog>
#include "filemanageform.h"
#include "filemanagechild.h"
#include "ui_filemanagechild.h"
#include "keyboard.h"
#include "time.h"
FileEditChild::FileEditChild(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::FileEditChild)
{
	ui->setupUi(this);

	connect(ui->variableTextBut,SIGNAL(clicked()),this,SLOT(variableTextBut_clicked()));
	//connect(ui->customTimeBut,SIGNAL(clicked()),this,SLOT(customTimeBut_clicked()));
	connect(ui->selBmpBut,SIGNAL(clicked()),this,SLOT(selBmpBut_clicked()));
	connect(ui->delBut,SIGNAL(clicked()),this,SLOT(delBut_clicked()));
	connect(ui->wordLineEdit,SIGNAL(clicked()),this,SLOT(wordLineEdit_clicked()));
	connect(ui->barCodeLineEdit,SIGNAL(clicked()),this,SLOT(barCodeLineEdit_clicked()));
	connect(ui->QRCodeLineEdit,SIGNAL(clicked()),this,SLOT(QRCodeLineEdit_clicked()));
	connect(ui->DMCodeLineEdit,SIGNAL(clicked()),this,SLOT(DMCodeLineEdit_clicked()));
	connect(ui->newTextBut,SIGNAL(clicked()),this,SLOT(newTextBut_clicked()));
	connect(ui->newBarCodeBut,SIGNAL(clicked()),this,SLOT(newBarCodeBut_clicked()));
	connect(ui->newQRBut,SIGNAL(clicked()),this,SLOT(newQRBut_clicked()));
	connect(ui->newDMBut,SIGNAL(clicked()),this,SLOT(newDMBut_clicked()));

	connect(ui->moveUpBut,SIGNAL(clicked()),this,SLOT(moveUpBut_clicked()));
	connect(ui->moveDownBut,SIGNAL(clicked()),this,SLOT(moveDownBut_clicked()));
	connect(ui->moveLeftBut,SIGNAL(clicked()),this,SLOT(moveLeftBut_clicked()));
	connect(ui->moveRightBut,SIGNAL(clicked()),this,SLOT(moveRightBut_clicked()));
	connect(ui->showNumCheckBox,SIGNAL(stateChanged()),this,SLOT(showNumCheckBox_clicked()));
	//connect(ui->degreeBarCodeAddBut,SIGNAL(clicked()),this,SLOT(degreeBarCodeAddBut_clicked()));
	//connect(ui->degreeBarCodeRedBut,SIGNAL(clicked()),this,SLOT(degreeBarCodeRedButt_clicked()));
	connect(ui->zoomBarCodeAddBut,SIGNAL(clicked()),this,SLOT(zoomBarCodeAddBut_clicked()));
	connect(ui->heightBarCodeAddBut,SIGNAL(clicked()),this,SLOT(heightBarCodeAddBut_clicked()));
	connect(ui->heightBarCodeRedBut,SIGNAL(clicked()),this,SLOT(heightBarCodeRedButt_clicked()));
	
	//connect(ui->degreeQRAddBut,SIGNAL(clicked()),this,SLOT(degreeQRAddBut_clicked()));
	//connect(ui->degreeQRRedBut,SIGNAL(clicked()),this,SLOT(degreeQRRedButt_clicked()));
	//connect(ui->degreeDMAddBut,SIGNAL(clicked()),this,SLOT(degreeDMAddBut_clicked()));
	//connect(ui->degreeDMRedBut,SIGNAL(clicked()),this,SLOT(degreeDMRedButt_clicked()));
	connect(ui->zoomBarCodeRedBut,SIGNAL(clicked()),this,SLOT(zoomBarCodeRedBut_clicked()));
	//connect(ui->zoomQRAddBut,SIGNAL(clicked()),this,SLOT(zoomQRAddBut_clicked()));
	//connect(ui->zoomQRRedBut,SIGNAL(clicked()),this,SLOT(zoomQRRedBut_clicked()));
	//connect(ui->zoomDMAddBut,SIGNAL(clicked()),this,SLOT(zoomDMAddBut_clicked()));
	//connect(ui->zoomDMRedBut,SIGNAL(clicked()),this,SLOT(zoomDMRedBut_clicked()));
	//connect(ui->degreeQRAddBut,SIGNAL(clicked()),this,SLOT(degreeQRAddBut_clicked()));
	//connect(ui->degreeQRRedBut,SIGNAL(clicked()),this,SLOT(degreeQRRedButt_clicked()));
	//connect(ui->degreeDMAddBut,SIGNAL(clicked()),this,SLOT(degreeDMAddBut_clicked()));
	//connect(ui->degreeDMRedBut,SIGNAL(clicked()),this,SLOT(degreeDMRedButt_clicked()));
	connect(ui->newTimeBut,SIGNAL(clicked()),this,SLOT(newTimeBut_clicked()));

	connect(ui->saveasBut,SIGNAL(clicked()),this,SLOT(saveasBut_clicked()));
	connect(ui->saveBut,SIGNAL(clicked()),this,SLOT(saveBut_clicked()));
	connect(ui->addTimeBut,SIGNAL(clicked()),this,SLOT(addTimeBut_clicked()));
	connect(ui->SkewComBox,SIGNAL(currentIndexChanged()),this,SLOT(SkewComBox_clicked()));
	connect(ui->refreshTimeBut,SIGNAL(clicked()),this,SLOT(refreshTimeBut_clicked()));
    ui->wordLineEdit->setFocus();

	keyboardWidget = new keyboard(ui->typeTab);
	keyboardWidget->setVisible(false);
	
	ui->editPreviewText->installEventFilter(this);
	ui->editPreviewText->viewport()->installEventFilter(this);

	ui->typeTab->setStyleSheet("QTabWidget:pane{ \
							  boder: -2px solid white;top: -2px;background-color:rgb(0, 0, 230);}\
							  QTabBar::tab{font:'楷体' 16pt;color: white;height:50px; width:114px; background-color:rgb(0, 0, 230); margin-right: 2px; margin-bottom:-2px;}\
							  QTabBar::tab:selected{border:1px solid white;border-bottom-color: none;}\
							  QTabBar::tab:!selected{border-bottom: 3px solid white;}\
							  ");
	ui->showNumCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									  QCheckBox{color:rgb(255, 255, 255);}\
									  ");
	ui->reverseCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
									  QCheckBox{color:rgb(255, 255, 255);}\
									  ");
	ui->reverseBmpCheckBox->setStyleSheet("QCheckBox::indicator {width: 27px; height: 27px;}\
		                                  QCheckBox{color:rgb(255, 255, 255);}\
										 ");
	ui->moveUpBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveup.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveup.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->moveDownBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/movedown.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/movedown.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->moveLeftBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveleft.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveleft.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->moveRightBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/moveright.bmp);border-radius:5px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								QPushButton:pressed{border-image: url(:/Images/moveright.bmp);border: 1px solid rgb(12 , 138 , 235);\
								padding-left:7px;padding-top:7px;}\
								"); 
	ui->degreeTextShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->internalShowTextLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->degreeTimeShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->currentValShowTimeLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->degreeSerialShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->currentValShowSerialLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->degreeBmpShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->heightBmpShowBmpLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->widthShowBmpLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->degreeBarCodeShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->zoomShowBarCodeLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	ui->heightBarCodeShowQRLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
    //ui->degreeQRShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->zoomShowQRLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->degreeDMShowLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 
	//ui->zoomShowDMLab->setStyleSheet("background-color: rgb(67,51, 139);color: rgb(255, 255, 255);"); 


	ui->typeBarCodeComBox->addItem(QStringLiteral("EANX"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("CODE39"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("CODE93"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("CODE128"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("UPCA"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("UPCE"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("ITF14"));
	ui->typeBarCodeComBox->addItem(QStringLiteral("PDF417"));
	ui->typeBarCodeComBox->setCurrentIndex(3);

	ui->typeBarCodeComBox->setCurrentIndex(1);

	ui->sideLenQRComBox->addItem(QStringLiteral("21 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("25 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("29 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("33 px"));
	ui->sideLenQRComBox->addItem(QStringLiteral("37 px"));
	ui->typeBarCodeComBox->setCurrentIndex(1);

	degreenum=0;
	degreenumQr=0;
	degreenumDM=0;
	Zoomfactor=1;
	ZoomfactorQr=1;
	ZoomfactorDM=1;

 //	m_PrinterMes.ReadObjectsFromXml("User\\Label\\qr.lab");
    //m_PrinterMes.ReadObjectsFromXml("User\\Label\\qr.lab");
	//m_PrinterMes.ReadBmp("D:\\1.bmp");
	//Create2Dcode(8,"1");
	ui->SkewSkewValueEdit->setText("0");
	ui->SkewUUnitlistWidget->addItem("Year");
	ui->SkewUUnitlistWidget->addItem("Month");
	ui->SkewUUnitlistWidget->addItem("Day");
	ui->SkewUUnitlistWidget->addItem("Hour");
	ui->SkewUUnitlistWidget->addItem("Minute");
	ui->fontTypeTimeComBox->addItem("5x5");
	ui->fontTypeTimeComBox->addItem("7x5");
	ui->fontTypeTimeComBox->addItem("12x12");
	ui->fontTypeTimeComBox->addItem("16x12");
	ui->fontTypeTimeComBox->setCurrentIndex(0);
	ui->SkewComBox->addItem("OFF");
	ui->SkewComBox->addItem("ON");
	ui->SkewComBox->setCurrentIndex(0);
	ui->FormatlistWidget->addItem("%Y - Year (0000 - 9999)");
	ui->FormatlistWidget->addItem("%y - Year (00 - 99)");
	ui->FormatlistWidget->addItem("%m - Month (01 - 12)");
	ui->FormatlistWidget->addItem("%d - Day  (01 - 31)");
	ui->FormatlistWidget->addItem("%H - Hour (00 - 23)");
	ui->FormatlistWidget->addItem("%h - Hour (01 - 12)");
	//ui->FormatlistWidget->addItem("%p - A.M. / P.M. "));
	ui->FormatlistWidget->addItem("%M - Minute (00 - 59)");
	ui->FormatlistWidget->addItem("%S - Second (00 - 59)");
	ui->FormatlistWidget->addItem("%U - Week, Sunday first (00 - 53)");
	ui->FormatlistWidget->addItem("%W - Week, Monday first (00 - 53)");
	//ui->FormatlistWidget->addItem("%V - Weekday (1 - 7; Sunday is 1)");
	//ui->FormatlistWidget->addItem("%v - Weekday (1 - 7; Monday is 1)"));
	ui->FormatlistWidget->addItem("%w - Weekday (0 - 6; Sunday is 0)");
	//ui->FormatlistWidget->addItem("%w - Weekday (0 - 6; Monday is 0)"));
	//ui->FormatlistWidget->addItem("%Q - Quarter number of year (1 - 4)"));
	ui->FormatlistWidget->addItem("%j - Day number of year (001 - 366)");
	ui->FormatlistWidget->addItem("%a - Abbreviated weekday name");
	ui->FormatlistWidget->addItem("%A - Full weekday name");
	ui->FormatlistWidget->addItem("%b - Abbreviated month name");
	ui->FormatlistWidget->addItem("%B - Full month name");
	ui->FormatlistWidget->addItem("%p - am / pm");

}

FileEditChild::~FileEditChild()
{
}

void FileEditChild::Create2Dcode(int nType,QString strContent)
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;
	int longth;
	int derta;
	derta=1;
	longth=0;
	error_number = 0;
	rotate_angle = 0;
	//QString angle1=ui->degreeBarCodeShowLab->text();//暂时注掉
	//int angle2=angle1.toInt();
	//rotate_angle = angle2;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = nType;
//	if(nType == 20 || nType == 8)
	my_symbol->height = 5;	 //此高度值会影响最终生成条形码点阵图的高度，且最小值为5

	my_symbol->scale =1;
	batch_mode = 0;
	mirror_mode = 0;

	my_symbol->whitespace_width=6;//改变条形码两边空白区域宽度,空白区域宽度会影响条形码的宽度，只会增加条码左右两侧的空白
	my_symbol->output_options= 1; //有无边框之类的控制;1:无边框，2：上下两条边界线，3：四条边框
	my_symbol->border_width=0;//改变边框宽度           //条形码高度显示问题，所以边框显示也存在问题

	int show_hrt;            //设置为1 显示文本在条码图片下面 设置为0 则不显示
	if (ui->showNumCheckBox->isChecked())
	{
		my_symbol->show_hrt=1;
	} 

	else  my_symbol->show_hrt=0;


	/* 
	char * QRTEXT = W2A(str.GetBuffer(0));	
	std::string strTmp = ASCToUTF8(QRTEXT);*/
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
	longth = my_symbol->bitmap_height;
/*	//longth = my_symbol->width;
	QString zoomvalue=ui->zoomShowBarCodeLab->text();
	int zoomvalue1=zoomvalue.toInt();
	derta = longth-zoomvalue1;     //将21改为zoomShowBarCodeLab中的值
	//my_symbol->scale =proportion ;
	//error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
	*/
	generated = 1;
  
	int xPos=0;
	int yPos=0;
	for(int i=0;i<m_PrinterMes.OBJ_Vec.size();i++)
	{
		if (m_PrinterMes.OBJ_Vec.at(i).booFocus)
		{
			m_PrinterMes.OBJ_Vec.at(i).booFocus=false;
			yPos = m_PrinterMes.OBJ_Vec.at(i).intLineStart;
			xPos = m_PrinterMes.OBJ_Vec.at(i).intRowSize+m_PrinterMes.OBJ_Vec.at(i).intRowStart;
		}
	}

	OBJ_Control bmpObj;
	bmpObj.intLineStart=yPos;
	bmpObj.intRowStart=xPos;
	bmpObj.strType1="text";
	bmpObj.strType2="qrcode";

	QString heightvalue = ui->heightBarCodeShowQRLab->text();
	int heightvalue1=heightvalue.toInt();
	bmpObj.intLineSize= heightvalue1;
	//bmpObj.intLineSize=my_symbol->bitmap_height-derta;
	bmpObj.intRowSize=my_symbol->bitmap_width;

	//以下先写死
	bmpObj.intSW=1;
	bmpObj.intSS=1;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;
	i=0;
	//i = derta*my_symbol->bitmap_width*3;
	int r, g, b;
	for (int row = 5; row < my_symbol->bitmap_height; row++)
	//for (int row = derta; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
		//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
				bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
		//		bmpObj.boDotBmp[col][row-proportion] = false;
		  		bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	bmpObj.strText = strContent.toStdString();
	bmpObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(bmpObj); 
}

void FileEditChild::CreateQrcode(int nType,QString strContent)
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;
	int v;

	error_number = 0;
	//QString angle1=ui->degreeQRShowLab->text();//暂时注掉
	//int angle2=angle1.toInt();
	//rotate_angle = angle2;
	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = nType;
	my_symbol->scale =0.5;

	v=ui->sideLenQRComBox->currentIndex();
	my_symbol->option_2=v+1;//option_1为容错等级，option_2为版本大小公式为:(V - 1) * 4 + 21；

	batch_mode = 0;
	mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
	/*float barlongth;
	barlongth=my_symbol->bitmap_height;
	float barwidth;
	barwidth=my_symbol->bitmap_width;
	float p;
	p=25/barlongth;
	my_symbol->scale =1;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
*/
	generated = 1;

	int xPos=0;
	int yPos=0;
	for(int i=0;i<m_PrinterMes.OBJ_Vec.size();i++)
	{
		if (m_PrinterMes.OBJ_Vec.at(i).booFocus)
		{
			m_PrinterMes.OBJ_Vec.at(i).booFocus=false;
			yPos = m_PrinterMes.OBJ_Vec.at(i).intLineStart;
			xPos = m_PrinterMes.OBJ_Vec.at(i).intRowSize+m_PrinterMes.OBJ_Vec.at(i).intRowStart;
		}
	}

	OBJ_Control bmpObj;
	bmpObj.intLineStart=yPos;
	bmpObj.intRowStart=xPos;
	bmpObj.strType1="text";
	bmpObj.strType2="qrcode";
	bmpObj.intLineSize=my_symbol->bitmap_height;
	bmpObj.intRowSize=my_symbol->bitmap_width;

	//以下先写死
	bmpObj.intSW=1;
	bmpObj.intSS=1;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;
	i = 0;
	int r, g, b;

	for (int row = 0; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
				bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				//		bmpObj.boDotBmp[col][row-proportion] = false;
				bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	bmpObj.strText = strContent.toStdString();
	bmpObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(bmpObj); 

}

void FileEditChild::CreateDMcode(int nType,QString strContent)
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;

	error_number = 0;
	//QString angle1=ui->degreeDMShowLab->text();//暂时注掉
	//int angle2=angle1.toInt();
	//rotate_angle = angle2;

	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = nType;
	my_symbol->scale =1;

	

	batch_mode = 0;
	mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
	
	
/*	float barlongth;
	barlongth=my_symbol->bitmap_height;
	float barwidth;
	barwidth=my_symbol->bitmap_width;
	float p;
	p=25/barlongth;
	my_symbol->scale =1;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strContent.toStdString().c_str(),strContent.toStdString().length(),rotate_angle);
	*/
	generated = 1;

	int xPos=0;
	int yPos=0;
	for(int i=0;i<m_PrinterMes.OBJ_Vec.size();i++)
	{
		if (m_PrinterMes.OBJ_Vec.at(i).booFocus)
		{
			m_PrinterMes.OBJ_Vec.at(i).booFocus=false;
			yPos = m_PrinterMes.OBJ_Vec.at(i).intLineStart;
			xPos = m_PrinterMes.OBJ_Vec.at(i).intRowSize+m_PrinterMes.OBJ_Vec.at(i).intRowStart;
		}
	}

	OBJ_Control bmpObj;
	bmpObj.intLineStart=yPos;
	bmpObj.intRowStart=xPos;
	bmpObj.strType1="text";
	bmpObj.strType2="qrcode";
	bmpObj.intLineSize=my_symbol->bitmap_height;
	bmpObj.intRowSize=my_symbol->bitmap_width;

	//以下先写死
	bmpObj.intSW=1;
	bmpObj.intSS=1;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;
	i = 0;
	int r, g, b;

	for (int row = 0; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
				bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				//		bmpObj.boDotBmp[col][row-proportion] = false;
				bmpObj.boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	bmpObj.strText = strContent.toStdString();
	bmpObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(bmpObj); 

}

void FileEditChild::PushBackTextOBJ(string txtFont, bool txtBWDy, bool txtBWDx, bool txtNEG, string txtContent,
	int txtRowSize, int txtLineSize, int txtLineStart, int txtRowStart, int txtSS, int txtSW)
{
	OBJ_Control textObj;
	textObj.intLineStart = 0;
	textObj.intRowStart = 0;
	textObj.strType1 = "text";
	textObj.strType2 = "text";
	textObj.strText = txtContent;
	int txtLength = txtContent.length();

	map<string,int> fntMap2;
	fntMap2.clear();
	fntMap2.insert(make_pair("5x5",0));
	fntMap2.insert(make_pair("7x5",1));
	fntMap2.insert(make_pair("12x12",2));
	fntMap2.insert(make_pair("16x12",3));
	int RowLength;
	int LineLength;

	switch(fntMap2[txtFont])
	{
		case 0:
			LineLength = 5;
			RowLength = 6;
			break;
		case 1:
			LineLength = 7;
			RowLength = 6;
			break;
		case 2:
			LineLength = 12;
			RowLength = 13;
			break;
		case 3:
			LineLength = 16;
			RowLength = 13;
			break;
	}

	textObj.intLineSize = LineLength;
	textObj.intRowSize = RowLength * txtLength;
	textObj.intSW = txtSW;
	textObj.intSS = txtSS;
	textObj.booNEG = txtNEG;
	textObj.booBWDx = txtBWDx;
	textObj.booBWDy = txtBWDy;
	
	textObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(textObj); 
}

void FileEditChild::LoadLocalFile()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(parentWidget()); 
 	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
	m_PrinterMes.ReadObjectsFromXml(pFilemanageForm->FormFileManageChild->GetCurXmlFile());
}

void FileEditChild::paintDot()
{
	QPainter painter(ui->editPreviewText);
	m_PrinterMes.DrawDot(&painter);
}

bool FileEditChild::eventFilter(QObject *watched, QEvent *event)
{
	if(watched == ui->editPreviewText && event->type() == QEvent::Paint)
	{
		paintDot();
		QWidget *pQWidget(this);
		pQWidget->update();
	}
	else if (watched == ui->editPreviewText->viewport())
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			//qDebug() << __FILE__<<__LINE__<< QString::number(event->type());
			QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
			mousePressEvent(mouseEvent);
			QWidget *pQWidget(this);
			pQWidget->update();
		}
	}
	return QWidget::eventFilter(watched, event);
}

void FileEditChild::mousePressEvent(QMouseEvent *event)
{
	//QPoint p_Global = event->globalPos();
	QPoint p_Relative = event->pos();
	m_PrinterMes.JudgeIfOBJ_Selected(p_Relative);
	paintDot();
	GetTextFromScreen();
}

void FileEditChild::GetTextFromScreen()
{
	for (int i=0; i<m_PrinterMes.OBJ_Vec.size(); i++)
	{
		if (m_PrinterMes.OBJ_Vec[i].booFocus)
		{
			QString tmpStr = QString::fromStdString(m_PrinterMes.OBJ_Vec[i].strText);
			this->ui->wordLineEdit->setText(tmpStr);
			break;
		}
	}
}

//“另存为”按钮
void FileEditChild::saveasBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget()); 
	string tmpFileName;
	//判断当前编辑的文件是否为本地文件
	if (pFilemanageForm->FormFileManageChild->boolFileSelected == true) //来源于本地
	{
		QString qfileName = pFilemanageForm->FormFileManageChild->ui->filelistWidget->currentItem()->text();
		QFileInfo fi(qfileName);
		qfileName = fi.baseName();
		tmpFileName = qfileName.toStdString();
	}
	else //新建文件
	{
		tmpFileName = "NewLabel_";
		m_PrinterMes.strMatrix = "1L7M";
		m_PrinterMes.Pixel = 7;
		m_PrinterMes.Reverse = "GLOBAL";
		m_PrinterMes.Inverse = "GLOBAL";
	}
	pFilemanageForm->FormFileManageChild->boolSaveAsBtn_Clicked = true;
	char* tmpChar = m_PrinterMes.GenerateFileName((tmpFileName));
	char FilePath[256];
	sprintf(FilePath,"%s",tmpChar);
	QString tmpFilePathStr = QString::fromStdString(FilePath);
	QFileInfo fi(tmpFilePathStr);
	QListWidgetItem *tmpItem = new QListWidgetItem(pFilemanageForm->FormFileManageChild->ui->filelistWidget);
	tmpItem->setText(fi.baseName()+".lab");
	pFilemanageForm->FormFileManageChild->ui->filelistWidget->addItem(tmpItem);
	pFilemanageForm->FormFileManageChild->ui->filelistWidget->setCurrentItem(tmpItem);
	pFilemanageForm->FormFileManageChild->SetButtonEnableOn();
	//pFilemanageForm->FormFileManageChild->ShowLocalFilePath();
	pFilemanageForm->FormFileManageChild->PreviewSaveFile();
	pFilemanageForm->FileManageChildWidgetCall();
}

//“保存”按钮
void FileEditChild::saveBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	//判断文件是新建的，还是来源于本地
	if (pFilemanageForm->FormFileManageChild->boolFileSelected == true) //来源于本地
	{
		QString qfileName = pFilemanageForm->FormFileManageChild->ui->filelistWidget->currentItem()->text();
		string tmpStr = qfileName.toStdString();
		char tmpFilePath[256];
		sprintf(tmpFilePath,"User/Label/%s",tmpStr.c_str());
		m_PrinterMes.SaveObjectsToXml(tmpFilePath);
		pFilemanageForm->FormFileManageChild->PreviewLocalFile();
		//此处应当弹出"保存成功！"对话框，持续一秒
	}
	else //新建文件，与"另存为"相同
	{
		saveasBut_clicked();
	}
}

void FileEditChild::variableTextBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->variableWidgetCall();
}

void FileEditChild::customTimeBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->timeCustomCall();
}

void FileEditChild::ReadBmp(char* strFileName)
{
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	QImage pImage;
	pImage = pLoad.toImage();

	OBJ_Control bmpObj;
	bmpObj.intLineStart=0;
	bmpObj.intRowStart=0;
	bmpObj.strType1="text";
	bmpObj.strType2="logo";
	bmpObj.intLineSize=pImage.width();
	bmpObj.intRowSize=pImage.height();
	bmpObj.intSW=1;
	bmpObj.intSS=0;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;

	for(int y = 0; y<pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x<pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
			if(average < 100)
				bmpObj.boDotBmp[bmpObj.intLineSize-x-1][y] = true;
			else
				bmpObj.boDotBmp[bmpObj.intLineSize-x-1][y] = false;
		}  

	}  
	bmpObj.booFocus = true;
	m_PrinterMes.OBJ_Vec.push_back(bmpObj); 
}

void FileEditChild::selBmpBut_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this,tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));
	aaaa=fileName;
	QImage image,result;
	image.load(fileName); 
	result = image.scaled(ui->bmpPreviewLab->width(), ui->bmpPreviewLab->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//放缩图片，以固定大小显示
	ui->bmpPreviewLab->setPixmap(QPixmap::fromImage(result));//在Label控件上显示图片
}

void FileEditChild::delBut_clicked()
{
	vector<OBJ_Control>::iterator itr = m_PrinterMes.OBJ_Vec.begin();
	while (itr != m_PrinterMes.OBJ_Vec.end())
	{
		if (itr->booFocus)
			{
				itr = m_PrinterMes.OBJ_Vec.erase(itr);
				paintDot();
				continue;
			}
	}
}

void FileEditChild::wordLineEdit_clicked()
{
	keyboardWidget->SetLineEdit(ui->wordLineEdit);
}

void FileEditChild::barCodeLineEdit_clicked()
{
 	keyboardWidget->SetLineEdit(ui->barCodeLineEdit);
}

void FileEditChild::QRCodeLineEdit_clicked()
{
 	keyboardWidget->SetLineEdit(ui->QRCodeLineEdit);
}

void FileEditChild::DMCodeLineEdit_clicked()
{
  	keyboardWidget->SetLineEdit(ui->DMCodeLineEdit);
}
 
void FileEditChild::newTextBut_clicked()
{
	for (int i=0; i<m_PrinterMes.OBJ_Vec.size(); i++)
	{
		if (m_PrinterMes.OBJ_Vec[i].booFocus)
		{
			string tmpStr = this->ui->wordLineEdit->text().toStdString();
			m_PrinterMes.OBJ_Vec[i].strText = tmpStr;
			int tmpStrLength = tmpStr.length();
			m_PrinterMes.OBJ_Vec[i].intRowSize = tmpStrLength * 6;

			/*map<string,int> fntMap3;
			fntMap3.clear();
			fntMap3.insert(make_pair("5x5",0));
			fntMap3.insert(make_pair("7x5",1));
			fntMap3.insert(make_pair("12x12",2));
			fntMap3.insert(make_pair("16x12",3));

			int RowLength;
			int LineLength;
			string tmpFont = this->ui-

			switch(fntMap3[])
			{
			case 0:
			LineLength = 5;
			RowLength = 6;
			case 1:
			LineLength = 7;
			RowLength = 6;
			case 2:
			LineLength = 12;
			RowLength = 13;
			case 3:
			LineLength = 16;
			RowLength = 13;
			}

			textObj.intLineSize = LineLength/2;
			textObj.intRowSize = RowLength/2 * txtLength;
			textObj.intSW = txtSW;
			textObj.intSS = txtSS;
			textObj.booNEG = txtNEG;
			textObj.booBWDx = txtBWDx;
			textObj.booBWDy = txtBWDy;*/

			return;
		}
	}
	QString txtQString = ui->wordLineEdit->text();
	string txtString = txtQString.toStdString();
	PushBackTextOBJ("7x5",false,false,false,txtString,20,20,0,0,0,1);
}

void FileEditChild::newBarCodeBut_clicked()
{
	int t;
	QString str;
	str = ui->barCodeLineEdit->text();
	if (ui->typeBarCodeComBox->currentIndex()==0)
	{
		t=13;
	}
	if (ui->typeBarCodeComBox->currentIndex()==1)
	{
		t=8;
	}
	if (ui->typeBarCodeComBox->currentIndex()==2)
	{
		t=25;
	}
	if (ui->typeBarCodeComBox->currentIndex()==3)
	{
		t=20;
	}
	if (ui->typeBarCodeComBox->currentIndex()==4)
	{
		t=34;
	}
	if (ui->typeBarCodeComBox->currentIndex()==5)
	{
		t=37;
	}
	if (ui->typeBarCodeComBox->currentIndex()==6)
	{
		t=89;
	}
	if (ui->typeBarCodeComBox->currentIndex()==7)
	{
		t=55;
	}

	Create2Dcode(t,str);
}

void FileEditChild::newQRBut_clicked()
{
	QString str;
	str = ui->QRCodeLineEdit->text();
	CreateQrcode(58,str);
}

void FileEditChild::newDMBut_clicked()
{
	QString str;
	str = ui->DMCodeLineEdit->text();
	CreateDMcode(71,str);
}

void FileEditChild::newBmpBut_clicked()
{
	 
	char *pic;
	QByteArray ba=aaaa.toLatin1();
	pic=ba.data();
	ReadBmp(pic);

}

void FileEditChild::moveUpBut_clicked()
{
	for (int i=0; i<m_PrinterMes.OBJ_Vec.size(); i++)
	{
		if (m_PrinterMes.OBJ_Vec[i].booFocus)
		{
			int EndPos = m_PrinterMes.OBJ_Vec[i].intLineStart + m_PrinterMes.OBJ_Vec[i].intLineSize ;
			if( EndPos < 241 )
			{
				m_PrinterMes.OBJ_Vec[i].intLineStart += 1;
				paintDot();
			}
		}
	}
}

void FileEditChild::moveDownBut_clicked()
{
	for (int i=0; i<m_PrinterMes.OBJ_Vec.size(); i++)
	{
		if (m_PrinterMes.OBJ_Vec[i].booFocus)
		{
			if( m_PrinterMes.OBJ_Vec[i].intLineStart > 0 )
			{
				m_PrinterMes.OBJ_Vec[i].intLineStart -= 1;
				paintDot();
			}
		}
	}
}

void FileEditChild::moveLeftBut_clicked()
{
	for (int i=0; i<m_PrinterMes.OBJ_Vec.size(); i++)
	{
		if (m_PrinterMes.OBJ_Vec[i].booFocus)
		{
			if( m_PrinterMes.OBJ_Vec[i].intRowStart > 0 )
			{
				m_PrinterMes.OBJ_Vec[i].intRowStart -= 1;
				paintDot();
			}
		}
	}
}

void FileEditChild::moveRightBut_clicked()
{
	for (int i=0; i<m_PrinterMes.OBJ_Vec.size(); i++)
	{
		if (m_PrinterMes.OBJ_Vec[i].booFocus)
		{
			int EndPos = m_PrinterMes.OBJ_Vec[i].intRowStart + m_PrinterMes.OBJ_Vec[i].intRowSize ;
			if( EndPos < 1041 )
			{
				m_PrinterMes.OBJ_Vec[i].intRowStart += 1;
				paintDot();
			}
		}
	}
}

void FileEditChild::deleteChar()
{
	ui->wordLineEdit->backspace();
	str1 = ui->wordLineEdit->text();
}

void FileEditChild::showNumCheckBox_clicked()
{
	
}

//void FileEditChild::degreeBarCodeAddBut_clicked()//暂时注掉
//{
//	
//	if (degreenum<270)
//	{
//		degreenum=degreenum+90;
//	} 
//	else
//	{
//		degreenum=0;
//	}
//	ui->degreeBarCodeShowLab->setText(QString::number(degreenum));
//}

//void FileEditChild::degreeBarCodeRedButt_clicked()//暂时注掉
//{
//
//	if (degreenum>0)
//	{
//		degreenum=degreenum-90;
//	} 
//	else
//	{
//		degreenum=270;
//	}
//	ui->degreeBarCodeShowLab->setText(QString::number(degreenum));
//}

void FileEditChild::heightBarCodeAddBut_clicked()
{
	ui->heightBarCodeShowQRLab->setText(QString::number(25));
}

void FileEditChild::heightBarCodeRedButt_clicked()
{
	ui->heightBarCodeShowQRLab->setText(QString::number(21));
	ui->wordLineEdit->backspace();
	str1 = ui->wordLineEdit->text();
}

//void FileEditChild::degreeQRAddBut_clicked()//暂时注掉
//{
//
//	if (degreenumQr<270)
//	{
//		degreenumQr=degreenumQr+90;
//	} 
//	else
//	{
//		degreenumQr=0;
//	}
//	ui->degreeQRShowLab->setText(QString::number(degreenumQr));
//}

//void FileEditChild::degreeQRRedButt_clicked()//暂时注掉
//{
//
//	if (degreenumQr>0)
//	{
//		degreenumQr=degreenumQr-90;
//	} 
//	else
//	{
//		degreenumQr=270;
//	}
//	ui->degreeQRShowLab->setText(QString::number(degreenumQr));
//}

//void FileEditChild::degreeDMAddBut_clicked()//暂时注掉
//{
//
//	if (degreenumDM<270)
//	{
//		degreenumDM=degreenumDM+90;
//	} 
//	else
//	{
//		degreenumDM=0;
//	}
//	ui->degreeDMShowLab->setText(QString::number(degreenumDM));
//}

//void FileEditChild::degreeDMRedButt_clicked()//暂时注掉
//{
//
//	if (degreenumDM>0)
//	{
//		degreenumDM=degreenumDM-90;
//	} 
//	else
//	{
//		degreenumDM=270;
//	}
//	ui->degreeDMShowLab->setText(QString::number(degreenumDM));
//}

 
void FileEditChild::zoomBarCodeAddBut_clicked()
{

	if (Zoomfactor>=0.5)
	{
		Zoomfactor=Zoomfactor+0.5;
	} 
	else
	{
		Zoomfactor=0.5;
	}
	ui->zoomShowBarCodeLab->setText(QString("%1").arg(Zoomfactor));
	//ui->zoomShowBarCodeLab->setText(QString::number(Zoomfactor,10,1));
}

void FileEditChild::zoomBarCodeRedBut_clicked()
{

	if (Zoomfactor>=1)
	{
		Zoomfactor=Zoomfactor-0.5;
	} 
	else
	{
		Zoomfactor=0.5;
	}
	ui->zoomShowBarCodeLab->setText(QString("%1").arg(Zoomfactor));
}

//void FileEditChild::zoomQRAddBut_clicked()//暂时注掉
//{
//
//	if (ZoomfactorQr>=0.5)
//	{
//		ZoomfactorQr=ZoomfactorQr+0.5;
//	} 
//	else
//	{
//		ZoomfactorQr=0.5;
//	}
//	ui->zoomShowQRLab->setText(QString("%1").arg(ZoomfactorQr));
//	//ui->zoomShowBarCodeLab->setText(QString::number(Zoomfactor,10,1));
//}

//void FileEditChild::zoomQRRedBut_clicked()
//{
//
//	if (ZoomfactorQr>=1)
//	{
//		ZoomfactorQr=ZoomfactorQr-0.5;
//	} 
//	else
//	{
//		ZoomfactorQr=0.5;
//	}
//	ui->zoomShowQRLab->setText(QString("%1").arg(ZoomfactorQr));
//}

//void FileEditChild::zoomDMAddBut_clicked()//暂时注掉
//{
//
//	if (ZoomfactorDM>=0.5)
//	{
//		ZoomfactorDM=ZoomfactorDM+0.5;
//	} 
//	else
//	{
//		ZoomfactorDM=0.5;
//	}
//	ui->zoomShowDMLab->setText(QString("%1").arg(ZoomfactorDM));
//	//ui->zoomShowBarCodeLab->setText(QString::number(Zoomfactor,10,1));
//}

//void FileEditChild::zoomDMRedBut_clicked()//暂时注掉
//{
//
//	if (ZoomfactorDM>=1)
//	{
//		ZoomfactorDM=ZoomfactorDM-0.5;
//	} 
//	else
//	{
//		ZoomfactorDM=0.5;
//	}
//	ui->zoomShowDMLab->setText(QString("%1").arg(ZoomfactorDM));
//}

void FileEditChild::addTimeBut_clicked()
{
	int nSelect=ui->FormatlistWidget->currentRow();
	QString timeFormatStr;
	timeFormatStr=ui->DateTimeEdit->text();
	switch(nSelect)
	{
	case 0:
		timeFormatStr+=("%Y");
		break;
	case 1:
		timeFormatStr+=("%y");
		break;
	case 2:
		timeFormatStr+=("%m");
		break;
	case 3:
		timeFormatStr+=("%d");
		break;
	case 4:
		timeFormatStr+=("%H");
		break;
	case 5:
		timeFormatStr+=("%I");
		break;
	case 6:
		timeFormatStr+=("%M");
		break;
	case 7:
		timeFormatStr+=("%S");
		break;
	case 8:
		timeFormatStr+= ("%U");
		break;
	case 9:
		timeFormatStr+= ("%W");
		break;
	case 10:
		timeFormatStr+= ("%w");
		break;
	case 11:
		timeFormatStr+= ("%j");
		break;
	case 12:
		timeFormatStr+= ("%a");
		break;
	case 13:
		timeFormatStr+= ("%A");
		break;
	case 14:
		timeFormatStr+= ("%b");
		break;
	case 15:
		timeFormatStr+= ("%B");
		break;
	case 16:
		timeFormatStr+= ("%p");
		break;
	default:
		break;
	}
	ui->DateTimeEdit->setText(timeFormatStr);
	QString skewvalue1;
	skewvalue1=ui->SkewSkewValueEdit->toPlainText();
	int skewvalue2=skewvalue1.toInt();
	//QString nowTimeStr=QString::fromStdString(m_TimeShow.TimeFormatToText(timeFormatStr,ui->SkewComBox->currentIndex(),skewvalue2,ui->SkewUUnitlistWidget->currentRow()));
	QString nowTimeStr=m_TimeShow.string2CString(m_TimeShow.TimeFormatToText(timeFormatStr,ui->SkewComBox->currentIndex(),skewvalue2,ui->SkewUUnitlistWidget->currentRow()));
	ui->PreviewEdit->setText(nowTimeStr);

}

void FileEditChild::SkewComBox_clicked()
{	if (ui->SkewComBox->currentIndex()==1)
{ChangeTime();}
}

void FileEditChild::refreshTimeBut_clicked()
{
	ChangeTime();
}

void FileEditChild::ChangeTime()
{
	CString timeFormatStr;
	timeFormatStr=ui->DateTimeEdit->text();
	QString skewvalue1;
	skewvalue1=ui->SkewSkewValueEdit->toPlainText();
	int skewvalue2=skewvalue1.toInt();
	QString nowTimeStr=m_TimeShow.string2CString(m_TimeShow.TimeFormatToText(timeFormatStr,ui->SkewComBox->currentIndex(),skewvalue2,ui->SkewUUnitlistWidget->currentRow()));
	//QString nowTimeStr=QString::fromStdString(m_TimeShow.TimeFormatToText(timeFormatStr,ui->SkewComBox->currentIndex(),skewvalue2,ui->SkewUUnitlistWidget->currentRow()));
	ui->PreviewEdit->setText(nowTimeStr);
}

void FileEditChild::newTimeBut_clicked()
{
	int xPos=0;
	int yPos=0;
	for(int i=0;i<m_PrinterMes.OBJ_Vec.size();i++)
	{
		if (m_PrinterMes.OBJ_Vec.at(i).booFocus)
		{
			m_PrinterMes.OBJ_Vec.at(i).booFocus=false;
			yPos=m_PrinterMes.OBJ_Vec.at(i).intLineStart;
			xPos=m_PrinterMes.OBJ_Vec.at(i).intRowSize+m_PrinterMes.OBJ_Vec.at(i).intRowStart;
		}
	}
	OBJ_Control tempObj;
	tempObj.intLineStart=yPos;
	tempObj.intRowStart=xPos;
	tempObj.strType1="text";
	tempObj.strType2="time";
	//以下先写死
	tempObj.intSW=1;
	tempObj.intSS=0;
	tempObj.booNEG=false;
	tempObj.booBWDx=false;
	tempObj.booBWDy=false;

	//CEdit* pEdit = (CEdit*)GetDlgItem(IDC_DATE_PREVIEW_EDIT);
	CString strText;
	//pEdit-> GetWindowText(strText);
	strText=ui->PreviewEdit->text();
	tempObj.strText=strText.toStdString();
	//tempObj.strText=theApp.myModuleMain.UnicodeToUtf8_CSTR(strText);

	CString formatText;
	formatText=ui->DateTimeEdit->text();
	//GetDlgItem(IDC_DATE_DATE_TIME_EDIT)->GetWindowText(formatText);
	tempObj.strTime=m_TimeShow.CString2string(formatText);

	CString  fontText;
	int nIndex = ui->fontTypeTimeComBox->currentIndex();
	//int nIndex = m_dateFontCombo.GetCurSel();  //当前选中的项
	switch(nIndex)
	{
	case 0:
		tempObj.intLineSize=5;
		tempObj.intRowSize=strText.length()*6;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 1:
		tempObj.intLineSize=7;
		tempObj.intRowSize=strText.length()*6;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 2:
		tempObj.intLineSize=12;
		tempObj.intRowSize=strText.length()*13;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 3:
		tempObj.intLineSize=16;
		tempObj.intRowSize=strText.length()*13;//////////这是个坑，注意阿拉伯语要改这
		break;
	}
	fontText=ui->fontTypeTimeComBox->currentText();
	//m_dateFontCombo.GetLBText(nIndex,fontText);
	tempObj.strFont=m_TimeShow.CString2string(fontText);

	tempObj.booETimeOffSet=ui->SkewComBox->currentIndex();
	CString timeOffText;
	timeOffText=ui->SkewSkewValueEdit->toPlainText();
	//GetDlgItem(IDC_DATE_SKEW_VALUE_EDIT)->GetWindowText(timeOffText);
	int timeOffText1=timeOffText.toInt();
	tempObj.intTimeOffSet=timeOffText1;
	tempObj.strTimeOffSet=ui->SkewUUnitlistWidget->currentRow();

	tempObj.booFocus=true;
	m_PrinterMes.OBJ_Vec.push_back(tempObj);
	//this->ShowWindow(SW_HIDE);
 
}
