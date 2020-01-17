#include "language.h"
#include "fileeditchild.h"
#include <QtWidgets/QStackedWidget>

language::language(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.OKLanBut,SIGNAL(clicked()),this,SLOT(OKLanBut_clicked()));
	connect(ui.LanEnglish,SIGNAL(clicked()),this,SLOT(lanEnglish_KBBut_clicked()));
	connect(ui.LanChinese,SIGNAL(clicked()),this,SLOT(LanChinese_KBBut_clicked()));
}

language::~language()
{
	
}

void language::OKLanBut_clicked()
{
	//��ʱ��wordLineEdit_clicked����KB
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->returnKB();    
}

void language::lanEnglish_KBBut_clicked()
{
	//����English�л���ԭ����
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FileEditChild *pFileEditChild = qobject_cast<FileEditChild*>(pQStackedWidget->parentWidget());  
	pFileEditChild->returnKB();   
}

void language::LanChinese_KBBut_clicked()
{

}
