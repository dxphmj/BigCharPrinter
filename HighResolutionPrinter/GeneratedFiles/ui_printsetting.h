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
    QLabel *printStyleBGLabel;
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
    QLabel *settingBGLabel;
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
    QPushButton *flashSprayTimesRedBut;
    QLabel *flashSprayTimesShowLab;
    QPushButton *flashSprayTimesAddBut;
    QLabel *flashSprayInternalShowLab;
    QLabel *flashSprayInternalLab;
    QPushButton *flashSprayInternalRedBut;
    QLabel *flashSprayTimesLab;
    QPushButton *flashSprayInternalAddBut;
    QCheckBox *isCombineCheckBox;
    QLabel *printSetBGLabel;
    QWidget *UVSettingTab;
    QLabel *UVSetBGLabel;
    QCheckBox *isUVCheckBox;
    QPushButton *startTimeAddBut;
    QPushButton *delayTimeRedBut;
    QPushButton *startTimeRedBut;
    QLabel *delayTimeShowLab;
    QPushButton *delayTimeAddBut;
    QLabel *delayTimeLab;
    QLabel *startTimeShowLab;
    QLabel *startTimeLab;

    void setupUi(QWidget *printSetting)
    {
        if (printSetting->objectName().isEmpty())
            printSetting->setObjectName(QStringLiteral("printSetting"));
        printSetting->resize(1061, 651);
        printSetting->setStyleSheet(QStringLiteral("background-color: rgb(72,61, 139);"));
        printSetTabWid = new QTabWidget(printSetting);
        printSetTabWid->setObjectName(QStringLiteral("printSetTabWid"));
        printSetTabWid->setGeometry(QRect(20, 20, 1021, 621));
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
        trigLab->setGeometry(QRect(530, 110, 151, 41));
        trigLab->setMinimumSize(QSize(101, 41));
        trigLab->setFont(font);
        trigLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        trigLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printSpeedShowLab = new QLabel(printStyleTab);
        printSpeedShowLab->setObjectName(QStringLiteral("printSpeedShowLab"));
        printSpeedShowLab->setGeometry(QRect(280, 110, 131, 41));
        printSpeedShowLab->setMinimumSize(QSize(0, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(14);
        printSpeedShowLab->setFont(font2);
        printSpeedShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
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
        printSpeedLab->setGeometry(QRect(20, 110, 221, 41));
        printSpeedLab->setMinimumSize(QSize(101, 41));
        printSpeedLab->setFont(font);
        printSpeedLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        printSpeedLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        trigComBox = new QComboBox(printStyleTab);
        trigComBox->setObjectName(QStringLiteral("trigComBox"));
        trigComBox->setGeometry(QRect(680, 110, 181, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(14);
        trigComBox->setFont(font3);
        trigComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        inkjetComBox = new QComboBox(printStyleTab);
        inkjetComBox->setObjectName(QStringLiteral("inkjetComBox"));
        inkjetComBox->setGeometry(QRect(680, 200, 181, 41));
        inkjetComBox->setFont(font3);
        inkjetComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        inkjetLab = new QLabel(printStyleTab);
        inkjetLab->setObjectName(QStringLiteral("inkjetLab"));
        inkjetLab->setGeometry(QRect(530, 200, 151, 41));
        inkjetLab->setMinimumSize(QSize(101, 41));
        inkjetLab->setFont(font);
        inkjetLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        inkjetLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printDirComBox = new QComboBox(printStyleTab);
        printDirComBox->setObjectName(QStringLiteral("printDirComBox"));
        printDirComBox->setGeometry(QRect(680, 290, 181, 41));
        printDirComBox->setFont(font3);
        printDirComBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        printDirLab = new QLabel(printStyleTab);
        printDirLab->setObjectName(QStringLiteral("printDirLab"));
        printDirLab->setGeometry(QRect(530, 290, 151, 41));
        printDirLab->setMinimumSize(QSize(101, 41));
        printDirLab->setFont(font);
        printDirLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        printDirLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printDelayLab = new QLabel(printStyleTab);
        printDelayLab->setObjectName(QStringLiteral("printDelayLab"));
        printDelayLab->setGeometry(QRect(20, 200, 221, 41));
        printDelayLab->setMinimumSize(QSize(101, 41));
        printDelayLab->setFont(font);
        printDelayLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        printDelayLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
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
        printDelayShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
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
        synFrequencyLab->setGeometry(QRect(20, 290, 221, 41));
        synFrequencyLab->setMinimumSize(QSize(101, 41));
        synFrequencyLab->setFont(font);
        synFrequencyLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        synFrequencyLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
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
        synFrequencyShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
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
        printGrayShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        printGrayShowLab->setAlignment(Qt::AlignCenter);
        printGrayLab = new QLabel(printStyleTab);
        printGrayLab->setObjectName(QStringLiteral("printGrayLab"));
        printGrayLab->setGeometry(QRect(20, 380, 221, 41));
        printGrayLab->setMinimumSize(QSize(101, 41));
        printGrayLab->setFont(font);
        printGrayLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        printGrayLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printGrayRedBut = new QPushButton(printStyleTab);
        printGrayRedBut->setObjectName(QStringLiteral("printGrayRedBut"));
        printGrayRedBut->setGeometry(QRect(240, 380, 41, 41));
        printGrayRedBut->setMinimumSize(QSize(41, 41));
        printGrayRedBut->setFont(font1);
        printGrayRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        synWheelCheckBox = new QCheckBox(printStyleTab);
        synWheelCheckBox->setObjectName(QStringLiteral("synWheelCheckBox"));
        synWheelCheckBox->setGeometry(QRect(680, 385, 261, 31));
        synWheelCheckBox->setFont(font);
        synWheelCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        synWheelCheckBox->setChecked(false);
        synWheelCheckBox->setAutoRepeat(false);
        voiceCheckBox = new QCheckBox(printStyleTab);
        voiceCheckBox->setObjectName(QStringLiteral("voiceCheckBox"));
        voiceCheckBox->setGeometry(QRect(680, 470, 181, 31));
        voiceCheckBox->setFont(font);
        voiceCheckBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        voiceCheckBox->setChecked(false);
        voiceCheckBox->setAutoRepeat(false);
        printStyleBGLabel = new QLabel(printStyleTab);
        printStyleBGLabel->setObjectName(QStringLiteral("printStyleBGLabel"));
        printStyleBGLabel->setGeometry(QRect(0, 0, 1016, 571));
        printStyleBGLabel->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        printSetTabWid->addTab(printStyleTab, QString());
        printStyleBGLabel->raise();
        printSpeedRedBut->raise();
        trigLab->raise();
        printSpeedShowLab->raise();
        printSpeedAddBut->raise();
        printSpeedLab->raise();
        trigComBox->raise();
        inkjetComBox->raise();
        inkjetLab->raise();
        printDirComBox->raise();
        printDirLab->raise();
        printDelayLab->raise();
        printDelayRedBut->raise();
        printDelayShowLab->raise();
        printDelayAddBut->raise();
        synFrequencyLab->raise();
        synFrequencyRedBut->raise();
        synFrequencyShowLab->raise();
        synFrequencyAddBut->raise();
        printGrayAddBut->raise();
        printGrayShowLab->raise();
        printGrayLab->raise();
        printGrayRedBut->raise();
        synWheelCheckBox->raise();
        voiceCheckBox->raise();
        settingTab = new QWidget();
        settingTab->setObjectName(QStringLiteral("settingTab"));
        DPILab = new QLabel(settingTab);
        DPILab->setObjectName(QStringLiteral("DPILab"));
        DPILab->setGeometry(QRect(460, 80, 101, 41));
        DPILab->setMinimumSize(QSize(101, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font4.setPointSize(16);
        DPILab->setFont(font4);
        DPILab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        DPILab->setAlignment(Qt::AlignCenter);
        DPI150RadioBut = new QRadioButton(settingTab);
        DPI150RadioBut->setObjectName(QStringLiteral("DPI150RadioBut"));
        DPI150RadioBut->setGeometry(QRect(230, 160, 91, 41));
        DPI150RadioBut->setFont(font4);
        DPI150RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        DPI200RadioBut = new QRadioButton(settingTab);
        DPI200RadioBut->setObjectName(QStringLiteral("DPI200RadioBut"));
        DPI200RadioBut->setGeometry(QRect(370, 160, 91, 41));
        DPI200RadioBut->setFont(font4);
        DPI200RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        DPI300RadioBut = new QRadioButton(settingTab);
        DPI300RadioBut->setObjectName(QStringLiteral("DPI300RadioBut"));
        DPI300RadioBut->setGeometry(QRect(510, 160, 91, 41));
        DPI300RadioBut->setFont(font4);
        DPI300RadioBut->setStyleSheet(QLatin1String("background-color: rgb(67,51, 139);\n"
"color: rgb(255, 255, 255);"));
        DPI600RadioBut = new QRadioButton(settingTab);
        DPI600RadioBut->setObjectName(QStringLiteral("DPI600RadioBut"));
        DPI600RadioBut->setGeometry(QRect(650, 160, 91, 41));
        DPI600RadioBut->setFont(font4);
        DPI600RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        repetePrintCheckBox = new QCheckBox(settingTab);
        repetePrintCheckBox->setObjectName(QStringLiteral("repetePrintCheckBox"));
        repetePrintCheckBox->setGeometry(QRect(70, 240, 181, 31));
        repetePrintCheckBox->setFont(font);
        repetePrintCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        repetePrintCheckBox->setChecked(false);
        repetePrintCheckBox->setAutoRepeat(false);
        repeteNumShowLab = new QLabel(settingTab);
        repeteNumShowLab->setObjectName(QStringLiteral("repeteNumShowLab"));
        repeteNumShowLab->setGeometry(QRect(270, 310, 471, 41));
        repeteNumShowLab->setMinimumSize(QSize(0, 41));
        repeteNumShowLab->setFont(font2);
        repeteNumShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        repeteNumShowLab->setAlignment(Qt::AlignCenter);
        repeteNumAddBut = new QPushButton(settingTab);
        repeteNumAddBut->setObjectName(QStringLiteral("repeteNumAddBut"));
        repeteNumAddBut->setGeometry(QRect(740, 310, 41, 41));
        repeteNumAddBut->setMinimumSize(QSize(41, 41));
        repeteNumAddBut->setFont(font1);
        repeteNumAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteLab = new QLabel(settingTab);
        repeteLab->setObjectName(QStringLiteral("repeteLab"));
        repeteLab->setGeometry(QRect(40, 310, 191, 41));
        repeteLab->setMinimumSize(QSize(101, 41));
        repeteLab->setFont(font);
        repeteLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        repeteLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        repeteNumRedBut = new QPushButton(settingTab);
        repeteNumRedBut->setObjectName(QStringLiteral("repeteNumRedBut"));
        repeteNumRedBut->setGeometry(QRect(230, 310, 41, 41));
        repeteNumRedBut->setMinimumSize(QSize(41, 41));
        repeteNumRedBut->setFont(font1);
        repeteNumRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteDelayRedBut = new QPushButton(settingTab);
        repeteDelayRedBut->setObjectName(QStringLiteral("repeteDelayRedBut"));
        repeteDelayRedBut->setGeometry(QRect(230, 400, 41, 41));
        repeteDelayRedBut->setMinimumSize(QSize(41, 41));
        repeteDelayRedBut->setFont(font1);
        repeteDelayRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteDelayShowLab = new QLabel(settingTab);
        repeteDelayShowLab->setObjectName(QStringLiteral("repeteDelayShowLab"));
        repeteDelayShowLab->setGeometry(QRect(270, 400, 471, 41));
        repeteDelayShowLab->setMinimumSize(QSize(0, 41));
        repeteDelayShowLab->setFont(font2);
        repeteDelayShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        repeteDelayShowLab->setAlignment(Qt::AlignCenter);
        repeteDelayAddBut = new QPushButton(settingTab);
        repeteDelayAddBut->setObjectName(QStringLiteral("repeteDelayAddBut"));
        repeteDelayAddBut->setGeometry(QRect(740, 400, 41, 41));
        repeteDelayAddBut->setMinimumSize(QSize(41, 41));
        repeteDelayAddBut->setFont(font1);
        repeteDelayAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        repeteDelayLab = new QLabel(settingTab);
        repeteDelayLab->setObjectName(QStringLiteral("repeteDelayLab"));
        repeteDelayLab->setGeometry(QRect(40, 400, 191, 41));
        repeteDelayLab->setMinimumSize(QSize(101, 41));
        repeteDelayLab->setFont(font);
        repeteDelayLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        repeteDelayLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        settingBGLabel = new QLabel(settingTab);
        settingBGLabel->setObjectName(QStringLiteral("settingBGLabel"));
        settingBGLabel->setGeometry(QRect(0, 0, 1016, 571));
        settingBGLabel->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        printSetTabWid->addTab(settingTab, QString());
        settingBGLabel->raise();
        DPILab->raise();
        DPI150RadioBut->raise();
        DPI200RadioBut->raise();
        DPI300RadioBut->raise();
        DPI600RadioBut->raise();
        repetePrintCheckBox->raise();
        repeteNumShowLab->raise();
        repeteNumAddBut->raise();
        repeteLab->raise();
        repeteNumRedBut->raise();
        repeteDelayRedBut->raise();
        repeteDelayShowLab->raise();
        repeteDelayAddBut->raise();
        repeteDelayLab->raise();
        nozzleSetTab = new QWidget();
        nozzleSetTab->setObjectName(QStringLiteral("nozzleSetTab"));
        inkTypeLab = new QLabel(nozzleSetTab);
        inkTypeLab->setObjectName(QStringLiteral("inkTypeLab"));
        inkTypeLab->setGeometry(QRect(430, 60, 151, 41));
        inkTypeLab->setMinimumSize(QSize(101, 41));
        inkTypeLab->setFont(font);
        inkTypeLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        inkTypeLab->setAlignment(Qt::AlignCenter);
        adaptParaCheckBox = new QCheckBox(nozzleSetTab);
        adaptParaCheckBox->setObjectName(QStringLiteral("adaptParaCheckBox"));
        adaptParaCheckBox->setGeometry(QRect(80, 150, 221, 31));
        adaptParaCheckBox->setFont(font);
        adaptParaCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        adaptParaCheckBox->setChecked(false);
        adaptParaCheckBox->setAutoRepeat(false);
        voltShowLab = new QLabel(nozzleSetTab);
        voltShowLab->setObjectName(QStringLiteral("voltShowLab"));
        voltShowLab->setGeometry(QRect(440, 140, 131, 41));
        voltShowLab->setMinimumSize(QSize(0, 41));
        voltShowLab->setFont(font2);
        voltShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        voltShowLab->setAlignment(Qt::AlignCenter);
        voltAddBut = new QPushButton(nozzleSetTab);
        voltAddBut->setObjectName(QStringLiteral("voltAddBut"));
        voltAddBut->setGeometry(QRect(570, 140, 41, 41));
        voltAddBut->setMinimumSize(QSize(41, 41));
        voltAddBut->setFont(font1);
        voltAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        inkVoltLab = new QLabel(nozzleSetTab);
        inkVoltLab->setObjectName(QStringLiteral("inkVoltLab"));
        inkVoltLab->setGeometry(QRect(300, 140, 101, 41));
        inkVoltLab->setMinimumSize(QSize(101, 41));
        inkVoltLab->setFont(font);
        inkVoltLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        inkVoltLab->setAlignment(Qt::AlignCenter);
        voltRedBut = new QPushButton(nozzleSetTab);
        voltRedBut->setObjectName(QStringLiteral("voltRedBut"));
        voltRedBut->setGeometry(QRect(400, 140, 41, 41));
        voltRedBut->setMinimumSize(QSize(41, 41));
        voltRedBut->setFont(font1);
        voltRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        PWShowLab = new QLabel(nozzleSetTab);
        PWShowLab->setObjectName(QStringLiteral("PWShowLab"));
        PWShowLab->setGeometry(QRect(790, 140, 131, 41));
        PWShowLab->setMinimumSize(QSize(0, 41));
        PWShowLab->setFont(font2);
        PWShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        PWShowLab->setAlignment(Qt::AlignCenter);
        PWAddBut = new QPushButton(nozzleSetTab);
        PWAddBut->setObjectName(QStringLiteral("PWAddBut"));
        PWAddBut->setGeometry(QRect(920, 140, 41, 41));
        PWAddBut->setMinimumSize(QSize(41, 41));
        PWAddBut->setFont(font1);
        PWAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        PWLab = new QLabel(nozzleSetTab);
        PWLab->setObjectName(QStringLiteral("PWLab"));
        PWLab->setGeometry(QRect(650, 140, 101, 41));
        PWLab->setMinimumSize(QSize(101, 41));
        PWLab->setFont(font);
        PWLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        PWLab->setAlignment(Qt::AlignCenter);
        PWRedBut = new QPushButton(nozzleSetTab);
        PWRedBut->setObjectName(QStringLiteral("PWRedBut"));
        PWRedBut->setGeometry(QRect(750, 140, 41, 41));
        PWRedBut->setMinimumSize(QSize(41, 41));
        PWRedBut->setFont(font1);
        PWRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        nozzleSelLab = new QLabel(nozzleSetTab);
        nozzleSelLab->setObjectName(QStringLiteral("nozzleSelLab"));
        nozzleSelLab->setGeometry(QRect(410, 220, 191, 41));
        nozzleSelLab->setMinimumSize(QSize(101, 41));
        nozzleSelLab->setFont(font);
        nozzleSelLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        nozzleSelLab->setAlignment(Qt::AlignCenter);
        offsetRedBut = new QPushButton(nozzleSetTab);
        offsetRedBut->setObjectName(QStringLiteral("offsetRedBut"));
        offsetRedBut->setGeometry(QRect(750, 300, 41, 41));
        offsetRedBut->setMinimumSize(QSize(41, 41));
        offsetRedBut->setFont(font1);
        offsetRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        offsetShowLab = new QLabel(nozzleSetTab);
        offsetShowLab->setObjectName(QStringLiteral("offsetShowLab"));
        offsetShowLab->setGeometry(QRect(790, 300, 131, 41));
        offsetShowLab->setMinimumSize(QSize(0, 41));
        offsetShowLab->setFont(font2);
        offsetShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        offsetShowLab->setAlignment(Qt::AlignCenter);
        offsetAddBut = new QPushButton(nozzleSetTab);
        offsetAddBut->setObjectName(QStringLiteral("offsetAddBut"));
        offsetAddBut->setGeometry(QRect(920, 300, 41, 41));
        offsetAddBut->setMinimumSize(QSize(41, 41));
        offsetAddBut->setFont(font1);
        offsetAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        offsetLab = new QLabel(nozzleSetTab);
        offsetLab->setObjectName(QStringLiteral("offsetLab"));
        offsetLab->setGeometry(QRect(630, 300, 121, 41));
        offsetLab->setMinimumSize(QSize(101, 41));
        offsetLab->setFont(font);
        offsetLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        offsetLab->setAlignment(Qt::AlignCenter);
        nozzleSel2RadioBut = new QRadioButton(nozzleSetTab);
        nozzleSel2RadioBut->setObjectName(QStringLiteral("nozzleSel2RadioBut"));
        nozzleSel2RadioBut->setGeometry(QRect(470, 300, 81, 41));
        nozzleSel2RadioBut->setFont(font4);
        nozzleSel2RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        nozzleSel1RadioBut = new QRadioButton(nozzleSetTab);
        nozzleSel1RadioBut->setObjectName(QStringLiteral("nozzleSel1RadioBut"));
        nozzleSel1RadioBut->setGeometry(QRect(370, 300, 81, 41));
        nozzleSel1RadioBut->setFont(font4);
        nozzleSel1RadioBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        flashSprayLab = new QLabel(nozzleSetTab);
        flashSprayLab->setObjectName(QStringLiteral("flashSprayLab"));
        flashSprayLab->setGeometry(QRect(410, 380, 191, 41));
        flashSprayLab->setMinimumSize(QSize(101, 41));
        flashSprayLab->setFont(font);
        flashSprayLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        flashSprayLab->setAlignment(Qt::AlignCenter);
        flashSprayCheckBox = new QCheckBox(nozzleSetTab);
        flashSprayCheckBox->setObjectName(QStringLiteral("flashSprayCheckBox"));
        flashSprayCheckBox->setGeometry(QRect(120, 470, 181, 31));
        flashSprayCheckBox->setFont(font);
        flashSprayCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        flashSprayCheckBox->setChecked(false);
        flashSprayCheckBox->setAutoRepeat(false);
        flashSprayTimesRedBut = new QPushButton(nozzleSetTab);
        flashSprayTimesRedBut->setObjectName(QStringLiteral("flashSprayTimesRedBut"));
        flashSprayTimesRedBut->setGeometry(QRect(750, 470, 41, 41));
        flashSprayTimesRedBut->setMinimumSize(QSize(41, 41));
        flashSprayTimesRedBut->setFont(font1);
        flashSprayTimesRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        flashSprayTimesShowLab = new QLabel(nozzleSetTab);
        flashSprayTimesShowLab->setObjectName(QStringLiteral("flashSprayTimesShowLab"));
        flashSprayTimesShowLab->setGeometry(QRect(790, 470, 131, 41));
        flashSprayTimesShowLab->setMinimumSize(QSize(0, 41));
        flashSprayTimesShowLab->setFont(font2);
        flashSprayTimesShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        flashSprayTimesShowLab->setAlignment(Qt::AlignCenter);
        flashSprayTimesAddBut = new QPushButton(nozzleSetTab);
        flashSprayTimesAddBut->setObjectName(QStringLiteral("flashSprayTimesAddBut"));
        flashSprayTimesAddBut->setGeometry(QRect(920, 470, 41, 41));
        flashSprayTimesAddBut->setMinimumSize(QSize(41, 41));
        flashSprayTimesAddBut->setFont(font1);
        flashSprayTimesAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        flashSprayInternalShowLab = new QLabel(nozzleSetTab);
        flashSprayInternalShowLab->setObjectName(QStringLiteral("flashSprayInternalShowLab"));
        flashSprayInternalShowLab->setGeometry(QRect(440, 470, 131, 41));
        flashSprayInternalShowLab->setMinimumSize(QSize(0, 41));
        flashSprayInternalShowLab->setFont(font2);
        flashSprayInternalShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        flashSprayInternalShowLab->setAlignment(Qt::AlignCenter);
        flashSprayInternalLab = new QLabel(nozzleSetTab);
        flashSprayInternalLab->setObjectName(QStringLiteral("flashSprayInternalLab"));
        flashSprayInternalLab->setGeometry(QRect(300, 470, 101, 41));
        flashSprayInternalLab->setMinimumSize(QSize(101, 41));
        flashSprayInternalLab->setFont(font);
        flashSprayInternalLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        flashSprayInternalLab->setAlignment(Qt::AlignCenter);
        flashSprayInternalRedBut = new QPushButton(nozzleSetTab);
        flashSprayInternalRedBut->setObjectName(QStringLiteral("flashSprayInternalRedBut"));
        flashSprayInternalRedBut->setGeometry(QRect(400, 470, 41, 41));
        flashSprayInternalRedBut->setMinimumSize(QSize(41, 41));
        flashSprayInternalRedBut->setFont(font1);
        flashSprayInternalRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        flashSprayTimesLab = new QLabel(nozzleSetTab);
        flashSprayTimesLab->setObjectName(QStringLiteral("flashSprayTimesLab"));
        flashSprayTimesLab->setGeometry(QRect(650, 470, 101, 41));
        flashSprayTimesLab->setMinimumSize(QSize(101, 41));
        flashSprayTimesLab->setFont(font);
        flashSprayTimesLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        flashSprayTimesLab->setAlignment(Qt::AlignCenter);
        flashSprayInternalAddBut = new QPushButton(nozzleSetTab);
        flashSprayInternalAddBut->setObjectName(QStringLiteral("flashSprayInternalAddBut"));
        flashSprayInternalAddBut->setGeometry(QRect(570, 470, 41, 41));
        flashSprayInternalAddBut->setMinimumSize(QSize(41, 41));
        flashSprayInternalAddBut->setFont(font1);
        flashSprayInternalAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        isCombineCheckBox = new QCheckBox(nozzleSetTab);
        isCombineCheckBox->setObjectName(QStringLiteral("isCombineCheckBox"));
        isCombineCheckBox->setGeometry(QRect(120, 300, 181, 31));
        isCombineCheckBox->setFont(font);
        isCombineCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        isCombineCheckBox->setChecked(false);
        isCombineCheckBox->setAutoRepeat(false);
        printSetBGLabel = new QLabel(nozzleSetTab);
        printSetBGLabel->setObjectName(QStringLiteral("printSetBGLabel"));
        printSetBGLabel->setGeometry(QRect(0, 0, 1016, 571));
        printSetBGLabel->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        printSetTabWid->addTab(nozzleSetTab, QString());
        printSetBGLabel->raise();
        inkTypeLab->raise();
        adaptParaCheckBox->raise();
        voltShowLab->raise();
        voltAddBut->raise();
        inkVoltLab->raise();
        voltRedBut->raise();
        PWShowLab->raise();
        PWAddBut->raise();
        PWLab->raise();
        PWRedBut->raise();
        nozzleSelLab->raise();
        offsetRedBut->raise();
        offsetShowLab->raise();
        offsetAddBut->raise();
        offsetLab->raise();
        nozzleSel2RadioBut->raise();
        nozzleSel1RadioBut->raise();
        flashSprayLab->raise();
        flashSprayCheckBox->raise();
        flashSprayTimesRedBut->raise();
        flashSprayTimesShowLab->raise();
        flashSprayTimesAddBut->raise();
        flashSprayInternalShowLab->raise();
        flashSprayInternalLab->raise();
        flashSprayInternalRedBut->raise();
        flashSprayTimesLab->raise();
        flashSprayInternalAddBut->raise();
        isCombineCheckBox->raise();
        UVSettingTab = new QWidget();
        UVSettingTab->setObjectName(QStringLiteral("UVSettingTab"));
        UVSetBGLabel = new QLabel(UVSettingTab);
        UVSetBGLabel->setObjectName(QStringLiteral("UVSetBGLabel"));
        UVSetBGLabel->setGeometry(QRect(0, 0, 1016, 571));
        UVSetBGLabel->setStyleSheet(QStringLiteral("background-color: rgb(67,51, 139);"));
        isUVCheckBox = new QCheckBox(UVSettingTab);
        isUVCheckBox->setObjectName(QStringLiteral("isUVCheckBox"));
        isUVCheckBox->setGeometry(QRect(300, 170, 181, 31));
        isUVCheckBox->setFont(font);
        isUVCheckBox->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        isUVCheckBox->setChecked(false);
        isUVCheckBox->setAutoRepeat(false);
        startTimeAddBut = new QPushButton(UVSettingTab);
        startTimeAddBut->setObjectName(QStringLiteral("startTimeAddBut"));
        startTimeAddBut->setGeometry(QRect(860, 330, 41, 41));
        startTimeAddBut->setMinimumSize(QSize(41, 41));
        startTimeAddBut->setFont(font1);
        startTimeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        delayTimeRedBut = new QPushButton(UVSettingTab);
        delayTimeRedBut->setObjectName(QStringLiteral("delayTimeRedBut"));
        delayTimeRedBut->setGeometry(QRect(490, 240, 41, 41));
        delayTimeRedBut->setMinimumSize(QSize(41, 41));
        delayTimeRedBut->setFont(font1);
        delayTimeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        startTimeRedBut = new QPushButton(UVSettingTab);
        startTimeRedBut->setObjectName(QStringLiteral("startTimeRedBut"));
        startTimeRedBut->setGeometry(QRect(490, 330, 41, 41));
        startTimeRedBut->setMinimumSize(QSize(41, 41));
        startTimeRedBut->setFont(font1);
        startTimeRedBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        delayTimeShowLab = new QLabel(UVSettingTab);
        delayTimeShowLab->setObjectName(QStringLiteral("delayTimeShowLab"));
        delayTimeShowLab->setGeometry(QRect(530, 240, 331, 41));
        delayTimeShowLab->setMinimumSize(QSize(0, 41));
        delayTimeShowLab->setFont(font2);
        delayTimeShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        delayTimeShowLab->setAlignment(Qt::AlignCenter);
        delayTimeAddBut = new QPushButton(UVSettingTab);
        delayTimeAddBut->setObjectName(QStringLiteral("delayTimeAddBut"));
        delayTimeAddBut->setGeometry(QRect(860, 240, 41, 41));
        delayTimeAddBut->setMinimumSize(QSize(41, 41));
        delayTimeAddBut->setFont(font1);
        delayTimeAddBut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 230);"));
        delayTimeLab = new QLabel(UVSettingTab);
        delayTimeLab->setObjectName(QStringLiteral("delayTimeLab"));
        delayTimeLab->setGeometry(QRect(300, 240, 191, 41));
        delayTimeLab->setMinimumSize(QSize(101, 41));
        delayTimeLab->setFont(font);
        delayTimeLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        delayTimeLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        startTimeShowLab = new QLabel(UVSettingTab);
        startTimeShowLab->setObjectName(QStringLiteral("startTimeShowLab"));
        startTimeShowLab->setGeometry(QRect(530, 330, 331, 41));
        startTimeShowLab->setMinimumSize(QSize(0, 41));
        startTimeShowLab->setFont(font2);
        startTimeShowLab->setStyleSheet(QLatin1String("background-color: rgb(72,61, 139);\n"
"color: rgb(255, 255, 255);"));
        startTimeShowLab->setAlignment(Qt::AlignCenter);
        startTimeLab = new QLabel(UVSettingTab);
        startTimeLab->setObjectName(QStringLiteral("startTimeLab"));
        startTimeLab->setGeometry(QRect(300, 330, 191, 41));
        startTimeLab->setMinimumSize(QSize(101, 41));
        startTimeLab->setFont(font);
        startTimeLab->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(67,51, 139);"));
        startTimeLab->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        printSetTabWid->addTab(UVSettingTab, QString());

        retranslateUi(printSetting);

        printSetTabWid->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(printSetting);
    } // setupUi

    void retranslateUi(QWidget *printSetting)
    {
        printSetting->setWindowTitle(QApplication::translate("printSetting", "printSetting", 0));
        printSpeedRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        trigLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\247\246\345\217\221\346\226\271\345\274\217</span></p></body></html>", 0));
        printSpeedShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">85</span></p></body></html>", 0));
        printSpeedAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        printSpeedLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\351\200\237\345\272\246</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">m/min</span></p></body></html>", 0));
        inkjetLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\226\267\345\242\250\346\226\271\345\274\217</span></p></body></html>", 0));
        printDirLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\346\226\271\345\220\221</span></p></body></html>", 0));
        printDelayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\345\273\266\346\227\266</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">ms</span></p></body></html>", 0));
        printDelayRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        printDelayShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">20</span></p></body></html>", 0));
        printDelayAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        synFrequencyLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\220\214\346\255\245\345\200\215\351\242\221</span></p></body></html>", 0));
        synFrequencyRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        synFrequencyShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        synFrequencyAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        printGrayAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        printGrayShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        printGrayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\211\223\345\215\260\347\201\260\345\272\246</span></p></body></html>", 0));
        printGrayRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        synWheelCheckBox->setText(QApplication::translate("printSetting", "\345\220\257\347\224\250\345\220\214\346\255\245\350\275\256", 0));
        voiceCheckBox->setText(QApplication::translate("printSetting", "\345\243\260\351\237\263", 0));
        printStyleBGLabel->setText(QString());
        printSetTabWid->setTabText(printSetTabWid->indexOf(printStyleTab), QApplication::translate("printSetting", "\346\211\223\345\215\260\351\243\216\346\240\274", 0));
        DPILab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">DPI</span></p></body></html>", 0));
        DPI150RadioBut->setText(QApplication::translate("printSetting", "150", 0));
        DPI200RadioBut->setText(QApplication::translate("printSetting", "200", 0));
        DPI300RadioBut->setText(QApplication::translate("printSetting", "300", 0));
        DPI600RadioBut->setText(QApplication::translate("printSetting", "600", 0));
        repetePrintCheckBox->setText(QApplication::translate("printSetting", "\351\207\215\345\244\215\346\211\223\345\215\260", 0));
        repeteNumShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        repeteNumAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        repeteLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\207\215\345\244\215\346\254\241\346\225\260</span></p></body></html>", 0));
        repeteNumRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        repeteDelayRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        repeteDelayShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">100</span></p></body></html>", 0));
        repeteDelayAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        repeteDelayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\207\215\345\244\215\345\273\266\346\227\266</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">ms</span></p></body></html>", 0));
        settingBGLabel->setText(QString());
        printSetTabWid->setTabText(printSetTabWid->indexOf(settingTab), QApplication::translate("printSetting", "\351\253\230\347\272\247\350\256\276\347\275\256", 0));
        inkTypeLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\242\250\346\260\264\347\261\273\345\236\213</span></p></body></html>", 0));
        adaptParaCheckBox->setText(QApplication::translate("printSetting", "\350\207\252\351\200\202\345\272\224\345\217\202\346\225\260", 0));
        voltShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">8.5</span></p></body></html>", 0));
        voltAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        inkVoltLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\347\224\265\345\216\213</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">V</span></p></body></html>", 0));
        voltRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        PWShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1.8</span></p></body></html>", 0));
        PWAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        PWLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\350\204\211\345\256\275</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">ms</span></p></body></html>", 0));
        PWRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        nozzleSelLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\226\267\345\244\264\351\200\211\346\213\251</span></p></body></html>", 0));
        offsetRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        offsetShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">0</span></p></body></html>", 0));
        offsetAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        offsetLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\201\217\347\247\273\351\207\217</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">mm</span></p></body></html>", 0));
        nozzleSel2RadioBut->setText(QApplication::translate("printSetting", "2", 0));
        nozzleSel1RadioBut->setText(QApplication::translate("printSetting", "1", 0));
        flashSprayLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\227\252\345\226\267\350\256\276\347\275\256</span></p></body></html>", 0));
        flashSprayCheckBox->setText(QApplication::translate("printSetting", "\351\227\252\345\226\267", 0));
        flashSprayTimesRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        flashSprayTimesShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">1</span></p></body></html>", 0));
        flashSprayTimesAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        flashSprayInternalShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">5</span></p></body></html>", 0));
        flashSprayInternalLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\351\227\264\351\232\224</span><span style=\" font-family:'\345\256\213\344\275\223'; font-size:14pt; color:#ffffff;\">s</span></p></body></html>", 0));
        flashSprayInternalRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        flashSprayTimesLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\346\254\241\346\225\260</span></p></body></html>", 0));
        flashSprayInternalAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        isCombineCheckBox->setText(QApplication::translate("printSetting", "\346\213\274\346\216\245", 0));
        printSetBGLabel->setText(QString());
        printSetTabWid->setTabText(printSetTabWid->indexOf(nozzleSetTab), QApplication::translate("printSetting", "\345\226\267\345\244\264\350\256\276\347\275\256", 0));
        UVSetBGLabel->setText(QString());
        isUVCheckBox->setText(QApplication::translate("printSetting", "\345\220\257\347\224\250UV\347\201\257", 0));
        startTimeAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        delayTimeRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        startTimeRedBut->setText(QApplication::translate("printSetting", "\357\274\215", 0));
        delayTimeShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">500</span></p></body></html>", 0));
        delayTimeAddBut->setText(QApplication::translate("printSetting", "\357\274\213", 0));
        delayTimeLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\273\266\351\225\277\346\227\266\351\227\264/ms</span></p></body></html>", 0));
        startTimeShowLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">500</span></p></body></html>", 0));
        startTimeLab->setText(QApplication::translate("printSetting", "<html><head/><body><p><span style=\" color:#ffffff;\">\345\274\200\345\247\213\346\227\266\351\225\277/ms</span></p></body></html>", 0));
        printSetTabWid->setTabText(printSetTabWid->indexOf(UVSettingTab), QApplication::translate("printSetting", "UV\347\201\257\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class printSetting: public Ui_printSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTSETTING_H
