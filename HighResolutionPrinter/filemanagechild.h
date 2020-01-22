#ifndef FILEMANAGECHILD_H
#define FILEMANAGECHILD_H

#include <QWidget>
#include <QDir>  
#include <QListWidgetItem>  
#include <QFileInfoList>  
#include <QListWidget>  
#include <QLineEdit>  
#include <QVBoxLayout>  
#include <QIcon>  
#include <QStringList>
#include "ClassMessage.h"

class keyboard;

namespace Ui {
	class FileManageChild;
}

class FileManageChild : public QWidget
{
	Q_OBJECT

public:
	FileManageChild(QWidget *parent = 0);
	~FileManageChild();
	Ui::FileManageChild *ui;  
	ClassMessage  m_PrinterMes2;
	keyboard  *keyboardWidget;

	void showFileInfoList(QFileInfoList list);
	void paintDot();
	QString rootStr;
	char* GetCurXmlFile();
	QFileInfoList list;

public slots:  
	void ShowLocalFilePath();
	void PreviewLocalFile();
	void slotShow(QDir dir); 
	void loadSeleFileBut_clicked();
	void editSeleFileBut_clicked();
	void fileNmaeLineEdit_click();

	//用于实现更改文件名的槽函数
	//void ChangeFileName();

protected:
	bool eventFilter(QObject *watched, QEvent *event);
};

#endif // FILEMANAGECHILD_H
