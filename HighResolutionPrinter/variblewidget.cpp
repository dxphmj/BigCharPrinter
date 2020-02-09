#include "variblewidget.h"
#include <QTableWidget>
#include "filemanageform.h"

varibleWidget::varibleWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.returnVarTextBut,SIGNAL(clicked()),this,SLOT(returnVarTextBut_clicked()));
}

varibleWidget::~varibleWidget()
{

}

void varibleWidget::returnVarTextBut_clicked()
{
	QStackedWidget *pQStackedWidget = qobject_cast<QStackedWidget*>(this->parentWidget());  
	FilemanageForm *pFilemanageForm = qobject_cast<FilemanageForm*>(pQStackedWidget->parentWidget());  
	pFilemanageForm->FileEditChildWidgetCall();

}
