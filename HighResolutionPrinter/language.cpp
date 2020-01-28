#include "language.h"
#include "ui_language.h"
#include <QtWidgets/QStackedWidget>
#include "keyboard.h"

language::language(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::language)
{
	ui->setupUi(this);

	connect(ui->OKLanBut,SIGNAL(clicked()),this,SLOT(OKLanBut_clicked()));
	connect(ui->LanEnglish,SIGNAL(clicked()),this,SLOT(lanEnglish_KBBut_clicked()));
	connect(ui->LanChinese,SIGNAL(clicked()),this,SLOT(LanChinese_KBBut_clicked()));
	connect(ui->LanKorean,SIGNAL(clicked()),this,SLOT(LanKorean_KBBut_clicked()));
	connect(ui->LanCzech,SIGNAL(clicked()),this,SLOT(LanCzech_KBBut_clicked()));
	connect(ui->LanJapanese,SIGNAL(clicked()),this,SLOT(LanJapanese_KBBut_clicked()));
}

language::~language()
{
	
}

void language::OKLanBut_clicked()
{
	//暂时用wordLineEdit_clicked调出KB
	setVisible(false);   
}

void language::lanEnglish_KBBut_clicked()
{
	//用于English切换回原键盘
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 7;
	pKeyboard->caps1_kBBut_clicked();
	setVisible(false); 
}

void language::LanChinese_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 0;
	pKeyboard->m_LantypeReverse = 1;//Chinese
	pKeyboard->caps1_kBBut_clicked();
	setVisible(false);   
}

void language::LanKorean_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 22;
	pKeyboard->m_LantypeReverse = 2;//Kore 
	pKeyboard->caps1_kBBut_clicked();
	setVisible(false);   
}

void language::LanJapanese_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 1;
	pKeyboard->m_LantypeReverse = 4;//Japanese 
	pKeyboard->caps1_kBBut_clicked();
	setVisible(false); 
}

void language::LanCzech_KBBut_clicked()
{
	keyboard *pKeyboard = qobject_cast<keyboard*>(this->parentWidget());  
	pKeyboard->m_Upper = true;
	pKeyboard->m_LanType = 8;
	pKeyboard->m_LantypeReverse = 3;//Czech 
	pKeyboard->caps1_kBBut_clicked();
	setVisible(false); 
}
