﻿#include "UILanguage.h"
#include <QTextCodec>
#include "xml/tinyxml.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "filemanageform.h"
#include "ui_filemanageform.h"
#include "paramsettingform.h"
#include "ui_paramsettingform.h"
#include <QDir>


CUILanguage::CUILanguage(QObject* pMainwindow)
{
	m_pMainwindow = pMainwindow;


}


CUILanguage::~CUILanguage(void)
{}

void CUILanguage::ChangeLanguage(int nLanguageType)
{
	MainWindow* pMainwindow = (MainWindow*)(m_pMainwindow);
	char strFileName[100];
	QDir MultiLanguage;
	QString MultiLanguageDir = MultiLanguage.currentPath();
	
	m_codemode = false;//定义变量用于判断编码方式 初始为false
	//根据nLanguageType 读取相应的xml文件

	if(nLanguageType == 1)
	{	
#ifdef vsPath
        QString MultiLanguagePath = MultiLanguageDir + "/System/chinese.xml";
#elif defined qtPath
        QString MultiLanguagePath = MultiLanguageDir + "/HighResolutionPrinter/System/chinese.xml";
#else
        QString MultiLanguagePath = "/home/System/chinese.xml";
#endif
	   sprintf(strFileName,"%s",MultiLanguagePath.toLatin1().data());
	    m_codemode = true;   //中文时变量为true
        m_nLanguage = 1;
	 }
	if(nLanguageType == 0)
	{
#ifdef vsPath
        QString MultiLanguagePath = MultiLanguageDir + "/System/arabic.xml";
#elif defined qtPath
        QString MultiLanguagePath = MultiLanguageDir + "/HighResolutionPrinter/System/arabic.xml";
#else
        QString MultiLanguagePath = "/home/System/arabic.xml";
#endif
        sprintf(strFileName,"%s",MultiLanguagePath.toLatin1().data());
         m_nLanguage = 0;
      }
	if(nLanguageType == 5)
	{
#ifdef vsPath
        QString MultiLanguagePath = MultiLanguageDir + "/System/english.xml";
#elif defined qtPath
        QString MultiLanguagePath = MultiLanguageDir + "/HighResolutionPrinter/System/english.xml";
#else
        QString MultiLanguagePath = "/home/System/english.xml";
#endif
	    sprintf(strFileName,"%s",MultiLanguagePath.toLatin1().data());
	/*m_chinesetype = nLanguageType;*/
	//先读取窗体的名称，根据窗体的名称获得窗体指针，然后再给窗体的各控件赋值 
		m_nLanguage = 5;
	}

	// ? ?        ?    ?       ? ?   ? ??   ?     ?  ?   ? 

	TiXmlDocument doc(strFileName);
	bool loadOkay = doc.LoadFile();
	if (!loadOkay)
	{
		return;
	}
	TiXmlNode* node = 0;
	TiXmlElement* todoElement = 0;
	TiXmlElement* itemElement = 0;
	node = doc.FirstChild( "MES" );
	assert( node );
	todoElement = node->ToElement();
	assert( todoElement  );

	node = todoElement->FirstChildElement();	 
	assert( node );
	itemElement = node->ToElement();
	assert( itemElement  );

	 
	for( node = todoElement->FirstChildElement();node;node = node->NextSibling() )
	{
		const char* str ;
		str = node->ValueTStr().c_str();		 
		
		if(strcmp(str,"MainWindow") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow),node);			 
		}
		else if(strcmp(str,"FilemanageForm") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_fileManage),node);			 
		}
		else if(strcmp(str,"FileEditChild") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_fileManage->FormFileEditChild),node);			 
		}
		else if(strcmp(str,"FileManageChild") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_fileManage->FormFileManageChild),node);			 
		}
		else if(strcmp(str,"ParamSettingForm") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_paramsetting),node);			 
		}
		else if(strcmp(str,"printSetting") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_paramsetting->m_printSetting),node);			 
		}
		else if(strcmp(str,"sysSetting") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_paramsetting->m_sysSetting),node);			 
		}
		else if(strcmp(str,"countSetting") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_paramsetting->m_countSetting),node);			 
		}
		else if(strcmp(str,"aboutMac") == 0)
		{
			ChangeLanguageForItem((QObject*)(pMainwindow->m_paramsetting->m_aboutMac),node);			 
		}
	} 
}

void CUILanguage::ChangeLanguageForItem(QObject* pWidge,TiXmlNode* node)
{
	//读入各控件信息,并赋值
	TiXmlNode* nodeTmp = 0;
	QFont font;
	switch(m_nLanguage)
	{
		case 0: font.setFamily(QStringLiteral("Adobe Arabic"));;break;
		case 1: font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));;break;
		case 2:    ;break;
		case 3:    ;break;
		case 4:    ;break;
		case 5: font.setFamily(QStringLiteral("Times New Roman"));;break;
		default: ;
	}
	for( nodeTmp = node->IterateChildren(0);nodeTmp;nodeTmp = node->IterateChildren( nodeTmp ) )
	{
		const char* strItem = nodeTmp->ValueTStr().c_str();				 
		const char* strText; 
		TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
		strText = nodeText->ValueTStr().c_str();

		const char* tempVal= strItem;
		QString str(tempVal);

		if(str =="fontsize")
		{
			font.setPointSize(atoi(strText));
		}

		QPushButton *tempButton = pWidge->findChild<QPushButton *>(strItem);
		QLabel *tempLabel = pWidge->findChild<QLabel *>(strItem);
		QCheckBox *tempCheck = pWidge->findChild<QCheckBox *>(strItem);
		QTabWidget * tempQTabWidget = pWidge->findChild<QTabWidget *>(strItem); 
		QComboBox *tempQComboBox = pWidge->findChild<QComboBox *>(strItem); 
 		
	  //中文编码和多语言不一样 fromLocal8Bit适用于中文转换，fromUtf8适用于其他种类语言。
		if (m_codemode)  //中文进入的编码函数fromLocal8Bit 先暂时和多语言一样的编码函数 待在qt4上试验后删除
			{
				if(tempButton	)
				{
					tempButton->setFont(font);
                    tempButton->setText(QString::fromUtf8(strText));
				}        
				else if(tempLabel)
				{
				tempLabel->setFont(font);
                tempLabel->setText(QString::fromUtf8(strText));
				}
				else if(tempCheck)
                {
				tempCheck->setFont(font);
                tempCheck->setText(QString::fromUtf8(strText));
				}
				else if(tempQTabWidget)
				{
				//以#分解字符
				char seg[] = "#"; /*分隔符，分隔符可以为你指定的分号，空格等*/  
				int i =0;  
				char *substr= strtok((char*)strText, seg);/*利用现成的分割函数,substr为分割出来的子字符串*/  
    
				while (substr != NULL) {    
						tempQTabWidget->setTabText(i,QString::fromUtf8(substr));
                        tempQTabWidget->setFont(font);
						i++;  
						substr = strtok(NULL,seg);/*在第一次调用时，strtok()必需给予参数str字符串， 
						往后的调用则将参数str设置成NULL。每次调用成功则返回被分割出片段的指针。*/  
						}    			
 				}
				else if(tempQComboBox)
				{
				//以#分解字符
				char seg[] = "#"; /*分隔符，分隔符可以为你指定的分号，空格等*/  
				int i =0;  
				char *substr= strtok((char*)strText, seg);/*利用现成的分割函数,substr为分割出来的子字符串*/  
    
				while (substr != NULL) {    
						tempQComboBox->setItemText(i,QString::fromUtf8(substr));
                        tempQComboBox->setFont(font);
						i++;  
						substr = strtok(NULL,seg);/*在第一次调用时，strtok()必需给予参数str字符串， 
						往后的调用则将参数str设置成NULL。每次调用成功则返回被分割出片段的指针。*/  
					}    			
 				}
			}
		else    //非中文语言时 进入的编码函数fromUtf8  多语言在fromUtf8函数下不乱码
			{   
				if(tempButton	)
				{
					tempButton->setFont(font);
                    tempButton->setText(QString::fromUtf8(strText));
				}
                        
				else if(tempLabel)
				{
				   tempLabel->setFont(font);
                   tempLabel->setText(QString::fromUtf8(strText));
				}
				else if(tempCheck)
                {
				   tempCheck->setFont(font);
                   tempCheck->setText(QString::fromUtf8(strText));
				}
				else if(tempQTabWidget)
				{
				//以#分解字符
				char seg[] = "#"; /*分隔符，分隔符可以为你指定的分号，空格等*/  
				int i =0;  
				char *substr= strtok((char*)strText, seg);/*利用现成的分割函数,substr为分割出来的子字符串*/  
    
				while (substr != NULL) {    
						tempQTabWidget->setTabText(i,QString::fromUtf8(substr));
                        tempQTabWidget->setFont(font);
						i++;  
						substr = strtok(NULL,seg);/*在第一次调用时，strtok()必需给予参数str字符串， 
						往后的调用则将参数str设置成NULL。每次调用成功则返回被分割出片段的指针。*/  
						}    			
 				}
				else if(tempQComboBox)
				{
				//以#分解字符
				char seg[] = "#"; /*分隔符，分隔符可以为你指定的分号，空格等*/  
				int i =0;  
				char *substr= strtok((char*)strText, seg);/*利用现成的分割函数,substr为分割出来的子字符串*/  
    
				while (substr != NULL) {    
						tempQComboBox->setItemText(i,QString::fromUtf8(substr));
                        tempQComboBox->setFont(font);
						i++;  
						substr = strtok(NULL,seg);/*在第一次调用时，strtok()必需给予参数str字符串， 
						往后的调用则将参数str设置成NULL。每次调用成功则返回被分割出片段的指针。*/  
					}    			
 				}
			}
	}
}
