/********************************************************************************
** Form generated from reading UI file 'filemanageform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMANAGEFORM_H
#define UI_FILEMANAGEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilemanageForm
{
public:
    QPushButton *editFileBut;
    QPushButton *manageFileBut;
    QPushButton *exitBut;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *FilemanageForm)
    {
        if (FilemanageForm->objectName().isEmpty())
            FilemanageForm->setObjectName(QStringLiteral("FilemanageForm"));
        FilemanageForm->resize(1280, 800);
        FilemanageForm->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 255);"));
        editFileBut = new QPushButton(FilemanageForm);
        editFileBut->setObjectName(QStringLiteral("editFileBut"));
        editFileBut->setGeometry(QRect(10, 180, 141, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        editFileBut->setFont(font);
        editFileBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/editFile.bmp);"));
        manageFileBut = new QPushButton(FilemanageForm);
        manageFileBut->setObjectName(QStringLiteral("manageFileBut"));
        manageFileBut->setGeometry(QRect(10, 360, 141, 141));
        manageFileBut->setFont(font);
        manageFileBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/manageFile.bmp);"));
        exitBut = new QPushButton(FilemanageForm);
        exitBut->setObjectName(QStringLiteral("exitBut"));
        exitBut->setGeometry(QRect(10, 540, 141, 141));
        exitBut->setFont(font);
        exitBut->setStyleSheet(QStringLiteral("background-image: url(:/Images/exit.bmp);"));
        stackedWidget = new QStackedWidget(FilemanageForm);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(190, 20, 1061, 761));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        stackedWidget->addWidget(page_2);

        retranslateUi(FilemanageForm);

        QMetaObject::connectSlotsByName(FilemanageForm);
    } // setupUi

    void retranslateUi(QWidget *FilemanageForm)
    {
        FilemanageForm->setWindowTitle(QApplication::translate("FilemanageForm", "Form", 0));
        editFileBut->setText(QApplication::translate("FilemanageForm", "\347\274\226\350\276\221\346\226\207\344\273\266", 0));
        manageFileBut->setText(QApplication::translate("FilemanageForm", "\347\256\241\347\220\206\346\226\207\344\273\266", 0));
        exitBut->setText(QApplication::translate("FilemanageForm", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class FilemanageForm: public Ui_FilemanageForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEFORM_H
