#include "paramsettingform.h"
#include "ui_paramsettingform.h"
#include <QFile>
#include <QDebug>
#include <QXmlStreamWriter>
#include "mainwindow.h"

ParamSettingForm::ParamSettingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ParamSettingForm)
{
    ui->setupUi(this);
	connect(ui->paraExitBut,SIGNAL(clicked()),this,SLOT(paraExitBut_clicked()));

	connect(ui->printSettingBut,SIGNAL(clicked()),this,SLOT(printSettingBut_clicked()));
	connect(ui->sysSettingBut,SIGNAL(clicked()),this,SLOT(sysSettingBut_clicked()));
	connect(ui->countSettingBut,SIGNAL(clicked()),this,SLOT(countSettingBut_clicked()));
	connect(ui->aboutMacBut,SIGNAL(clicked()),this,SLOT(aboutMacBut_clicked()));

	connect(ui->savePrintSetBut,SIGNAL(clicked()),this,SLOT(holdConfigurationBut_clicked()));


	ui->printSettingBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/printSetting.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
									   QPushButton:pressed{border-image: url(:/Images/printSetting.bmp);border: 1px solid rgb(12 , 138 , 235);\
									   padding-left:7px;padding-top:7px;}\
									   "); 
	ui->sysSettingBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/sysSetting.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
									 QPushButton:pressed{border-image: url(:/Images/sysSetting.bmp);border: 1px solid rgb(12 , 138 , 235);\
									 padding-left:7px;padding-top:7px;}\
									 "); 
	ui->countSettingBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/countSetting.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
									   QPushButton:pressed{border-image: url(:/Images/countSetting.bmp);border: 1px solid rgb(12 , 138 , 235);\
									   padding-left:7px;padding-top:7px;}\
									   "); 
	ui->aboutMacBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/aboutMac.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								   QPushButton:pressed{border-image: url(:/Images/aboutMac.bmp);border: 1px solid rgb(12 , 138 , 235);\
								   padding-left:7px;padding-top:7px;}\
								   "); 
	ui->paraExitBut->setStyleSheet("QPushButton{text-align:bottom;border-image: url(:/Images/exit.bmp);border-radius:15px;font: bold;font-size:30px;color:rgb(255,255,255)}\
								   QPushButton:pressed{border-image: url(:/Images/exit.bmp);border: 1px solid rgb(12 , 138 , 235);\
								   padding-left:7px;padding-top:7px;}\
								   "); 
	
	m_printSetting = new printSetting(this);//ʵ��������ҳ��
	m_sysSetting = new sysSetting(this);
	m_countSetting = new countSetting(this);
	m_aboutMac = new aboutMac(this);

	ui->paraManageStacWid->addWidget(m_printSetting);
	ui->paraManageStacWid->addWidget(m_sysSetting);
	ui->paraManageStacWid->addWidget(m_countSetting);
	ui->paraManageStacWid->addWidget(m_aboutMac);
	ui->paraManageStacWid->setCurrentWidget(m_printSetting);
}

ParamSettingForm::~ParamSettingForm()
{
    delete ui;
}

void ParamSettingForm::paraExitBut_clicked()
{
	this->close();
}

void ParamSettingForm::printSettingBut_clicked()
{
	ui->paraManageStacWid->setCurrentWidget(m_printSetting);
}

void ParamSettingForm::sysSettingBut_clicked()
{
	ui->paraManageStacWid->setCurrentWidget(m_sysSetting);
}

void ParamSettingForm::countSettingBut_clicked()
{
	ui->paraManageStacWid->setCurrentWidget(m_countSetting);
}

void ParamSettingForm::aboutMacBut_clicked()
{
	ui->paraManageStacWid->setCurrentWidget(m_aboutMac);
}

void ParamSettingForm::holdConfigurationBut_clicked()
{
	//�ȸ�m_ParamSetting�еĲ�����ֵ��Ȼ�����CParamSetting�еĺ���SaveParam2Xml���б���
	MainWindow* theApp = (MainWindow*)(this->parent());
	theApp->m_ParamSetting.SaveParam2Xml();

	//���´������SaveParam2Xml()������

	QFile file("bookindex.xml"); //��ֻд��ʽ����һ���ļ�
	if (!file.open(QFile::WriteOnly | QFile::Text)) {
		qDebug() << "Error: Cannot write file: "
			<< qPrintable(file.errorString());
		return;
	}

	QXmlStreamWriter xmlWriter(&file);
	xmlWriter.setAutoFormatting(true); //��ʽ�����Ҳ���ǻ��б�ǩ������
	xmlWriter.writeStartDocument();//��ʼ���� XML �ĵ������,���������д�� <?xml version="1.0" encoding="UTF-8"?>
	xmlWriter.writeStartElement("configuration_information"); //���ڵ�


	xmlWriter.writeStartElement("printsetting"); //д��һ�� entry �Ŀ�ʼ��ǩ

	xmlWriter.writeStartElement("Print_style"); //д��һ�� entry �Ŀ�ʼ��ǩ
	//xmlWriter.writeAttribute("term", "sidebearings"); //Ȼ��������ǩһ������ term������ֵ�� of vectors��
	xmlWriter.writeTextElement("Printing_speed",m_printSetting->ui.printSpeedShowLab->text()); //���һ���������ı����ݵı�ǩ
	xmlWriter.writeTextElement("Print_delay", m_printSetting->ui.printDelayShowLab->text());
	xmlWriter.writeTextElement("synFrequency", m_printSetting->ui.synFrequencyShowLab->text());
	xmlWriter.writeTextElement("Print_Gray", m_printSetting->ui.printGrayShowLab->text());
	xmlWriter.writeTextElement("Trigger_mode", m_printSetting->ui.trigComBox->currentText());
	xmlWriter.writeTextElement("Inkjet_mode", m_printSetting->ui.inkjetComBox->currentText());
	xmlWriter.writeTextElement("Printing_direction", m_printSetting->ui.printDirComBox->currentText());
	xmlWriter.writeEndElement(); //�رձ�ǩ

	xmlWriter.writeStartElement("advanced_setting");
	//xmlWriter.writeAttribute("term", "subtraction");
	xmlWriter.writeTextElement("Repetitions", m_printSetting->ui.repeteNumShowLab->text());
	xmlWriter.writeTextElement("Repetitive_delay", m_printSetting->ui.repeteDelayShowLab->text());
	xmlWriter.writeEndElement();

	xmlWriter.writeStartElement("Sprinklerhead_setting");
	//xmlWriter.writeAttribute("term", "subtraction");
	xmlWriter.writeTextElement("Ink_Voltage", m_printSetting->ui.voltShowLab->text());
	xmlWriter.writeTextElement("Ink_Pulse_width", m_printSetting->ui.PWShowLab->text());
	xmlWriter.writeTextElement("Flash_spray_Voltage", m_printSetting->ui.flashSprayVolShowLab->text());
	xmlWriter.writeTextElement("Flash_sprayk_Pulse_width", m_printSetting->ui.flashSprayPWShowLab->text());
	xmlWriter.writeTextElement("Offset", m_printSetting->ui.offsetShowLab->text());
	xmlWriter.writeEndElement();

	//xmlWriter.writeStartElement("UVlamp_setting");
	////xmlWriter.writeAttribute("term", "of vectors");
	//xmlWriter.writeTextElement("page", "9");
	//xmlWriter.writeEndElement();

	xmlWriter.writeEndElement();


	xmlWriter.writeStartElement("system_setting");
	//xmlWriter.writeAttribute("term", "subtraction");
	QString a = m_sysSetting->ui.yearShowBut->text();
	QString b = m_sysSetting->ui.monthShowBut->text();
	QString c = m_sysSetting->ui.dayShowBut->text();
	QString d = m_sysSetting->ui.hourShowBut->text();
	QString e = m_sysSetting->ui.minShowBut->text();
	QString f = m_sysSetting->ui.secondShowBut->text();

	xmlWriter.writeTextElement("system_time",a+b+c+d+e+f);
	xmlWriter.writeEndElement();


	xmlWriter.writeStartElement("count_setting");
	//xmlWriter.writeAttribute("term", "of vectors");
	xmlWriter.writeTextElement("page", "9");
	xmlWriter.writeEndElement();

	xmlWriter.writeEndElement();

	xmlWriter.writeEndDocument(); //��� XML �ĵ��Ѿ�д�ꡣ

	file.close();
	if (file.error()) {
		qDebug() << "Error: Cannot write file: "
			<< qPrintable(file.errorString());
		return;
	}
}
