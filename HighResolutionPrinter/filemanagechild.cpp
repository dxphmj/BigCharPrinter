#include "filemanagechild.h"
#include "QDir"
#include "QFileDialog"
#include "QTextStream"
#include "QFile"

FileManageChild::FileManageChild(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.localFileBut,SIGNAL(clicked()),this,SLOT(localFileBut_clicked()));
}

FileManageChild::~FileManageChild()
{

}

void FileManageChild::localFileBut_clicked()
{
		
	//QString path = QDir::toNativeSeparators(QFileDialog::getOpenFileName(this,tr("Save path"),QDir::currentPath())); 
	//if(!path.isEmpty())
	//{
	//	if(ui->comboBox->findText(path)==-1)
	//		ui->comboBox->addItem(path);    //��comboBox����ʾ�ļ�·��

	//	QFile *file=new QFile;   //����һ���ļ�ָ��
	//	file->setFileName(path);   //�����ļ�·��
	//	bool ok=file->open(QIODevice::ReadOnly);
	//	if(ok)
	//	{
	//		QTextStream in(file);
	//		ui->textBrowser->setText(in.readAll());    //��textBrowser����ʾ�ļ�����
	//		file->close();
	//	}

	//}
	
}