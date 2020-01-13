/********************************************************************************
** Form generated from reading UI file 'printsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTSETTING_H
#define UI_PRINTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_printSetting
{
public:
    QTabWidget *printSetTabWid;
    QWidget *printStyleTab;
    QPushButton *printSpeedRedBut;
    QLabel *trigLab;
    QLabel *printSpeedShowLab;
    QPushButton *printSpeedAddBut;
    QLabel *printSpeedLab;
    QComboBox *trigComBox;
    QComboBox *inkjetComBox;
    QLabel *inkjetLab;
    QComboBox *printDirComBox;
    QLabel *printDirLab;
    QLabel *printDelayLab;
    QPushButton *printDelayRedBut;
    QLabel *printDelayShowLab;
    QPushButton *printDelayAddBut;
    QLabel *synFrequencyLab;
    QPushButton *synFrequencyRedBut;
    QLabel *synFrequencyShowLab;
    QPushButton *synFrequencyAddBut;
    QPushButton *printGrayAddBut;
    QLabel *printGrayShowLab;
    QLabel *printGrayLab;
    QPushButton *printGrayRedBut;
    QCheckBox *synWheelCheckBox;
    QCheckBox *voiceCheckBox;
    QWidget *settingTab;
    QLabel *DPILab;
    QRadioButton *DPI150RadioBut;
    QRadioButton *DPI200RadioBut;
    QRadioButton *DPI300RadioBut;
    QRadioButton *DPI600RadioBut;
    QCheckBox *repetePrintCheckBox;
    QLabel *repeteNumShowLab;
    QPushButton *repeteNumAddBut;
    QLabel *repeteLab;
    QPushButton *repeteNumRedBut;
    QPushButton *repeteDelayRedBut;
    QLabel *repeteDelayShowLab;
    QPushButton *repeteDelayAddBut;
    QLabel *repeteDelayLab;
    QWidget *nozzleSetTab;
    QLabel *inkTypeLab;
    QCheckBox *adaptParaCheckBox;
    QLabel *voltShowLab;
    QPushButton *voltAddBut;
    QLabel *inkVoltLab;
    QPushButton *voltRedBut;
    QLabel *PWShowLab;
    QPushButton *PWAddBut;
    QLabel *PWLab;
    QPushButton *PWRedBut;
    QLabel *nozzleSelLab;
    QPushButton *offsetRedBut;
    QLabel *offsetShowLab;
    QPushButton *offsetAddBut;
    QLabel *offsetLab;
    QRadioButton *nozzleSel2RadioBut;
    QRadioButton *nozzleSel1RadioBut;
    QLabel *flashSprayLab;
    QCheckBox *flashSprayCheckBox;
    QPushButton *flashSprayPWRedBut;
    QLabel *flashSprayPWShowLab;
    QPushButton *flashSprayPWAddBut;
    QLabel *flashSprayVolShowLab;
    QLabel *flashSprayVoltLab;
    QPushButton *flashSprayVolRedBut;
    QLabel *flashSprayPWLab;
    QPushButton *flashSprayVolAddBut;
    QWidget *UVSettingTab;

    void setupUi(QWidget *printSetting)
    {
        if (printSetting->objectName().isEmpty())
            printSetting->setObjectName(QStringLiteral("printSetting"));
        printSetting->resize(1061, 691);
        printSetting->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        printSetTabWid = new QTabWidget(printSetting);
        printSetTabWid->setObjectName(QStringLiteral("printSetTabWid"));
        printSetTabWid->setGeometry(QRect(20, 20, 1021, 651));
        printSetTabWid->setMaximumSize(QSize(1021, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(16);
        printSetTabWid->setFont(font);
        printSetTabWid->setStyleSheet(QLatin1String("QTabBar::tab{width:255}\n"
"QTabBar::tab{height:50}"));
        printStyleTab = new QWidget();
        printStyleTab->setObjectName(QStringLiteral("printStyleTab"));
        printSpeedRedBut = new QPushButton(printStyleTab);
        printSpeedRedBut->setObjectName(QStringLiteral("printSpeedRedBut"));
        printSpeedRedBut->setGeometry(QRect(240, 110, 41, 41));
        printSpeedRedBut->setMinimumSize(QSize(41, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        printSpeedRedBut->setFont(font1);
        printSpeedRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        trigLab = new QLabel(printStyleTab);
        trigLab->setObjectName(QStringLiteral("trigLab"));
        trigLab->setGeometry(QRect(580, 110, 101, 41));
        trigLab->setMinimumSize(QSize(101, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        trigLab->setFont(font2);
        trigLab->setAlignment(Qt::AlignCenter);
        printSpeedShowLab = new QLabel(printStyleTab);
        printSpeedShowLab->setObjectName(QStringLiteral("printSpeedShowLab"));
        printSpeedShowLab->setGeometry(QRect(280, 110, 131, 41));
        printSpeedShowLab->setMinimumSize(QSize(0, 41));
        printSpeedShowLab->setFont(font2);
        printSpeedShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        printSpeedShowLab->setAlignment(Qt::AlignCenter);
        printSpeedAddBut = new QPushButton(printStyleTab);
        printSpeedAddBut->setObjectName(QStringLiteral("printSpeedAddBut"));
        printSpeedAddBut->setGeometry(QRect(410, 110, 41, 41));
        printSpeedAddBut->setMinimumSize(QSize(41, 41));
        printSpeedAddBut->setFont(font1);
        printSpeedAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printSpeedLab = new QLabel(printStyleTab);
        printSpeedLab->setObjectName(QStringLiteral("printSpeedLab"));
        printSpeedLab->setGeometry(QRect(140, 110, 101, 41));
        printSpeedLab->setMinimumSize(QSize(101, 41));
        printSpeedLab->setFont(font2);
        printSpeedLab->setAlignment(Qt::AlignCenter);
        trigComBox = new QComboBox(printStyleTab);
        trigComBox->setObjectName(QStringLiteral("trigComBox"));
        trigComBox->setGeometry(QRect(680, 115, 181, 31));
        trigComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        inkjetComBox = new QComboBox(printStyleTab);
        inkjetComBox->setObjectName(QStringLiteral("inkjetComBox"));
        inkjetComBox->setGeometry(QRect(680, 205, 181, 31));
        inkjetComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        inkjetLab = new QLabel(printStyleTab);
        inkjetLab->setObjectName(QStringLiteral("inkjetLab"));
        inkjetLab->setGeometry(QRect(580, 200, 101, 41));
        inkjetLab->setMinimumSize(QSize(101, 41));
        inkjetLab->setFont(font2);
        inkjetLab->setAlignment(Qt::AlignCenter);
        printDirComBox = new QComboBox(printStyleTab);
        printDirComBox->setObjectName(QStringLiteral("printDirComBox"));
        printDirComBox->setGeometry(QRect(680, 295, 181, 31));
        printDirComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printDirLab = new QLabel(printStyleTab);
        printDirLab->setObjectName(QStringLiteral("printDirLab"));
        printDirLab->setGeometry(QRect(580, 290, 101, 41));
        printDirLab->setMinimumSize(QSize(101, 41));
        printDirLab->setFont(font2);
        printDirLab->setAlignment(Qt::AlignCenter);
        printDelayLab = new QLabel(printStyleTab);
        printDelayLab->setObjectName(QStringLiteral("printDelayLab"));
        printDelayLab->setGeometry(QRect(140, 200, 101, 41));
        printDelayLab->setMinimumSize(QSize(101, 41));
        printDelayLab->setFont(font2);
        printDelayLab->setAlignment(Qt::AlignCenter);
        printDelayRedBut = new QPushButton(printStyleTab);
        printDelayRedBut->setObjectName(QStringLiteral("printDelayRedBut"));
        printDelayRedBut->setGeometry(QRect(240, 200, 41, 41));
        printDelayRedBut->setMinimumSize(QSize(41, 41));
        printDelayRedBut->setFont(font1);
        printDelayRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printDelayShowLab = new QLabel(printStyleTab);
        printDelayShowLab->setObjectName(QStringLiteral("printDelayShowLab"));
        printDelayShowLab->setGeometry(QRect(280, 200, 131, 41));
        printDelayShowLab->setMinimumSize(QSize(0, 41));
        printDelayShowLab->setFont(font2);
        printDelayShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        printDelayShowLab->setAlignment(Qt::AlignCenter);
        printDelayAddBut = new QPushButton(printStyleTab);
        printDelayAddBut->setObjectName(QStringLiteral("printDelayAddBut"));
        printDelayAddBut->setGeometry(QRect(410, 200, 41, 41));
        printDelayAddBut->setMinimumSize(QSize(41, 41));
        printDelayAddBut->setFont(font1);
        printDelayAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        synFrequencyLab = new QLabel(printStyleTab);
        synFrequencyLab->setObjectName(QStringLiteral("synFrequencyLab"));
        synFrequencyLab->setGeometry(QRect(140, 290, 101, 41));
        synFrequencyLab->setMinimumSize(QSize(101, 41));
        synFrequencyLab->setFont(font2);
        synFrequencyLab->setAlignment(Qt::AlignCenter);
        synFrequencyRedBut = new QPushButton(printStyleTab);
        synFrequencyRedBut->setObjectName(QStringLiteral("synFrequencyRedBut"));
        synFrequencyRedBut->setGeometry(QRect(240, 290, 41, 41));
        synFrequencyRedBut->setMinimumSize(QSize(41, 41));
        synFrequencyRedBut->setFont(font1);
        synFrequencyRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        synFrequencyShowLab = new QLabel(printStyleTab);
        synFrequencyShowLab->setObjectName(QStringLiteral("synFrequencyShowLab"));
        synFrequencyShowLab->setGeometry(QRect(280, 290, 131, 41));
        synFrequencyShowLab->setMinimumSize(QSize(0, 41));
        synFrequencyShowLab->setFont(font2);
        synFrequencyShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        synFrequencyShowLab->setAlignment(Qt::AlignCenter);
        synFrequencyAddBut = new QPushButton(printStyleTab);
        synFrequencyAddBut->setObjectName(QStringLiteral("synFrequencyAddBut"));
        synFrequencyAddBut->setGeometry(QRect(410, 290, 41, 41));
        synFrequencyAddBut->setMinimumSize(QSize(41, 41));
        synFrequencyAddBut->setFont(font1);
        synFrequencyAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printGrayAddBut = new QPushButton(printStyleTab);
        printGrayAddBut->setObjectName(QStringLiteral("printGrayAddBut"));
        printGrayAddBut->setGeometry(QRect(410, 380, 41, 41));
        printGrayAddBut->setMinimumSize(QSize(41, 41));
        printGrayAddBut->setFont(font1);
        printGrayAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printGrayShowLab = new QLabel(printStyleTab);
        printGrayShowLab->setObjectName(QStringLiteral("printGrayShowLab"));
        printGrayShowLab->setGeometry(QRect(280, 380, 131, 41));
        printGrayShowLab->setMinimumSize(QSize(0, 41));
        printGrayShowLab->setFont(font2);
        printGrayShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        printGrayShowLab->setAlignment(Qt::AlignCenter);
        printGrayLab = new QLabel(printStyleTab);
        printGrayLab->setObjectName(QStringLiteral("printGrayLab"));
        printGrayLab->setGeometry(QRect(140, 380, 101, 41));
        printGrayLab->setMinimumSize(QSize(101, 41));
        printGrayLab->setFont(font2);
        printGrayLab->setAlignment(Qt::AlignCenter);
        printGrayRedBut = new QPushButton(printStyleTab);
        printGrayRedBut->setObjectName(QStringLiteral("printGrayRedBut"));
        printGrayRedBut->setGeometry(QRect(240, 380, 41, 41));
        printGrayRedBut->setMinimumSize(QSize(41, 41));
        printGrayRedBut->setFont(font1);
        printGrayRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        synWheelCheckBox = new QCheckBox(printStyleTab);
        synWheelCheckBox->setObjectName(QStringLiteral("synWheelCheckBox"));
        synWheelCheckBox->setGeometry(QRect(680, 385, 181, 31));
        synWheelCheckBox->setFont(font2);
        synWheelCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        synWheelCheckBox->setChecked(false);
        synWheelCheckBox->setAutoRepeat(false);
        voiceCheckBox = new QCheckBox(printStyleTab);
        voiceCheckBox->setObjectName(QStringLiteral("voiceCheckBox"));
        voiceCheckBox->setGeometry(QRect(680, 470, 181, 31));
        voiceCheckBox->setFont(font2);
        voiceCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        voiceCheckBox->setChecked(false);
        voiceCheckBox->setAutoRepeat(false);
        printSetTabWid->addTab(printStyleTab, QString());
        settingTab = new QWidget();
        settingTab->setObjectName(QStringLiteral("settingTab"));
        DPILab = new QLabel(settingTab);
        DPILab->setObjectName(QStringLiteral("DPILab"));
        DPILab->setGeometry(QRect(460, 60, 101, 41));
        DPILab->setMinimumSize(QSize(101, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(14);
        DPILab->setFont(font3);
        DPILab->setAlignment(Qt::AlignCenter);
        DPI150RadioBut = new QRadioButton(settingTab);
        DPI150RadioBut->setObjectName(QStringLiteral("DPI150RadioBut"));
        DPI150RadioBut->setGeometry(QRect(70, 140, 131, 41));
        DPI150RadioBut->setFont(font3);
        DPI150RadioBut->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        DPI200RadioBut = new QRadioButton(settingTab);
        DPI200RadioBut->setObjectName(QStringLiteral("DPI200RadioBut"));
        DPI200RadioBut->setGeometry(QRect(330, 140, 131, 41));
        DPI200RadioBut->setFont(font3);
        DPI200RadioBut->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        DPI300RadioBut = new QRadioButton(settingTab);
        DPI300RadioBut->setObjectName(QStringLiteral("DPI300RadioBut"));
        DPI300RadioBut->setGeometry(QRect(590, 140, 131, 41));
        DPI300RadioBut->setFont(font3);
        DPI300RadioBut->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        DPI600RadioBut = new QRadioButton(settingTab);
        DPI600RadioBut->setObjectName(QStringLiteral("DPI600RadioBut"));
        DPI600RadioBut->setGeometry(QRect(850, 140, 131, 41));
        DPI600RadioBut->setFont(font3);
        DPI600RadioBut->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        repetePrintCheckBox = new QCheckBox(settingTab);
        repetePrintCheckBox->setObjectName(QStringLiteral("repetePrintCheckBox"));
        repetePrintCheckBox->setGeometry(QRect(140, 280, 181, 31));
        repetePrintCheckBox->setFont(font2);
        repetePrintCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        repetePrintCheckBox->setChecked(false);
        repetePrintCheckBox->setAutoRepeat(false);
        repeteNumShowLab = new QLabel(settingTab);
        repeteNumShowLab->setObjectName(QStringLiteral("repeteNumShowLab"));
        repeteNumShowLab->setGeometry(QRect(270, 370, 471, 41));
        repeteNumShowLab->setMinimumSize(QSize(0, 41));
        repeteNumShowLab->setFont(font2);
        repeteNumShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        repeteNumShowLab->setAlignment(Qt::AlignCenter);
        repeteNumAddBut = new QPushButton(settingTab);
        repeteNumAddBut->setObjectName(QStringLiteral("repeteNumAddBut"));
        repeteNumAddBut->setGeometry(QRect(740, 370, 41, 41));
        repeteNumAddBut->setMinimumSize(QSize(41, 41));
        repeteNumAddBut->setFont(font1);
        repeteNumAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteLab = new QLabel(settingTab);
        repeteLab->setObjectName(QStringLiteral("repeteLab"));
        repeteLab->setGeometry(QRect(130, 370, 101, 41));
        repeteLab->setMinimumSize(QSize(101, 41));
        repeteLab->setFont(font2);
        repeteLab->setAlignment(Qt::AlignCenter);
        repeteNumRedBut = new QPushButton(settingTab);
        repeteNumRedBut->setObjectName(QStringLiteral("repeteNumRedBut"));
        repeteNumRedBut->setGeometry(QRect(230, 370, 41, 41));
        repeteNumRedBut->setMinimumSize(QSize(41, 41));
        repeteNumRedBut->setFont(font1);
        repeteNumRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteDelayRedBut = new QPushButton(settingTab);
        repeteDelayRedBut->setObjectName(QStringLiteral("repeteDelayRedBut"));
        repeteDelayRedBut->setGeometry(QRect(230, 470, 41, 41));
        repeteDelayRedBut->setMinimumSize(QSize(41, 41));
        repeteDelayRedBut->setFont(font1);
        repeteDelayRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteDelayShowLab = new QLabel(settingTab);
        repeteDelayShowLab->setObjectName(QStringLiteral("repeteDelayShowLab"));
        repeteDelayShowLab->setGeometry(QRect(270, 470, 471, 41));
        repeteDelayShowLab->setMinimumSize(QSize(0, 41));
        repeteDelayShowLab->setFont(font2);
        repeteDelayShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        repeteDelayShowLab->setAlignment(Qt::AlignCenter);
        repeteDelayAddBut = new QPushButton(settingTab);
        repeteDelayAddBut->setObjectName(QStringLiteral("repeteDelayAddBut"));
        repeteDelayAddBut->setGeometry(QRect(740, 470, 41, 41));
        repeteDelayAddBut->setMinimumSize(QSize(41, 41));
        repeteDelayAddBut->setFont(font1);
        repeteDelayAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteDelayLab = new QLabel(settingTab);
        repeteDelayLab->setObjectName(QStringLiteral("repeteDelayLab"));
        repeteDelayLab->setGeometry(QRect(130, 470, 101, 41));
        repeteDelayLab->setMinimumSize(QSize(101, 41));
        repeteDelayLab->setFont(font2);
        repeteDelayLab->setAlignment(Qt::AlignCenter);
        printSetTabWid->addTab(settingTab, QString());
        nozzleSetTab = new QWidget();
        nozzleSetTab->setObjectName(QStringLiteral("nozzleSetTab"));
        inkTypeLab = new QLabel(nozzleSetTab);
        inkTypeLab->setObjectName(QStringLiteral("inkTypeLab"));
        inkTypeLab->setGeometry(QRect(460, 20, 101, 41));
        inkTypeLab->setMinimumSize(QSize(101, 41));
        inkTypeLab->setFont(font2);
        inkTypeLab->setAlignment(Qt::AlignCenter);
        adaptParaCheckBox = new QCheckBox(nozzleSetTab);
        adaptParaCheckBox->setObjectName(QStringLiteral("adaptParaCheckBox"));
        adaptParaCheckBox->setGeometry(QRect(30, 100, 181, 31));
        adaptParaCheckBox->setFont(font2);
        adaptParaCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        adaptParaCheckBox->setChecked(false);
        adaptParaCheckBox->setAutoRepeat(false);
        voltShowLab = new QLabel(nozzleSetTab);
        voltShowLab->setObjectName(QStringLiteral("voltShowLab"));
        voltShowLab->setGeometry(QRect(440, 100, 131, 41));
        voltShowLab->setMinimumSize(QSize(0, 41));
        voltShowLab->setFont(font2);
        voltShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        voltShowLab->setAlignment(Qt::AlignCenter);
        voltAddBut = new QPushButton(nozzleSetTab);
        voltAddBut->setObjectName(QStringLiteral("voltAddBut"));
        voltAddBut->setGeometry(QRect(570, 100, 41, 41));
        voltAddBut->setMinimumSize(QSize(41, 41));
        voltAddBut->setFont(font1);
        voltAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        inkVoltLab = new QLabel(nozzleSetTab);
        inkVoltLab->setObjectName(QStringLiteral("inkVoltLab"));
        inkVoltLab->setGeometry(QRect(300, 100, 101, 41));
        inkVoltLab->setMinimumSize(QSize(101, 41));
        inkVoltLab->setFont(font2);
        inkVoltLab->setAlignment(Qt::AlignCenter);
        voltRedBut = new QPushButton(nozzleSetTab);
        voltRedBut->setObjectName(QStringLiteral("voltRedBut"));
        voltRedBut->setGeometry(QRect(400, 100, 41, 41));
        voltRedBut->setMinimumSize(QSize(41, 41));
        voltRedBut->setFont(font1);
        voltRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        PWShowLab = new QLabel(nozzleSetTab);
        PWShowLab->setObjectName(QStringLiteral("PWShowLab"));
        PWShowLab->setGeometry(QRect(830, 100, 131, 41));
        PWShowLab->setMinimumSize(QSize(0, 41));
        PWShowLab->setFont(font2);
        PWShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        PWShowLab->setAlignment(Qt::AlignCenter);
        PWAddBut = new QPushButton(nozzleSetTab);
        PWAddBut->setObjectName(QStringLiteral("PWAddBut"));
        PWAddBut->setGeometry(QRect(960, 100, 41, 41));
        PWAddBut->setMinimumSize(QSize(41, 41));
        PWAddBut->setFont(font1);
        PWAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        PWLab = new QLabel(nozzleSetTab);
        PWLab->setObjectName(QStringLiteral("PWLab"));
        PWLab->setGeometry(QRect(690, 100, 101, 41));
        PWLab->setMinimumSize(QSize(101, 41));
        PWLab->setFont(font2);
        PWLab->setAlignment(Qt::AlignCenter);
        PWRedBut = new QPushButton(nozzleSetTab);
        PWRedBut->setObjectName(QStringLiteral("PWRedBut"));
        PWRedBut->setGeometry(QRect(790, 100, 41, 41));
        PWRedBut->setMinimumSize(QSize(41, 41));
        PWRedBut->setFont(font1);
        PWRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        nozzleSelLab = new QLabel(nozzleSetTab);
        nozzleSelLab->setObjectName(QStringLiteral("nozzleSelLab"));
        nozzleSelLab->setGeometry(QRect(460, 210, 101, 41));
        nozzleSelLab->setMinimumSize(QSize(101, 41));
        nozzleSelLab->setFont(font2);
        nozzleSelLab->setAlignment(Qt::AlignCenter);
        offsetRedBut = new QPushButton(nozzleSetTab);
        offsetRedBut->setObjectName(QStringLiteral("offsetRedBut"));
        offsetRedBut->setGeometry(QRect(790, 300, 41, 41));
        offsetRedBut->setMinimumSize(QSize(41, 41));
        offsetRedBut->setFont(font1);
        offsetRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        offsetShowLab = new QLabel(nozzleSetTab);
        offsetShowLab->setObjectName(QStringLiteral("offsetShowLab"));
        offsetShowLab->setGeometry(QRect(830, 300, 131, 41));
        offsetShowLab->setMinimumSize(QSize(0, 41));
        offsetShowLab->setFont(font2);
        offsetShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        offsetShowLab->setAlignment(Qt::AlignCenter);
        offsetAddBut = new QPushButton(nozzleSetTab);
        offsetAddBut->setObjectName(QStringLiteral("offsetAddBut"));
        offsetAddBut->setGeometry(QRect(960, 300, 41, 41));
        offsetAddBut->setMinimumSize(QSize(41, 41));
        offsetAddBut->setFont(font1);
        offsetAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        offsetLab = new QLabel(nozzleSetTab);
        offsetLab->setObjectName(QStringLiteral("offsetLab"));
        offsetLab->setGeometry(QRect(690, 300, 101, 41));
        offsetLab->setMinimumSize(QSize(101, 41));
        offsetLab->setFont(font2);
        offsetLab->setAlignment(Qt::AlignCenter);
        nozzleSel2RadioBut = new QRadioButton(nozzleSetTab);
        nozzleSel2RadioBut->setObjectName(QStringLiteral("nozzleSel2RadioBut"));
        nozzleSel2RadioBut->setGeometry(QRect(390, 300, 131, 41));
        nozzleSel2RadioBut->setFont(font3);
        nozzleSel2RadioBut->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        nozzleSel1RadioBut = new QRadioButton(nozzleSetTab);
        nozzleSel1RadioBut->setObjectName(QStringLiteral("nozzleSel1RadioBut"));
        nozzleSel1RadioBut->setGeometry(QRect(80, 300, 131, 41));
        nozzleSel1RadioBut->setFont(font3);
        nozzleSel1RadioBut->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        flashSprayLab = new QLabel(nozzleSetTab);
        flashSprayLab->setObjectName(QStringLiteral("flashSprayLab"));
        flashSprayLab->setGeometry(QRect(460, 410, 101, 41));
        flashSprayLab->setMinimumSize(QSize(101, 41));
        flashSprayLab->setFont(font2);
        flashSprayLab->setAlignment(Qt::AlignCenter);
        flashSprayCheckBox = new QCheckBox(nozzleSetTab);
        flashSprayCheckBox->setObjectName(QStringLiteral("flashSprayCheckBox"));
        flashSprayCheckBox->setGeometry(QRect(60, 500, 181, 31));
        flashSprayCheckBox->setFont(font2);
        flashSprayCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        flashSprayCheckBox->setChecked(false);
        flashSprayCheckBox->setAutoRepeat(false);
        flashSprayPWRedBut = new QPushButton(nozzleSetTab);
        flashSprayPWRedBut->setObjectName(QStringLiteral("flashSprayPWRedBut"));
        flashSprayPWRedBut->setGeometry(QRect(790, 500, 41, 41));
        flashSprayPWRedBut->setMinimumSize(QSize(41, 41));
        flashSprayPWRedBut->setFont(font1);
        flashSprayPWRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        flashSprayPWShowLab = new QLabel(nozzleSetTab);
        flashSprayPWShowLab->setObjectName(QStringLiteral("flashSprayPWShowLab"));
        flashSprayPWShowLab->setGeometry(QRect(830, 500, 131, 41));
        flashSprayPWShowLab->setMinimumSize(QSize(0, 41));
        flashSprayPWShowLab->setFont(font2);
        flashSprayPWShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        flashSprayPWShowLab->setAlignment(Qt::AlignCenter);
        flashSprayPWAddBut = new QPushButton(nozzleSetTab);
        flashSprayPWAddBut->setObjectName(QStringLiteral("flashSprayPWAddBut"));
        flashSprayPWAddBut->setGeometry(QRect(960, 500, 41, 41));
        flashSprayPWAddBut->setMinimumSize(QSize(41, 41));
        flashSprayPWAddBut->setFont(font1);
        flashSprayPWAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        flashSprayVolShowLab = new QLabel(nozzleSetTab);
        flashSprayVolShowLab->setObjectName(QStringLiteral("flashSprayVolShowLab"));
        flashSprayVolShowLab->setGeometry(QRect(440, 500, 131, 41));
        flashSprayVolShowLab->setMinimumSize(QSize(0, 41));
        flashSprayVolShowLab->setFont(font2);
        flashSprayVolShowLab->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        flashSprayVolShowLab->setAlignment(Qt::AlignCenter);
        flashSprayVoltLab = new QLabel(nozzleSetTab);
        flashSprayVoltLab->setObjectName(QStringLiteral("flashSprayVoltLab"));
        flashSprayVoltLab->setGeometry(QRect(300, 500, 101, 41));
        flashSprayVoltLab->setMinimumSize(QSize(101, 41));
        flashSprayVoltLab->setFont(font2);
        flashSprayVoltLab->setAlignment(Qt::AlignCenter);
        flashSprayVolRedBut = new QPushButton(nozzleSetTab);
        flashSprayVolRedBut->setObjectName(QStringLiteral("flashSprayVolRedBut"));
        flashSprayVolRedBut->setGeometry(QRect(400, 500, 41, 41));
        flashSprayVolRedBut->setMinimumSize(QSize(41, 41));
        flashSprayVolRedBut->setFont(font1);
        flashSprayVolRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        flashSprayPWLab = new QLabel(nozzleSetTab);
        flashSprayPWLab->setObjectName(QStringLiteral("flashSprayPWLab"));
        flashSprayPWLab->setGeometry(QRect(690, 500, 101, 41));
        flashSprayPWLab->setMinimumSize(QSize(101, 41));
        flashSprayPWLab->setFont(font2);
        flashSprayPWLab->setAlignment(Qt::AlignCenter);
        flashSprayVolAddBut = new QPushButton(nozzleSetTab);
        flashSprayVolAddBut->setObjectName(QStringLiteral("flashSprayVolAddBut"));
        flashSprayVolAddBut->setGeometry(QRect(570, 500, 41, 41));
        flashSprayVolAddBut->setMinimumSize(QSize(41, 41));
        flashSprayVolAddBut->setFont(font1);
        flashSprayVolAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printSetTabWid->addTab(nozzleSetTab, QString());
        UVSettingTab = new QWidget();
        UVSettingTab->setObjectName(QStringLiteral("UVSettingTab"));
        printSetTabWid->addTab(UVSettingTab, QString());

        retranslateUi(printSetting);

        printSetTabWid->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(printSetting);
    } // setupUi

    void retranslateUi(QWidget *printSetting)
    {
        printSetting->setWindowTitle(QApplication::translate("printSetting", "printSetting", 0));
        printSpeedRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        trigLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\247\246\345\217\221\346\226\271\345\274\217</span></p></body></html>", 0));
        printSpeedShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        printSpeedAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        printSpeedLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\351\200\237\345\272\246</span></p></body></html>", 0));
        inkjetLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\226\267\345\242\250\346\226\271\345\274\217</span></p></body></html>", 0));
        printDirLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\346\226\271\345\220\221</span></p></body></html>", 0));
        printDelayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\345\273\266\346\227\266</span></p></body></html>", 0));
        printDelayRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        printDelayShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        printDelayAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        synFrequencyLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\220\214\346\255\245\345\200\215\351\242\221</span></p></body></html>", 0));
        synFrequencyRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        synFrequencyShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        synFrequencyAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        printGrayAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        printGrayShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        printGrayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\347\201\260\345\272\246</span></p></body></html>", 0));
        printGrayRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        synWheelCheckBox->setText(QApplication::translate("printSetting", "\345\220\257\347\224\250\345\220\214\346\255\245\350\275\256", 0));
        voiceCheckBox->setText(QApplication::translate("printSetting", "\345\243\260\351\237\263", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(printStyleTab), QApplication::translate("printSetting", "\346\211\223\345\215\260\351\243\216\346\240\274", 0));
        DPILab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">DPI</span></p></body></html>", 0));
        DPI150RadioBut->setText(QApplication::translate("printSetting", "150", 0));
        DPI200RadioBut->setText(QApplication::translate("printSetting", "200", 0));
        DPI300RadioBut->setText(QApplication::translate("printSetting", "300", 0));
        DPI600RadioBut->setText(QApplication::translate("printSetting", "600", 0));
        repetePrintCheckBox->setText(QApplication::translate("printSetting", "\351\207\215\345\244\215\346\211\223\345\215\260", 0));
        repeteNumShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        repeteNumAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        repeteLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\207\215\345\244\215\346\254\241\346\225\260</span></p></body></html>", 0));
        repeteNumRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        repeteDelayRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        repeteDelayShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        repeteDelayAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        repeteDelayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\207\215\345\244\215\345\273\266\346\227\266</span></p></body></html>", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(settingTab), QApplication::translate("printSetting", "\351\253\230\347\272\247\350\256\276\347\275\256", 0));
        inkTypeLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\242\250\346\260\264\347\261\273\345\236\213</span></p></body></html>", 0));
        adaptParaCheckBox->setText(QApplication::translate("printSetting", "\350\207\252\351\200\202\345\272\224\345\217\202\346\225\260", 0));
        voltShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        voltAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        inkVoltLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\224\265\345\216\213</span></p></body></html>", 0));
        voltRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        PWShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        PWAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        PWLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\204\211\345\256\275</span></p></body></html>", 0));
        PWRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        nozzleSelLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\226\267\345\244\264\351\200\211\346\213\251</span></p></body></html>", 0));
        offsetRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        offsetShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        offsetAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        offsetLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\201\217\347\247\273\351\207\217</span></p></body></html>", 0));
        nozzleSel2RadioBut->setText(QApplication::translate("printSetting", "2", 0));
        nozzleSel1RadioBut->setText(QApplication::translate("printSetting", "1", 0));
        flashSprayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\227\252\345\226\267\350\256\276\347\275\256</span></p></body></html>", 0));
        flashSprayCheckBox->setText(QApplication::translate("printSetting", "\351\227\252\345\226\267", 0));
        flashSprayPWRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        flashSprayPWShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        flashSprayPWAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        flashSprayVolShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        flashSprayVoltLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\224\265\345\216\213</span></p></body></html>", 0));
        flashSprayVolRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        flashSprayPWLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\204\211\345\256\275</span></p></body></html>", 0));
        flashSprayVolAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(nozzleSetTab), QApplication::translate("printSetting", "\345\226\267\345\244\264\350\256\276\347\275\256", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(UVSettingTab), QApplication::translate("printSetting", "UV\347\201\257\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class printSetting: public Ui_printSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTSETTING_H
