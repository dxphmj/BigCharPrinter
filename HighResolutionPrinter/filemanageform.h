#ifndef FILEMANAGEFORM_H
#define FILEMANAGEFORM_H

#include <QWidget>
#include <QStackedWidget>

class FileManageChild;
class FileEditChild;
class varibleWidget;
class timeCustom;

namespace Ui {
class FilemanageForm;
}

class FilemanageForm : public QWidget
{
    Q_OBJECT

public:
    FilemanageForm(QWidget *parent = 0);
    ~FilemanageForm();
    Ui::FilemanageForm *ui;
	 
public:
	FileManageChild *FormFileManageChild;//��������ҳ��ָ��
	FileEditChild  *FormFileEditChild;
	varibleWidget  *fontVarWidget;
	timeCustom  *timeCustomWidget;

private slots:
	void exitBut_clicked();
	void editFileBut_clicked();
	void manageFileBut_clicked();

public:
	void timeCustomCall();
	void variableWidgetCall();
	void FileEditChildWidgetCall();
	void FileManageChildWidgetCall();
};

#endif // FILEMANAGEFORM_H
