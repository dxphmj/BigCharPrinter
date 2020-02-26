#include "ClassMessage.h"
#include "sstream"
#include <fstream>
#include <stdio.h>
#include "xml\tinyxml.h"
#include <QPainter>
#include <io.h>
#include "QFileInfo"
#include <Windows.h>
#include "backend\zint.h"
#include "wordStock\\GetHZinfo.h"

//#include <qwidget.h>

ClassMessage::ClassMessage(void)
{
}

ClassMessage::~ClassMessage(void)
{
}

BYTE ClassMessage::getByteFromDot(bool boDot,int moveNum)
{
	if (boDot)
	{
		return 1<<moveNum;
	} 
	else
	{
		return 0;
	}
}
	
string ClassMessage::to_String(int n)
{
	int m = n;
	char s[max];
	char ss[max];
	int i=0,j=0;
	if (n < 0)// 处理负数
	{
		m = 0 - m;
		j = 1;
		ss[0] = '-';
	}    
	while (m>0)
	{
		s[i++] = m % 10 + '0';
		m /= 10;
	}
	s[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		ss[j++] = s[i--];
	}
	if (n==0)
	{
            ss[j++] = '0';
	}
	ss[j] = '\0';    
	return ss;
}

string ClassMessage::DEC_to_BIN(long long Dec)
{
	string DecToBin;
	while (Dec>0)
	{
		if (Dec %2>0)
		{
			DecToBin=this->to_String(Dec %2)+DecToBin;
		}
		else
		{
			DecToBin=this->to_String(0)+DecToBin;
		}
		Dec=Dec/2;
	}
	return DecToBin;
}

long long ClassMessage::BIN_to_DEC(string Bin)
{
	long long BinToDec=0;
	for (int i=0;i<Bin.length();i++)
	{
		std::stringstream ss;
		ss<<Bin.substr(i,1);
		int intss;
		ss>>intss;
		BinToDec=BinToDec*2+intss;
	}
	return  BinToDec;
}

bool ClassMessage::readBin(string FontName,int offset,char *arr, int DataLen )
{
	ifstream file;
	string path="\\Storage Card\\User\\Font\\";    //E:\\

	path = FontName;
	file.open(path.c_str(),ios::binary);
	file.seekg(offset,ios::beg);
	file.read(arr,DataLen);
	return true;
}

void ClassMessage::DrawDot(CDC* pDC)
{
	for (int i = 0; i < OBJ_Vec.size(); i++)
	{
		OBJ_Vec[i].DrawDot(pDC);
	}
}

//判断是否有OBJ被选中
void ClassMessage::JudgeIfOBJ_Selected(QPoint p_Relative)
{
	//计算鼠标相对于FileManageChild窗口的坐标位置
	int x_pos = p_Relative.x();
	int y_pos = p_Relative.y();
	//判断该位置是否在控件editPreviewText范围内
	if ((x_pos>=0 && x_pos<=1041) && (y_pos>=0 && y_pos<=241))
	{
		int nLin;
		int nRow;	 
		nLin = ( 241 - y_pos ) / 5;
		nRow = x_pos / 5;
		vector<OBJ_Control>::iterator itr = this->OBJ_Vec.begin();
		while (itr != this->OBJ_Vec.end())
		{		
			int x = itr->intLineStart;
			int x0 = itr->intLineSize;
			int y = itr->intRowStart;
			int y0 = itr->intRowSize;
			if (nLin>=itr->intLineStart && nLin<=(itr->intLineStart+itr->intLineSize)
				&& nRow>=itr->intRowStart && nRow<=(itr->intRowStart+itr->intRowSize))
			{
				if (itr->booFocus == true && itr->booBeenDragged == false)
				{
					itr->booFocus = false;
				}
				else if (itr->booFocus == false)
				{
					itr->booFocus = true;
				}
				itr->booBeenDragged = false;
			}
			else
			{
				if (itr->booFocus == true && itr->booBeenDragged == false)
				{
					itr->booFocus = false;
				}
				itr->booBeenDragged = false;
			}
			++itr;
		}
	}
}

//判断用户输入的文件名strFileName是否和本地已有的xml文件名重复
char* ClassMessage::GenerateFileName(string tmpFileName)
{
	int tmpFileNum = 1;
	bool fileRepeat = true;
	char CurFilePath[256];
	sprintf(CurFilePath,"User/Label/%s%d.lab",tmpFileName.c_str(),tmpFileNum);
	while (fileRepeat == true)
	{
		QFileInfo fi(CurFilePath);
		if (fi.exists())
		{
			tmpFileNum++;
			sprintf(CurFilePath,"User/Label/%s%d.lab",tmpFileName.c_str(),tmpFileNum);
		}
		else
		{
			fileRepeat = false;
			break;
		}
	}
	return CurFilePath;
}

//生成自动保存的条形码的文件名
char* ClassMessage::Generate2DcodeName(string strFileName)
{
	int tmpFileNum = 1;
	bool fileRepeat = true;
	char CurFilePath[256];
	sprintf(CurFilePath,"User/Logo/%s%d.bmp",strFileName.c_str(),tmpFileNum);
	while (fileRepeat == true)
	{
		QFileInfo fi(CurFilePath);
		if (fi.exists())
		{
			tmpFileNum++;
			sprintf(CurFilePath,"User/Logo/%s%d.bmp",strFileName.c_str(),tmpFileNum);
		}
		else
		{
			fileRepeat = false;
			break;
		}
	}
	return CurFilePath;
}

void ClassMessage::SaveObjectsToXml(char* strFileName)
{
	TiXmlDocument doc;

	TiXmlElement itemMes( "MES" );

	TiXmlElement itemPro( "PRO" );
	TiXmlElement itemMatrix( "Matrix" );
	TiXmlElement itemPixel("Pixel");
	TiXmlElement itemReverse("Reverse");
	TiXmlElement itemInverse("Inverse");
	TiXmlText textMatrix(strMatrix.c_str());
	TiXmlText textPixel(to_String(Pixel+1).c_str());
	TiXmlText textReverse(Reverse.c_str());
	TiXmlText textInverse(Inverse.c_str());

	itemMatrix.InsertEndChild(textMatrix);
	itemPixel.InsertEndChild(textPixel);
	itemReverse.InsertEndChild(textReverse);
	itemInverse.InsertEndChild(textInverse);
	itemPro.InsertEndChild( itemMatrix );
	itemPro.InsertEndChild( itemPixel );
	itemPro.InsertEndChild( itemReverse );
	itemPro.InsertEndChild( itemInverse );
	itemMes.InsertEndChild( itemPro );

	for(int i = 0; i < OBJ_Vec.size(); i++)
	{
		TiXmlElement itemObj( "OBJ" ); 
		TiXmlElement itemTYPE1("TYPE1");
		TiXmlElement itemTYPE2("TYPE2");
		TiXmlElement itemLineStart("LineStart");
		TiXmlElement itemRowStart("RowStart");
		TiXmlElement itemLineSize("LineSize");
		TiXmlElement itemRowSize("RowSize");
		TiXmlElement itemSW("SW");
		TiXmlElement itemSS("SS");
		TiXmlElement itemNEG("NEG");
		TiXmlElement itemBWDx("BWDx");
		TiXmlElement itemBWDy("BWDy");


		TiXmlText textType1(OBJ_Vec[i].strType1.c_str());
		TiXmlText textType2(OBJ_Vec[i].strType2.c_str());
		TiXmlText textLinestart(to_String(OBJ_Vec[i].intLineStart).c_str());
		TiXmlText textRowstart(to_String(OBJ_Vec[i].intRowStart).c_str());
		TiXmlText textLinesize(to_String(OBJ_Vec[i].intLineSize).c_str());
		TiXmlText textRowsize(to_String(OBJ_Vec[i].intRowSize).c_str());
		TiXmlText textSW(to_String(OBJ_Vec[i].intSW).c_str());
		TiXmlText textSS(to_String(OBJ_Vec[i].intSS).c_str());
		TiXmlText textNEG(to_String(OBJ_Vec[i].booNEG).c_str());///这几个bool是个坑
		TiXmlText textBWDx(to_String(OBJ_Vec[i].booBWDx).c_str());
		TiXmlText textBWDy(to_String(OBJ_Vec[i].booBWDy).c_str());


		itemTYPE1.InsertEndChild(textType1);
		itemTYPE2.InsertEndChild(textType2);
		itemLineStart.InsertEndChild(textLinestart);
		itemRowStart.InsertEndChild(textRowstart);
		itemLineSize.InsertEndChild(textLinesize);
		itemRowSize.InsertEndChild(textRowsize);
		itemSW.InsertEndChild(textSW);
		itemSS.InsertEndChild(textSS);
		itemNEG.InsertEndChild(textNEG);
		itemBWDx.InsertEndChild(textBWDx);
		itemBWDy.InsertEndChild(textBWDy);

		itemObj.InsertEndChild( itemTYPE1 );
		itemObj.InsertEndChild( itemTYPE2 );
		itemObj.InsertEndChild( itemLineStart );
		itemObj.InsertEndChild( itemRowStart );
		itemObj.InsertEndChild( itemLineSize );
		itemObj.InsertEndChild( itemRowSize );
		itemObj.InsertEndChild( itemSW );
		itemObj.InsertEndChild( itemSS );
		itemObj.InsertEndChild( itemNEG );
		itemObj.InsertEndChild( itemBWDx );
		itemObj.InsertEndChild( itemBWDy );


		if (OBJ_Vec[i].strType2=="text")
		{
			TiXmlElement itemsetFONT("setFONT");
			TiXmlElement itemSetTEXT( "setTEXT" );

			TiXmlText textSetFont(OBJ_Vec[i].strFont.c_str());
			TiXmlText textSetTEXT(OBJ_Vec[i].strText.c_str());

			itemsetFONT.InsertEndChild(textSetFont);
			itemSetTEXT.InsertEndChild(textSetTEXT);

			itemObj.InsertEndChild( itemsetFONT );
			itemObj.InsertEndChild( itemSetTEXT );
		}
		else if (OBJ_Vec[i].strType2=="serial")
		{
			TiXmlElement itemsetFONT("setFONT");
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemFirstLimit( "FirstLimit" );
			TiXmlElement itemSecondLimit( "SecondLimit" );
			TiXmlElement itemStartValue( "StartValue" );
			TiXmlElement itemStep( "Step" );
			TiXmlElement itemRepeat( "Repeat" );
			TiXmlElement itemDigits( "Digits" );
			TiXmlElement itemFormat( "Format" );
			TiXmlElement itemCounter( "Counter" );

			TiXmlText textSetFont(OBJ_Vec[i].strFont.c_str());
			TiXmlText textSetTEXT(OBJ_Vec[i].strText.c_str());
			TiXmlText textFirstLimit(to_String(OBJ_Vec[i].intSerialFirstLimit).c_str());
			TiXmlText textSecondLimit(to_String(OBJ_Vec[i].intSerialSecondLimit).c_str());
			TiXmlText textStartValue(to_String(OBJ_Vec[i].intSerialStartValue).c_str());
			TiXmlText textStep(to_String(OBJ_Vec[i].intSerialStep).c_str());
			TiXmlText textRepeat(to_String(OBJ_Vec[i].intSerialRepeat).c_str());
			TiXmlText textDigits(to_String(OBJ_Vec[i].intSerialDigits).c_str());
			TiXmlText textFormat(to_String(OBJ_Vec[i].bytSerialFormat).c_str());
			TiXmlText textCounter(to_String(OBJ_Vec[i].intSerialCounter).c_str());


			itemsetFONT.InsertEndChild(textSetFont);
			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemFirstLimit.InsertEndChild(textFirstLimit);
			itemSecondLimit.InsertEndChild(textSecondLimit);
			itemStartValue.InsertEndChild(textStartValue);
			itemStep.InsertEndChild(textStep);
			itemRepeat.InsertEndChild(textRepeat);
			itemDigits.InsertEndChild(textDigits);
			itemFormat.InsertEndChild(textFormat);
			itemCounter.InsertEndChild(textCounter);


			itemObj.InsertEndChild( itemsetFONT );
			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemFirstLimit );
			itemObj.InsertEndChild( itemSecondLimit );
			itemObj.InsertEndChild( itemStartValue );
			itemObj.InsertEndChild( itemStep );
			itemObj.InsertEndChild( itemRepeat );
			itemObj.InsertEndChild( itemDigits );
			itemObj.InsertEndChild( itemFormat );
			itemObj.InsertEndChild( itemCounter );
		} 
		else if(OBJ_Vec[i].strType2=="time")
		{
			TiXmlElement itemsetFONT("setFONT");
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemSetTIME( "setTIME" );
			TiXmlElement itemETimeOffSet( "ETimeOffSet" );
			TiXmlElement itemTimeOffSet( "TimeOffSet" );
			TiXmlElement itemTimeOffSetUint( "TimeOffSetUint" );

			TiXmlText textSetFont(OBJ_Vec[i].strFont.c_str());
			TiXmlText textSetTEXT(OBJ_Vec[i].strText.c_str());
			TiXmlText textSetTIME(OBJ_Vec[i].strTime.c_str());
			TiXmlText textETimeOffSet(to_String(OBJ_Vec[i].booETimeOffSet).c_str());
			TiXmlText textTimeOffSet(to_String(OBJ_Vec[i].intTimeOffSet).c_str());
			TiXmlText textTimeOffSetUint(to_String(OBJ_Vec[i].strTimeOffSet).c_str());

			itemsetFONT.InsertEndChild(textSetFont);
			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemSetTIME.InsertEndChild(textSetTIME);
			itemETimeOffSet.InsertEndChild(textETimeOffSet);
			itemTimeOffSet.InsertEndChild(textTimeOffSet);
			itemTimeOffSetUint.InsertEndChild(textTimeOffSetUint);

			itemObj.InsertEndChild( itemsetFONT );
			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemSetTIME );
			itemObj.InsertEndChild( itemETimeOffSet );
			itemObj.InsertEndChild( itemTimeOffSet );
			itemObj.InsertEndChild( itemTimeOffSetUint );
		}
		else if (OBJ_Vec[i].strType2=="logo")
		{
			TiXmlElement itemSetTEXT( "setTEXT" );

			TiXmlText textSetTEXT(OBJ_Vec[i].strText.c_str());

			itemSetTEXT.InsertEndChild(textSetTEXT);

			itemObj.InsertEndChild( itemSetTEXT );
		}
		else if (OBJ_Vec[i].strType2=="2Dcode")
		{
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemBarcodeType( "BarcodeType" );
			TiXmlElement itemBarType( "BarType" );
			TiXmlElement itemBarcodeContent( "BarcodeContent" );
			TiXmlElement itemBarWhite( "BarWhite" );

			TiXmlText textSetTEXT(OBJ_Vec[i].strText.c_str());
			TiXmlText textBarcodeType(to_String(OBJ_Vec[i].intBarcodeType).c_str());
			TiXmlText textBarType(to_String(OBJ_Vec[i].intBarType).c_str());
			TiXmlText textBarcodeContent(OBJ_Vec[i].strCodeContent.c_str());
			TiXmlText textBarWhite(to_String(OBJ_Vec[i].intBarWhite).c_str());

			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemBarcodeType.InsertEndChild(textBarcodeType);
			itemBarType.InsertEndChild(textBarType);
			itemBarcodeContent.InsertEndChild(textBarcodeContent);
			itemBarWhite.InsertEndChild(textBarWhite);

			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemBarcodeType );
			itemObj.InsertEndChild( itemBarType );
			itemObj.InsertEndChild( itemBarcodeContent );
			itemObj.InsertEndChild( itemBarWhite );
		}
		else if (OBJ_Vec[i].strType2=="qrcode")
		{
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemVersion( "qrcodeVersion" );
			//TiXmlElement itemECCLevel( "qrcodeECCLevel" );
			//TiXmlElement itemQuietZone( "qrcodeQuietZone" );

			TiXmlText textSetTEXT(OBJ_Vec[i].strText.c_str());
			TiXmlText textVersion(to_String(OBJ_Vec[i].intQRVersion).c_str());
			//TiXmlText textECCLevel(to_String(OBJ_Vec[i].intQRErrLevel).c_str());
			//TiXmlText textQuietZone(to_String(OBJ_Vec[i].intqrcodeQuietZone).c_str());

			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemVersion.InsertEndChild(textVersion);
			//itemECCLevel.InsertEndChild(textECCLevel);
			//itemQuietZone.InsertEndChild(textQuietZone);

			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemVersion );
			//itemObj.InsertEndChild( itemECCLevel );
			//itemObj.InsertEndChild( itemQuietZone );
		}
		else if (OBJ_Vec[i].strType2=="datamatrix")
		{
			TiXmlElement itemSetTEXT( "setTEXT" );
			TiXmlElement itemVersion( "DMsize" );
			TiXmlElement itemDMContent("DMContent");
			TiXmlElement itemDMrow( "DMrow" );

			TiXmlText textSetTEXT(OBJ_Vec[i].strText.c_str());
			TiXmlText textVersion(to_String(OBJ_Vec[i].intDMsize).c_str());
			TiXmlText textDMContent(OBJ_Vec[i].strDMContent.c_str());
			TiXmlText textDMrow(to_String(OBJ_Vec[i].intDMrow).c_str());

			itemSetTEXT.InsertEndChild(textSetTEXT);
			itemVersion.InsertEndChild(textVersion);
			itemDMContent.InsertEndChild(textDMContent);
			itemDMrow.InsertEndChild(textDMrow);

			itemObj.InsertEndChild( itemSetTEXT );
			itemObj.InsertEndChild( itemVersion );
			itemObj.InsertEndChild( itemDMContent);
			itemObj.InsertEndChild( itemDMrow );
		}
		itemMes.InsertEndChild( itemObj );
	}	 

	doc.InsertEndChild(itemMes);

	doc.SaveFile(strFileName);

}

void ClassMessage::ReadBmp(char* strFileName)
{
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	QImage pImage;
	pImage = pLoad.toImage();

	OBJ_Control bmpObj;
	bmpObj.intLineStart=0;
	bmpObj.intRowStart=0;
	bmpObj.strType1="text";
	bmpObj.strType2="logo";
	bmpObj.strText = strFileName;
	bmpObj.intLineSize=pImage.width();
	bmpObj.intRowSize=pImage.height();
	bmpObj.intSW=1;
	bmpObj.intSS=0;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
			if(average < 200)
				bmpObj.boDotBmp[bmpObj.intLineSize-x-1][y] = true;
			else
				bmpObj.boDotBmp[bmpObj.intLineSize-x-1][y] = false;
		}  
	}  
	bmpObj.booFocus = true;
	this->OBJ_Vec.push_back(bmpObj); 
}

void ClassMessage::ReadObjectsFromXml(char* strFileName)
{
	memset(CounterEditMes,false,sizeof(bool)*4);
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

	int count = 0;
	//itemElement = itemElement->NextSiblingElement();
	for( node = todoElement->FirstChildElement();node;node = node->NextSibling() )
	//for( node = todoElement->FirstChildElement();todoElement;node = node->NextSibling() )
	{
		const char* str ;
		str = node->ValueTStr().c_str();
		count++;
		if(strcmp(str,"PRO") == 0)
		{
			//读入信息
			TiXmlNode* nodeTmp = 0;
			for( nodeTmp = node->IterateChildren(0);nodeTmp;nodeTmp = node->IterateChildren( nodeTmp ) )
			{
				const char* strItem = nodeTmp->ValueTStr().c_str();
				if(strcmp(strItem,"Matrix") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					//sprintf_s(obj.m_texts,"%s",strText); 
					strMatrix.assign(strText);
				}
				else if(strcmp(strItem,"Pixel") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					//sprintf_s(obj.m_texts,"%s",strText); 
					Pixel=atoi(strText)-1;
				}
				else if(strcmp(strItem,"Reverse") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					//sprintf_s(obj.m_texts,"%s",strText); 
					Reverse.assign(strText);
				}
				else if(strcmp(strItem,"Inverse") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					//sprintf_s(obj.m_texts,"%s",strText); 
					Inverse.assign(strText);
				}
			}
		}
		else if(strcmp(str,"OBJ") == 0)
		{
			//读入属性信息
			OBJ_Control obj;
			obj.booFocus=false;
			TiXmlNode* nodeTmp = 0;
			for( nodeTmp = node->IterateChildren(0);nodeTmp;nodeTmp = node->IterateChildren( nodeTmp ) )
			{
				const char* strItem = nodeTmp->ValueTStr().c_str();
				if(strcmp(strItem,"TYPE1") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.strType1.assign(strText);
				}
				else if(strcmp(strItem,"TYPE2") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.strType2.assign(strText);
				}
				else if(strcmp(strItem,"LineStart") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intLineStart=atoi(strText);
				}
				else if(strcmp(strItem,"RowStart") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intRowStart=atoi(strText);
				}
				else if(strcmp(strItem,"LineSize") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intLineSize=atoi(strText);
				}
				else if(strcmp(strItem,"RowSize") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intRowSize=atoi(strText);
				}
				else if(strcmp(strItem,"SW") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intSW=atoi(strText);
				}
				else if(strcmp(strItem,"SS") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.intSS=atoi(strText);
				}
				else if(strcmp(strItem,"NEG") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.booNEG=atoi(strText);
				}
				else if(strcmp(strItem,"BWDx") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.booBWDx=atoi(strText);
				}
				else if(strcmp(strItem,"BWDy") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.booBWDy=atoi(strText);
				}
				else if(strcmp(strItem,"setFONT") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					obj.strFont.assign(strText);
				}


				if (obj.strType1=="text"&&obj.strType2=="text")
				{
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}
				}

				else if (obj.strType1=="text"&&obj.strType2=="serial")
				{
					if(strcmp(strItem,"FirstLimit") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intSerialFirstLimit=atoi(strText);
					}
					else if(strcmp(strItem,"SecondLimit") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intSerialSecondLimit=atoi(strText);
					}
					else if(strcmp(strItem,"StartValue") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intSerialStartValue=atoi(strText);
					}
					else if(strcmp(strItem,"Step") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intSerialStep=atoi(strText);
					}
					else if(strcmp(strItem,"Repeat") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intSerialRepeat=atoi(strText);
					}
					else if(strcmp(strItem,"Digits") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intSerialDigits=atoi(strText);
					}
					else if(strcmp(strItem,"Format") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.bytSerialFormat=atoi(strText);
					}
					else if(strcmp(strItem,"Counter") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intSerialCounter=atoi(strText);
						CounterEditMes[obj.intSerialCounter]=true;
					}
					else if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);

					}						
				}

				else if (obj.strType1=="text"&&obj.strType2=="time")/////这个以后再写
				{
					if(strcmp(strItem,"setTIME") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strTime.assign(strText);
					}
					else if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}	
				}

				else if (obj.strType1=="text"&&obj.strType2=="logo")
				{
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
						obj.ReadBmp(const_cast<char*>(obj.strText.c_str()));
					}	
				}

				else if (obj.strType1=="text"&&obj.strType2=="2Dcode")
				{
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}
					if (strcmp(strItem,"BarcodeType") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intBarcodeType = atoi(strText);
					}
					if (strcmp(strItem,"BarType") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.intBarType = atoi(strText);
					}
					//if(strcmp(strItem, "BarWhite" ) == 0)
					//{
					//	//读入信息
					//	const char* strText; 
					//	TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					//	strText = nodeText->ValueTStr().c_str();
					//	//obj.strDMContent.assign(strText);
					//	obj.intBarWhite = atoi(strText);
					//}
					if(strcmp(strItem,"BarcodeContent") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strCodeContent.assign(strText);
						obj.Create2Dcode();
					}
				}
				
				else if (obj.strType1=="text"&&obj.strType2=="qrcode")
				{
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}	
					if(strcmp(strItem,"qrcodeVersion") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strqrcodeVersion.assign(strText);
						obj.intQRVersion = atoi(strText);
					//}
					//if(strcmp(strItem,"qrcodeECCLevel") == 0)
					//{
					//	//读入信息
					//	const char* strText; 
					//	TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					//	strText = nodeText->ValueTStr().c_str();
					//	obj.strqrcodeECCLevel.assign(strText);
					//}
					//if(strcmp(strItem,"qrcodeQuietZone") == 0)
					//{
					//	//读入信息
					//	const char* strText; 
					//	TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					//	strText = nodeText->ValueTStr().c_str();
					//	obj.intqrcodeQuietZone = atoi(strText);

						//读入完所有的信息后要重新生成二位码的点阵信息,因为lab中不包含这些信息，logo及其他类似
						obj.CreateQrcode();
					}
				}
				else if (obj.strType1=="text"&&obj.strType2=="datamatrix")
				{
					if(strcmp(strItem,"setTEXT") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strText.assign(strText);
					}	
					if(strcmp(strItem,"DMsize") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						//obj.strDMContent.assign(strText);
						obj.intDMsize = atoi(strText);
					}
					if(strcmp(strItem,"DMrow") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						//obj.strDMContent.assign(strText);
						obj.intDMrow = atoi(strText);
					}
					if(strcmp(strItem,"DMContent") == 0)
					{
						//读入信息
						const char* strText; 
						TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
						strText = nodeText->ValueTStr().c_str();
						obj.strDMContent.assign(strText);
					
						//读入完所有的信息后要重新生成二位码的点阵信息,因为lab中不包含这些信息，logo及其他类似
						obj.CreateDMcode();
					}
				}
			}
			obj.booFocus = false;
			OBJ_Vec.push_back(obj);
		}
	}

	string strPathName=strFileName;
	int lastN=strPathName.find_last_of('\\');
	labName = strPathName.substr(lastN + 1);
	labPath=strPathName.substr(0,lastN);

}

void ClassMessage::getdot(string tempfont, bool tempBWDy, bool tempBWDx , bool tempNEG, string tempsetTEXT ,
	int tempRowSize, int tempLineSize, int tempLineStart , int tempRowStart , int tempSS , int tempSW )
{
	//memset(boDotMes,false,sizeof(boDotMes));
	map<string,int> gfntMap;
	gfntMap.clear();
	gfntMap.insert(make_pair("5x5",0));
	gfntMap.insert(make_pair("7x5",1));
	gfntMap.insert(make_pair("12x12",2));
	gfntMap.insert(make_pair("16x12",3));
	int theDog;
	int bytTextUni,lonTextUniSetOff;
	string binLineTemp;
	char Dot;///////////////////////////////////////////////////小心，这可能是个坑。。
	int bx,by;
	ClassMessage objClassMessage;
	//map<string,int>::iterator iterTemp=fntMap.begin();
	//iterTemp=fntMap.find(strFont);
	//int caseN=iterTemp->second;
	switch(gfntMap[tempfont])
	{
		case 0://5x5.fnt
			theDog=0;//标记位
			if (tempBWDy)
			{
			} 
			else
			{
				for (int i=0;i<tempsetTEXT.length();i++)
				{
					wchar_t strTempText=tempsetTEXT[i];
					bytTextUni=(int)strTempText;
					lonTextUniSetOff=bytTextUni*7+64;
					bool objRead=objClassMessage.readBin("Font\\5x5.fnt",lonTextUniSetOff,objbytTex5x5Line,7);
					if (!objRead)
					{
						for (int r=0;r<7;r++)
						{
							if (r==6)
							{
								objbytTex5x5Line[r]=6;
							} 
							else
							{
								objbytTex5x5Line[r]=0;
							}

						}
					}
					switch(objbytTex5x5Line[6])
					{
					case 6:
						for (int k=0;k<6;k++)
						{
							binLineTemp="0000000"+objClassMessage.DEC_to_BIN(objbytTex5x5Line[k]);
							binLineTemp=binLineTemp.substr(binLineTemp.length()-5,5);
							for (int p =0;p<5;p++)
							{
								Dot=binLineTemp[p];
								bx=theDog+tempRowStart+k*tempSW;

								if (tempBWDx)
								{
									by=tempLineStart+p;
								} 
								else
								{
									by=5-p+tempLineStart-1;
								}
								switch(Dot)
								{
								case '0':
									if(tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;
										}
									}
									break;
								case '1':
									if(!tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;
										}
									}
									break;
								default:
									if(!tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;
										}
									}
								}	
							}
						}//画列结束；

						if(intSS>0&&tempNEG)
						{
							for (int m=0;m<tempSS;m++)
							{
								for(int p=0;p<5;p++)
								{
									bx=theDog+tempRowStart+6*tempSW+m;
									if (tempBWDx)
									{
										by=5-p+tempLineStart-1;
									} 
									else
									{
										by=tempLineStart+p;
									}
										boDotMes[by][bx]=true;
								}
							}
						}
						theDog=theDog+6*tempSW+tempSS;
						break;
					case 5:
						break;
					case 4:
						break;
					case 3:
						break;
						//default:

					}
				}
			}
			break;
		case 1:
			theDog=0;//标记位
			if (tempBWDy)
			{
			} 
			else
			{
				for (int i=0;i<tempsetTEXT.length();i++)
				{
					wchar_t strTempText=tempsetTEXT[i];
					bytTextUni=(int)strTempText;
					lonTextUniSetOff=bytTextUni*8+64;

					bool objRead=objClassMessage.readBin("Font\\7x5.fnt",lonTextUniSetOff,objbytTex7x5Line,8);
					if (!objRead)
					{
						for (int r=0;r<8;r++)
						{
							if (r==7)
							{
								objbytTex7x5Line[r]=6;
							} 
							else
							{
								objbytTex7x5Line[r]=0;
							}

						}
					}
					switch(objbytTex7x5Line[7])
					{
					case 7:
						break;
					case 6:
						for (int k=0;k<6;k++)
						{
							binLineTemp="0000000"+objClassMessage.DEC_to_BIN(objbytTex7x5Line[k]);
							binLineTemp=binLineTemp.substr(binLineTemp.length()-7,7);
							for (int p =0;p<7;p++)
							{
								Dot=binLineTemp[p];
								bx=(theDog+tempRowStart)+k*tempSW;
									
								if (tempBWDx)
								{
									
									by=(tempLineStart+p);
								} 
								else
								{
										
									by=(7-p+tempLineStart-1);

								}
								switch(Dot)
								{
								case '0':
									if(tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;
										}
									}
									break;
								case '1':
									if(!tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;
										}
									}
									break;
								default:
									if(!tempNEG)
									{
										for (int s=0;s<tempSW;s++)
										{
											boDotMes[by][bx+s]=true;

										}
									}
								}	
							}
						}//画列结束；

						if(intSS>0&&tempNEG)
						{
							for (int m=0;m<tempSS;m++)
							{
								for(int p=0;p<7;p++)
								{
									bx=(theDog+tempRowStart)+6*tempSW+m;
									
									if (tempBWDx)
									{
											
										by=7-p+tempLineStart-1;
									} 
									else
									{
											
										by=tempLineStart+p;
									}
									boDotMes[by][bx]=true;
								}
							}
						}
						theDog=theDog+6*tempSW+tempSS;
						break;
					case 5:
						break;
					case 4:
						break;
					case 3:
						break;
						//default:

					}
				}
			}
			break;
	}
}

vector<BYTE> ClassMessage::DotToByte(int tempintDotRowStart, int tempintDotRowEnd)
{
	vector<BYTE> bytTempVec;
	if (boReverse)
	{
	} 
	else
	{
		if (boInverse)
		{
		} 
		else
		{
			switch(Matrix)
			{
				case 9:
					if (Pixel<8)
					{
						bytRowByteMul=1;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<Pixel;j++)
							{
								bytTempVec[i]=bytTempVec[i]+getByteFromDot(boDotMes[j][i],j);
							}
						}
					}
					else if(Pixel>7)
					{
						bytRowByteMul=2;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[2*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<Pixel;j++)
							{
								bytTempVec[2*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
						}
					}
					break;
				case 12:
					if (Pixel<8)
					{
						bytRowByteMul=1;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<Pixel;j++)
							{
								bytTempVec[i]=bytTempVec[i]+getByteFromDot(boDotMes[j][i],j);
							}
						}
					}
					else if(Pixel>7)
					{
						bytRowByteMul=2;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[2*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<Pixel;j++)
							{
								bytTempVec[2*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
						}
					}
					break;
				case 14:
					if (Pixel<8)
					{
						bytRowByteMul=2;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							bytTempVec[2*i]=getByteFromDot(boDotMes[0][i],0)+getByteFromDot(boDotMes[8][i],1)+getByteFromDot(boDotMes[1][i],2)+getByteFromDot(boDotMes[9][i],3)
								+getByteFromDot(boDotMes[2][i],4)+getByteFromDot(boDotMes[10][i],5)+getByteFromDot(boDotMes[3][i],6)+getByteFromDot(boDotMes[11][i],7);

							bytTempVec.push_back(0);
							bytTempVec[2*i+1]=getByteFromDot(boDotMes[4][i],0)+getByteFromDot(boDotMes[12][i],1)+getByteFromDot(boDotMes[5][i],2)+getByteFromDot(boDotMes[13][i],3)
								+getByteFromDot(boDotMes[6][i],4)+getByteFromDot(boDotMes[14][i],5);
						}
					}
					break;
				case 19:
					if (Pixel<8)
					{
						bytRowByteMul=1;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<Pixel;j++)
							{
								bytTempVec[i]=bytTempVec[i]+getByteFromDot(boDotMes[j][i],j);
							}
						}
					}
					else if(Pixel>7&&Pixel<16)
					{
						bytRowByteMul=2;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[2*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<Pixel;j++)
							{
								bytTempVec[2*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
						}
					}
					else if(Pixel>15)
					{
						bytRowByteMul=3;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[3*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<16;j++)
							{
								bytTempVec[3*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
							bytTempVec.push_back(0);
							for (int j=16;j<Pixel;j++)
							{
								bytTempVec[3*i+2]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-16);
							}
						}
					}
					break;
				case 25:
					if (Pixel<8)
					{
						bytRowByteMul=1;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<Pixel;j++)
							{
								bytTempVec[i]=bytTempVec[i]+getByteFromDot(boDotMes[j][i],j);
							}
						}
					}
					else if(Pixel>7&&Pixel<16)
					{
						bytRowByteMul=2;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[2*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<Pixel;j++)
							{
								bytTempVec[2*i+1]=bytTempVec[2*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
						}
					}
					else if(Pixel>15&&Pixel<24)
					{
						bytRowByteMul=3;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[3*i]=bytTempVec[3*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<16;j++)
							{
								bytTempVec[3*i+1]=bytTempVec[3*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
							bytTempVec.push_back(0);
							for (int j=16;j<Pixel;j++)
							{
								bytTempVec[3*i+2]=bytTempVec[3*i+2]+getByteFromDot(boDotMes[j][i],j-16);
							}
						}
					}
					else if(Pixel>24)
					{
						bytRowByteMul=4;
						for (int i=tempintDotRowStart;i<tempintDotRowEnd;i++)
						{
							bytTempVec.push_back(0);
							for (int j=0;j<8;j++)
							{
								bytTempVec[4*i]=bytTempVec[2*i]+getByteFromDot(boDotMes[j][i],j);
							}
							bytTempVec.push_back(0);
							for (int j=8;j<16;j++)
							{
								bytTempVec[4*i+1]=bytTempVec[4*i+1]+getByteFromDot(boDotMes[j][i],j-8);
							}
							bytTempVec.push_back(0);
							for (int j=16;j<Pixel;j++)
							{
								bytTempVec[4*i+2]=bytTempVec[4*i+2]+getByteFromDot(boDotMes[j][i],j-16);
							}
							bytTempVec.push_back(0);
							for (int j=24;j<Pixel;j++)
							{
								bytTempVec[4*i+3]=bytTempVec[4*i+3]+getByteFromDot(boDotMes[j][i],j-24);
							}
						}
					}
					break;
			}
		}
	}
	return bytTempVec;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
OBJ_Control::OBJ_Control(void)
{
	this->strDuan="OBJ";
	this->intSW=1;
	this->intSS=0;
	this->intX=0;
	this->intY=0;
	this->booNEG=false;
	this->booBWDx=false;
	this->booBWDy=false;
	this->strFont="7x5";
	this->strText="Text";
	this->booETimeOffSet=0;
	this->intTimeOffSet=1;
	this->intSerialFirstLimit=1;
	this->intSerialSecondLimit=999999999;
    this->intSerialStartValue=1;
	this->intSerialStep=1;
	this->intSerialRepeat=1;
	this->intSerialDigits=9;
	this->intSerialCounter=0;
	this->bytSerialFormat=0;
	this->intLineSize=0;
	this->intRowSize=0;
	this->intLineStart=0;
    this->intRowStart=0;
	this->intqrcodeQuietZone=0;
	this->booFocus=true;

}

OBJ_Control::~OBJ_Control(void){}

void OBJ_Control::DrawFrame(CDC * pDC)
{
	QPen cPen;//QPainter painter();
	if (this->booFocus)
	{
		cPen.setStyle(Qt::SolidLine);
		cPen.setWidth(3);
		cPen.setColor(Qt::green);
		cPen.setCapStyle(Qt::SquareCap);
		cPen.setJoinStyle(Qt::BevelJoin);
	}
	else
	{
		cPen.setStyle(Qt::SolidLine);
		cPen.setWidth(3);
		cPen.setColor(Qt::blue);
		cPen.setCapStyle(Qt::SquareCap);
		cPen.setJoinStyle(Qt::BevelJoin);
	}
	pDC->setPen(cPen);
		
	//下
	pDC->drawLine(intRowStart*5,241-intLineStart*5-1,(intRowStart+intRowSize)*5,241-intLineStart*5-1);
	//上
	pDC->drawLine(intRowStart*5,241-(intLineSize+intLineStart)*5-1,(intRowStart+intRowSize)*5,241-(intLineSize+intLineStart)*5-1);
	//左
	pDC->drawLine(intRowStart*5,241-intLineStart*5-1,intRowStart*5,241-(intLineSize+intLineStart)*5-1);
	//右
	pDC->drawLine((intRowStart+intRowSize)*5,241-intLineStart*5-1,(intRowStart+intRowSize)*5,241-(intLineSize+intLineStart)*5-1);
}

wstring stringToWstring(const string& str)
{
	setlocale(LC_ALL, "chs"); 

	const char* _Source = str.c_str();
	size_t _Dsize = str.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest,_Source,_Dsize);
	wstring result = _Dest;
	delete []_Dest;

	setlocale(LC_ALL, "C");

	return result;
}

void OBJ_Control::DrawDot(CDC* pDC)
{
 	CBrush cbrushB(QColor(0,0,0));//黑笔
	cbrushB.setStyle(Qt::SolidPattern);
	CBrush cbrushW(QColor(255,255,255));//白笔
	cbrushW.setStyle(Qt::NoBrush);
	//cbrushW.setStyle(Qt::SolidPattern);
	CPen cPenInvisible(Qt::NoPen);
		 
	if (strType2=="logo"||strType2=="qrcode"||strType2 == "2Dcode"||strType2=="datamatrix")
	{
		int bmpWidth,bmpHeight,bmpXStart,bmpYStart;
		bmpWidth=intRowSize;
		bmpHeight=intLineSize;
		//bmpXStart = intRowStart;
		//bmpYStart = intLineStart;
		if (booBWDy)
		{
			for (int i=0;i<bmpWidth;i++)
			{
				for(int j=0;j<bmpHeight;j++)
				{
					if (booBWDx)
					{
						if (booNEG)
						{	
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushW);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,241-(bmpHeight-j)*5-1,5,5); //width和height先写死
									//CRect rect((bmpWidth-i-1)*5,161-(bmpHeight-j)*5-1,(bmpWidth-i)*5,241-(bmpHeight-j-1)*5-1);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushB);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,241-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						} 
						else
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushB);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,241-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushW);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,241-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						}
					} 
					else
					{
						if (booNEG)
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushW);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,241-(j+1)*5-1,5,5);
									//CRect rect((bmpWidth-i-1)*5,161-(j+1)*5-1,(bmpWidth-i)*5,241-j*5-1);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushB);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,241-(j+1)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						} 
						else
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushB);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,241-(j+1)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushW);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((bmpWidth-i-1)*5,241-(j+1)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						}
					}
				}
			}
		} 
		else
		{
			for (int i=0;i<bmpWidth;i++)
			{
				for(int j=0;j<bmpHeight;j++)
				{
					if (booBWDx)
					{
						if (booNEG)
						{

							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushW);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,241-(bmpHeight-j)*5-1,5,5);
									//CRect rect(i*5,161-(bmpHeight-j)*5-1,(i+1)*5,161-(bmpHeight-j-1)*5-1);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushB);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,241-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						} 
						else
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushB);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,241-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushW);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,241-(bmpHeight-j)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						}
					} 
					else
					{
						if (booNEG)
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushW);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,241-(j+1)*5-1,5,5);
								    //CRect rect(i*5,161-(j+1)*5-1,(i+1)*5,161-j*5-1);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushB);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,241-(j+1)*5-1,5,5);
									pDC->Ellipse(rect);
								}
							}
						} 
						else
						{
							if (boDotBmp[i][j])
							{
								pDC->setBrush(cbrushB);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect((intRowStart+i)*5,241-(intLineStart+j+1)*5-1,5,5);
									//CRect rect((intRowStart+i)*5,161-(intLineStart+j+1)*5-1,(intRowStart+i+1)*5,161-(intLineStart+j)*5-1);
									pDC->Ellipse(rect);
								}
							} 
							else
							{
								pDC->setBrush(cbrushW);
								pDC->setPen(cPenInvisible);
								for(int sw=0;sw<intSW;sw++)
								{
									CRect rect(i*5,241-(j+1)*5-1,5,5);
									//CRect rect(i*5,161-(j+1)*5-1,(i+1)*5,161-j*5-1);
									pDC->Ellipse(rect);
								}
							}
						}
					}
				}
			}
		}
	}

	//如果是文本
	else
	{
		fntMap.clear();
		fntMap.insert(make_pair("5x5",0));
		fntMap.insert(make_pair("7x5",1));
		fntMap.insert(make_pair("12x12",2));
		fntMap.insert(make_pair("16x12",3));
		int theDog;
		int bytTextUni,lonTextUniSetOff;
		string binLineTemp;
		char Dot;///////////////////////////////////////////////////小心，这可能是个坑。。
		int x1,y1,x2,y2;
		ClassMessage objClassMessage;

		//map<string,int>::iterator iterTemp=fntMap.begin();
		//iterTemp=fntMap.find(strFont);
		//int caseN=iterTemp->second;
		//this->strFont = OBJ_Vec[i]

		switch(fntMap[strFont])
		{
		case 0://5x5.fnt
			theDog=0;//标记位
			if (booBWDy)
			{
				wstring strWText = stringToWstring(strText);
				for (int i=0;i<strWText.length();i++)
				{
					wchar_t strTempText = strWText[strWText.length()-i-1];
					bytTextUni = (int)strTempText;
					lonTextUniSetOff = bytTextUni*7+64;
					bool objRead = objClassMessage.readBin("Font\\5x5.fnt",lonTextUniSetOff,objbytTex5x5Line,7);
					if (!objRead)
					{
						for (int r=0;r<7;r++)
						{
							if (r==6)
							{
								objbytTex5x5Line[r]=6;
							} 
							else
							{
								objbytTex5x5Line[r]=0;
							}

						}
					}
					if(intSS>0 && booNEG)
					{
						for (int m=0;m<intSS;m++)
						{
							for(int p=0;p<5;p++)
							{
								x1=5*(theDog+intRowStart)+5*m;
								x2=5*(theDog+intRowStart+1)+5*m;
								if (booBWDx)
								{
									y1=241-5*(5-p+intLineStart)-1;
									y2=241-5*(5-p+intLineStart-1)-1;
								} 
								else
								{
									y1=241-5*(intLineStart+p+1)-1;
									y2=241-5*(intLineStart+p)-1;
								}
								pDC->setBrush(cbrushB);
								CRect rect(x1+1,y1+1,x2-x1-1,y2-y1-1);
								pDC->Ellipse(rect);
							}
						}
					}

					for (int k=0;k<objbytTex5x5Line[6];k++)
					{
						binLineTemp="0000000"+objClassMessage.DEC_to_BIN((byte)objbytTex5x5Line[objbytTex5x5Line[6]-1-k]);
						binLineTemp=binLineTemp.substr(binLineTemp.length()-5,5);
						for (int p =0;p<5;p++)
						{
							Dot=binLineTemp[p];
							x1=5*(theDog+intRowStart)+5*k*intSW+5*intSS;
							x2=5*(theDog+intRowStart+1)+5*k*intSW+5*intSS;
							if (booBWDx)
							{
								y1=241-5*(intLineStart+p+1)-1;
								y2=241-5*(intLineStart+p)-1;
							} 
							else
							{
								y1=241-5*(5-p+intLineStart)-1;
								y2=241-5*(5-p+intLineStart-1)-1;

							}
							switch(Dot)
							{
							case '0':
								if(booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							case '1':
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							default:
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
							}	
						}
					}//画列结束
					theDog=theDog+objbytTex5x5Line[6]*intSW+intSS;
				}
			} 
			else
			{
				wstring strWText=stringToWstring(strText);
				for (int i=0;i<strWText.length();i++)
				{
					wchar_t strTempText=strWText[i];
					bytTextUni=(int)strTempText;
					lonTextUniSetOff=bytTextUni*7+64;
					bool objRead=objClassMessage.readBin("Font\\5x5.fnt",lonTextUniSetOff,objbytTex5x5Line,7);
					if (!objRead)
					{
						for (int r=0;r<7;r++)
						{
							if (r==6)
							{
								objbytTex5x5Line[r]=6;
							} 
							else
							{
								objbytTex5x5Line[r]=0;
							}

						}
					}
					for (int k=0;k<objbytTex5x5Line[6];k++)
					{
						binLineTemp="0000000"+objClassMessage.DEC_to_BIN((byte)objbytTex5x5Line[k]);
						binLineTemp=binLineTemp.substr(binLineTemp.length()-5,5);
						for (int p =0;p<5;p++)
						{
							Dot=binLineTemp[p];
							x1=5*(theDog+intRowStart)+5*k*intSW;
							x2=5*(theDog+intRowStart+1)+5*k*intSW;
							if (booBWDx)
							{
								y1=241-5*(intLineStart+p+1)-1;
								y2=241-5*(intLineStart+p)-1;
							} 
							else
							{
								y1=241-5*(5-p+intLineStart)-1;
								y2=241-5*(5-p+intLineStart-1)-1;

							}
							switch(Dot)
							{
							case '0':
								if(booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							case '1':
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							default:
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
							}	
						}
					}//画列结束；

					if(intSS>0&&booNEG)
					{
						for (int m=0;m<intSS;m++)
						{
							for(int p=0;p<5;p++)
							{
								x1=5*(theDog+intRowStart)+5*objbytTex5x5Line[6]*intSW+5*m;
								x2=5*(theDog+intRowStart+1)+5*objbytTex5x5Line[6]*intSW+5*m;
								if (booBWDx)
								{
									y1=241-5*(5-p+intLineStart)-1;
									y2=241-5*(5-p+intLineStart-1)-1;
								} 
								else
								{
									y1=241-5*(intLineStart+p+1)-1;
									y2=241-5*(intLineStart+p)-1;
								}
								pDC->setBrush(cbrushB);
								CRect rect(x1+1,y1+1,x2-x1-1,y2-y1-1);
								pDC->Ellipse(rect);
							}
						}
					}
					theDog=theDog+objbytTex5x5Line[6]*intSW+intSS;
				}
			}
			break;
		case 1://7x5
			theDog=0;//标记位
			if (booBWDy)
			{
				wstring strWText = stringToWstring(strText);
				for (int i=0;i<strWText.length();i++)
				{
					wchar_t strTempText = strWText[strWText.length()-i-1];
					bytTextUni = (int)strTempText;
					lonTextUniSetOff = bytTextUni*8+64;
					
					bool objRead=objClassMessage.readBin("Font\\7x5.fnt",lonTextUniSetOff,objbytTex7x5Line,8);
					if (!objRead)
					{
						for (int r=0;r<8;r++)
						{
							if (r==7)
							{
								objbytTex7x5Line[r]=6;
							} 
							else
							{
								objbytTex7x5Line[r]=0;
							}
						}
					}
					if(intSS>0&&booNEG)
					{
						for (int m=0;m<intSS;m++)
						{
							for(int p=0;p<7;p++)
							{
								x1=5*(theDog+intRowStart)+5*m;
								x2=5*(theDog+intRowStart+1)+5*m;
								if (booBWDx)
								{
									y1=241-5*(7-p+intLineStart)-1;
									y2=241-5*(7-p+intLineStart-1)-1;
								} 
								else
								{
									y1=241-5*(intLineStart+p+1)-1;
									y2=241-5*(intLineStart+p)-1;
								}
								pDC->setBrush(cbrushB);
								CRect rect(x1+1,y1+1,x2-x1-1,y2-y1-1);
								pDC->Ellipse(rect);
							}
						}
					}

					for (int k=0;k<objbytTex7x5Line[7];k++)
					{
						binLineTemp="0000000"+objClassMessage.DEC_to_BIN((byte)objbytTex7x5Line[objbytTex7x5Line[7]-1-k]);
						binLineTemp=binLineTemp.substr(binLineTemp.length()-7,7);
						for (int p =0;p<7;p++)
						{
							Dot=binLineTemp[p];
							x1=5*(theDog+intRowStart)+5*k*intSW+5*intSS;
							x2=5*(theDog+intRowStart+1)+5*k*intSW+5*intSS;
							if (booBWDx)
							{
								y1=241-5*(intLineStart+p+1)-1;
								y2=241-5*(intLineStart+p)-1;
							} 
							else
							{
								y1=241-5*(7-p+intLineStart)-1;
								y2=241-5*(7-p+intLineStart-1)-1;
							}
							switch(Dot)
							{
							case '0':
								if(booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							case '1':
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							default:
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
							}	
						}
					}//画列结束；

					theDog=theDog+objbytTex7x5Line[7]*intSW+intSS;
				}
			} 
			else
			{
				wstring strWText = stringToWstring(strText);
				for (int i=0;i<strWText.length();i++)
				{
					wchar_t strTempText = strWText[i];
					bytTextUni = (int)strTempText;
					lonTextUniSetOff = bytTextUni*8+64;

					bool objRead=objClassMessage.readBin("Font\\7x5.fnt",lonTextUniSetOff,objbytTex7x5Line,8);
					if (!objRead)
					{
						for (int r=0;r<8;r++)
						{
							if (r==7)
							{
								objbytTex7x5Line[r]=6;
							} 
							else
							{
								objbytTex7x5Line[r]=0;
							}

						}
					}
					for (int k=0;k<objbytTex7x5Line[7];k++)
					{
						binLineTemp="0000000"+objClassMessage.DEC_to_BIN((byte)objbytTex7x5Line[k]);
						binLineTemp=binLineTemp.substr(binLineTemp.length()-7,7);
						for (int p =0;p<7;p++)
						{
							Dot=binLineTemp[p];
							x1=5*(theDog+intRowStart)+5*k*intSW;
							x2=5*(theDog+intRowStart+1)+5*k*intSW;
							if (booBWDx)
							{
								y1=241-5*(intLineStart+p+1)-1;
								y2=241-5*(intLineStart+p)-1;
							} 
							else
							{
								y1=241-5*(7-p+intLineStart)-1;
								y2=241-5*(7-p+intLineStart-1)-1;
							}
							switch(Dot)
							{
							case '0':
								if(booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							case '1':
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							default:
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
							}	
						}
					}//画列结束；

					if(intSS>0&&booNEG)
					{
						for (int m=0;m<intSS;m++)
						{
							for(int p=0;p<7;p++)
							{
								x1=5*(theDog+intRowStart)+5*objbytTex7x5Line[7]*intSW+5*m;
								x2=5*(theDog+intRowStart+1)+5*objbytTex7x5Line[7]*intSW+5*m;
								if (booBWDx)
								{
									y1=241-5*(7-p+intLineStart)-1;
									y2=241-5*(7-p+intLineStart-1)-1;
								} 
								else
								{
									y1=241-5*(intLineStart+p+1)-1;
									y2=241-5*(intLineStart+p)-1;
								}
								pDC->setBrush(cbrushB);
								CRect rect(x1+1,y1+1,x2-x1-1,y2-y1-1);
								pDC->Ellipse(rect);
							}
						}
					}
					theDog=theDog+objbytTex7x5Line[7]*intSW+intSS;
				}
			}
			break;

		case 2://12x12

			theDog=0;
			if (booBWDy)
			{
				wstring strWText = stringToWstring(strText);
				for (int i=0;i<strWText.length();i++)
				{
					wchar_t strTempText = strWText[strWText.length()-i-1];
					bytTextUni = (int)strTempText;
					lonTextUniSetOff = bytTextUni*25+64;
					
					bool objRead = objClassMessage.readBin("Font\\12x12.fnt",lonTextUniSetOff,objbytTex12x12Line,25);
					if (!objRead)
					{
						for (int r=0;r<25;r++)
						{
							if (r==24)
							{
								objbytTex12x12Line[r]=12;
							} 
							else
							{
								objbytTex12x12Line[r]=0;
							}

						}
					}

					if(intSS>0&&booNEG)
					{
						for (int m=0;m<intSS;m++)
						{
							for(int p=0;p<12;p++)
							{
								x1=5*(theDog+intRowStart)+5*m;
								x2=5*(theDog+intRowStart+1)+5*m;
								if (booBWDx)
								{
									y1=241-5*(12-p+intLineStart)-1;
									y2=241-5*(12-p+intLineStart-1)-1;
								} 
								else
								{
									y1=241-5*(intLineStart+p+1)-1;
									y2=241-5*(intLineStart+p)-1;
								}
								pDC->setBrush(cbrushB);
								CRect rect(x1+1,y1+1,x2-x1-1,y2-y1-1);
								pDC->Ellipse(rect);
							}
						}
					}

					for (int k=0;k<objbytTex12x12Line[24];k++)
					{
						string binLineTemp1,binLineTemp0;
						binLineTemp1="0000"+objClassMessage.DEC_to_BIN((byte)objbytTex12x12Line[(objbytTex12x12Line[24]*2)-1-k*2]);
						binLineTemp1=binLineTemp1.substr(binLineTemp1.length()-4,4);
						binLineTemp0="00000000"+objClassMessage.DEC_to_BIN((byte)objbytTex12x12Line[(objbytTex12x12Line[24]*2)-1-k*2-1]);
						binLineTemp0=binLineTemp0.substr(binLineTemp0.length()-8,8);
						binLineTemp=binLineTemp1+binLineTemp0;
						//binLineTemp="0000000"+objClassMessage.DEC_to_BIN(objbytTex12x12Line[5-k]);
						//binLineTemp=binLineTemp.substr(binLineTemp.length()-5,5);
						for (int p =0;p<12;p++)
						{
							Dot=binLineTemp[p];
							x1=5*(theDog+intRowStart)+5*k*intSW+5*intSS;
							x2=5*(theDog+intRowStart+1)+5*k*intSW+5*intSS;
							if (booBWDx)
							{
								y1=241-5*(intLineStart+p+1)-1;
								y2=241-5*(intLineStart+p)-1;
							} 
							else
							{
								y1=241-5*(12-p+intLineStart)-1;
								y2=241-5*(12-p+intLineStart-1)-1;
							}
							switch(Dot)
							{
							case '0':
								if(booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							case '1':
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							default:
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
							}	
						}
					}//画列结束；
					theDog=theDog+objbytTex12x12Line[24]*intSW+intSS;
				}
			} 
			else
			{
				wstring strWText = stringToWstring(strText);
				for (int i=0;i<strWText.length();i++)
				{
					wchar_t strTempText = strWText[i];
					bytTextUni = (int)strTempText;
					lonTextUniSetOff = bytTextUni*25+64;

					bool objRead = objClassMessage.readBin("Font\\12x12.fnt",lonTextUniSetOff,objbytTex12x12Line,25);
					if (!objRead)
					{
						for (int r=0;r<25;r++)
						{
							if (r==24)
							{
								objbytTex12x12Line[r]=12;
							} 
							else
							{
								objbytTex12x12Line[r]=0;
							}

						}
					}

					for (int k=0;k<objbytTex12x12Line[24];k++)
					{
						string binLineTemp1,binLineTemp0;
						binLineTemp1="0000"+objClassMessage.DEC_to_BIN((byte)objbytTex12x12Line[k*2+1]);
						binLineTemp1=binLineTemp1.substr(binLineTemp1.length()-4,4);
						binLineTemp0="00000000"+objClassMessage.DEC_to_BIN((byte)objbytTex12x12Line[k*2]);
						binLineTemp0=binLineTemp0.substr(binLineTemp0.length()-8,8);
						binLineTemp=binLineTemp1+binLineTemp0;
						for (int p =0;p<12;p++)
						{
							Dot=binLineTemp[p];
							x1=5*(theDog+intRowStart)+5*k*intSW;
							x2=5*(theDog+intRowStart+1)+5*k*intSW;
							if (booBWDx)
							{
								y1=241-5*(intLineStart+p+1)-1;
								y2=241-5*(intLineStart+p)-1;
							} 
							else
							{
								y1=241-5*(12-p+intLineStart)-1;
								y2=241-5*(12-p+intLineStart-1)-1;
							}
							switch(Dot)
							{
							case '0':
								if(booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							case '1':
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							default:
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
							}	
						}
					}//画列结束；

					if(intSS>0&&booNEG)
					{
						for (int m=0;m<intSS;m++)
						{
							for(int p=0;p<12;p++)
							{
								x1=5*(theDog+intRowStart)+5*objbytTex12x12Line[24]*intSW+5*m;
								x2=5*(theDog+intRowStart+1)+5*objbytTex12x12Line[24]*intSW+5*m;
								if (booBWDx)
								{
									y1=241-5*(12-p+intLineStart)-1;
									y2=241-5*(12-p+intLineStart-1)-1;
								} 
								else
								{
									y1=241-5*(intLineStart+p+1)-1;
									y2=241-5*(intLineStart+p)-1;
								}
								pDC->setBrush(cbrushB);
								CRect rect(x1+1,y1+1,x2-x1-1,y2-y1-1);
								pDC->Ellipse(rect);
							}
						}
					}
					theDog=theDog+objbytTex12x12Line[24]*intSW+intSS;
				}
			}
			break;
		case 3://16x12
			theDog=0;
			if (booBWDy)
			{
				//strText="中国";
				wstring strWText = stringToWstring(strText);
				for (int i=0;i<strWText.length();i++)
				{
					wchar_t strTempText = strWText[strWText.length()-i-1];
					bytTextUni = (int)strTempText;
					lonTextUniSetOff = bytTextUni*29+64;

					bool objRead = objClassMessage.readBin("Font\\16x12.fnt",lonTextUniSetOff,objbytTex16x12Line,29);
					if (!objRead)
					{
						for (int r=0;r<29;r++)
						{
							if (r==28)
							{
								objbytTex16x12Line[r]=14;
							} 
							else
							{
								objbytTex16x12Line[r]=0;
							}

						}
					}

					if(intSS>0&&booNEG)
					{
						for (int m=0;m<intSS;m++)
						{
							for(int p=0;p<16;p++)
							{
								x1=5*(theDog+intRowStart)+5*m;
								x2=5*(theDog+intRowStart+1)+5*m;
								if (booBWDx)
								{
									y1=241-5*(16-p+intLineStart)-1;
									y2=241-5*(16-p+intLineStart-1)-1;
								} 
								else
								{
									y1=241-5*(intLineStart+p+1)-1;
									y2=241-5*(intLineStart+p)-1;
								}
								pDC->setBrush(cbrushB);
								CRect rect(x1+1,y1+1,x2-x1-1,y2-y1-1);
								pDC->Ellipse(rect);
							}
						}
					}

					for (int k=0;k<objbytTex16x12Line[28];k++)
					{
						string binLineTemp1,binLineTemp0;
						binLineTemp1="00000000"+objClassMessage.DEC_to_BIN((byte)objbytTex16x12Line[(objbytTex16x12Line[28]*2)-1-k*2]);
						binLineTemp1=binLineTemp1.substr(binLineTemp1.length()-8,8);
						binLineTemp0="00000000"+objClassMessage.DEC_to_BIN((byte)objbytTex16x12Line[(objbytTex16x12Line[28]*2)-1-k*2-1]);
						binLineTemp0=binLineTemp0.substr(binLineTemp0.length()-8,8);
						binLineTemp=binLineTemp1+binLineTemp0;
						//binLineTemp="0000000"+objClassMessage.DEC_to_BIN(objbytTex12x12Line[5-k]);
						//binLineTemp=binLineTemp.substr(binLineTemp.length()-5,5);
						for (int p =0;p<16;p++)
						{
							Dot=binLineTemp[p];
							x1=5*(theDog+intRowStart)+5*k*intSW+5*intSS;
							x2=5*(theDog+intRowStart+1)+5*k*intSW+5*intSS;
							if (booBWDx)
							{
								y1=241-5*(intLineStart+p+1)-1;
								y2=241-5*(intLineStart+p)-1;
							} 
							else
							{
								y1=241-5*(16-p+intLineStart)-1;
								y2=241-5*(16-p+intLineStart-1)-1;

							}
							switch(Dot)
							{
							case '0':
								if(booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							case '1':
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							default:
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
							}	
						}
					}//画列结束；

					theDog=theDog+objbytTex16x12Line[28]*intSW+intSS;
				}
			} 
			else
			{
				wstring strWText = stringToWstring(strText);
				for (int i=0;i<strWText.length();i++)
				{
					wchar_t strTempText = strWText[i];
					bytTextUni = (int)strTempText;
					lonTextUniSetOff = bytTextUni*29+64;

					bool objRead = objClassMessage.readBin("Font\\16x12.fnt",lonTextUniSetOff,objbytTex16x12Line,29);
					if (!objRead)
					{
						for (int r=0;r<29;r++)
						{
							if (r==28)
							{
								objbytTex16x12Line[r]=14;
							} 
							else
							{
								objbytTex16x12Line[r]=0;
							}

						}
					}

					for (int k=0;k<objbytTex16x12Line[28];k++)
					{
						string binLineTemp1,binLineTemp0;
						binLineTemp1="00000000"+objClassMessage.DEC_to_BIN((byte)objbytTex16x12Line[k*2+1]);
						binLineTemp1=binLineTemp1.substr(binLineTemp1.length()-8,8);
						binLineTemp0="00000000"+objClassMessage.DEC_to_BIN((byte)objbytTex16x12Line[k*2]);
						binLineTemp0=binLineTemp0.substr(binLineTemp0.length()-8,8);
						binLineTemp=binLineTemp1+binLineTemp0;
						for (int p =0;p<16;p++)
						{
							Dot=binLineTemp[p];
							x1=5*(theDog+intRowStart)+5*k*intSW;
							x2=5*(theDog+intRowStart+1)+5*k*intSW;
							if (booBWDx)
							{
								y1=241-5*(intLineStart+p+1)-1;
								y2=241-5*(intLineStart+p)-1;
							} 
							else
							{
								y1=241-5*(16-p+intLineStart)-1;
								y2=241-5*(16-p+intLineStart-1)-1;

							}
							switch(Dot)
							{
							case '0':
								if(booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							case '1':
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
								break;
							default:
								if(!booNEG)
								{
									for (int s=0;s<intSW;s++)
									{
										pDC->setBrush(cbrushB);
										CRect rect(x1+5*s+1,y1+1,x2-x1-1,y2-y1-1);
										pDC->Ellipse(rect);
									}
								}
							}	
						}
					}//画列结束

					if(intSS>0&&booNEG)
					{
						for (int m=0;m<intSS;m++)
						{
							for(int p=0;p<16;p++)
							{
								x1=5*(theDog+intRowStart)+5*objbytTex16x12Line[28]*intSW+5*m;
								x2=5*(theDog+intRowStart+1)+5*objbytTex16x12Line[28]*intSW+5*m;
								if (booBWDx)
								{
									y1=241-5*(16-p+intLineStart)-1;
									y2=241-5*(16-p+intLineStart-1)-1;
								} 
								else
								{
									y1=241-5*(intLineStart+p+1)-1;
									y2=241-5*(intLineStart+p)-1;
								}
								pDC->setBrush(cbrushB);
								CRect rect(x1+1,y1+1,x2-x1-1,y2-y1-1);
								pDC->Ellipse(rect);
							}
						}
					}
					theDog=theDog+objbytTex16x12Line[28]*intSW+intSS;
				}

			}
			break;
		}
		intRowSize=theDog;
	}

	//pDC->setBrush(cbrushB); //载入笔刷

	//CRect rect(col*nStepPixels,row*nStepPixels,(col+1)*nStepPixels,(row+1)*nStepPixels);
	//pDC->Ellipse(&rect); 

	DrawFrame(pDC);
}
	
void OBJ_Control::ReadBmp(char* strFileName)
{
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	QImage pImage;
	pImage = pLoad.toImage();

	int intLineSize = pImage.width();
	int intRowSize = pImage.height();

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
			if(average < 200)
				boDotBmp[intLineSize-x-1][y] = true;
			else
				boDotBmp[intLineSize-x-1][y] = false;
		}  
	}  
}

void OBJ_Control::CreateQrcode()
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	//int batch_mode;
	//int mirror_mode;
	//char filetype[4];
	int i;
	int v;

	error_number = 0;
	
	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = 58; //临时用一下变量intQRVersion
	my_symbol->scale = 0.5;

//	v=ui->sideLenQRComBox->currentIndex();
	my_symbol->option_2 = intQRVersion;//option_1为容错等级，option_2为版本大小公式为:(V - 1) * 4 + 21；

	//batch_mode = 0;
	//mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strText.c_str(),strText.size(),rotate_angle);
	
	generated = 1;
	strType1="text";
	strType2="qrcode";		
	intLineSize=my_symbol->bitmap_height;
	intRowSize=my_symbol->bitmap_width;

	i = 0;
	int r, g, b;

	for (int row = 0; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				boDotBmp[col][my_symbol->bitmap_height-row-1] = true;//由于坐标系的原因，上下必须颠倒
			}
			else
			{
				boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	booFocus = true;
}

void OBJ_Control::Create2Dcode()
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;
	int longth;
	int derta;
	derta=1;
	longth=0;
	error_number = 0;
	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = intBarcodeType;
	int heightvalue1 = intLineSize;
	if (heightvalue1<28)
	{	
		my_symbol->height =5;	 
	} 
	else
	{
		my_symbol->height=heightvalue1-23;
	}
	/*QString zoomvalue=ui->zoomShowBarCodeLab->text();
	float zoomvalue1=zoomvalue.toFloat();*/
	my_symbol->scale =1;
	batch_mode = 0;
	mirror_mode = 0;
	
	my_symbol->whitespace_width = 9;//改变条形码两边空白区域宽度,空白区域宽度会影响条形码的宽度，只会增加条码左右两侧的空白
	//if (ui->typerimComBox->currentIndex()==0)
	//{
	//	my_symbol->output_options= 1;
	//} 
	//else if(ui->typerimComBox->currentIndex()==1)
	//{
	//	my_symbol->output_options=2;
	//}
	//else
	//{
	//	my_symbol->output_options=4;
	//}
	//有无边框之类的控制;1:无边框，2：上下两条边界线，4：四条边框
	//QString rimwide=ui->rimwideLab->text();
	//int rimwide1=rimwide.toInt();
	//my_symbol->border_width=rimwide1;//改变边框宽度           

	//int show_hrt;            //设置为1 显示文本在条码图片下面 设置为0 则不显示
	//if (ui->showNumCheckBox->isChecked())
	//{
	//	my_symbol->show_hrt=1;
	//} 

	//else  {my_symbol->show_hrt=0;}

	strcpy_s(my_symbol->outfile, "User/logo/output.bmp");
	ZBarcode_Encode(my_symbol, (unsigned char*) strCodeContent.c_str(), 0);
	generated=1;
	int error_num = ZBarcode_Print(my_symbol, 0);

	if (error_num != 0)
	//{
	//	/* some error occurred */
	//	//printf("%s\n", my_symbol->errtxt);
	//}

	ZBarcode_Delete(my_symbol);
		
	char* strFileName = "User/logo/output.bmp";
	QPixmap pLoad;
	pLoad.load(strFileName);
	int nW = pLoad.width();
	int nH = pLoad.height();
	QImage pImage;
	pImage = pLoad.toImage();
	pImage = pImage.scaled(pImage.width(),heightvalue1, Qt::IgnoreAspectRatio, Qt::SmoothTransformation); 

	//intLineStart = 0;
	//intRowStart = 0;
	strType1 = "text";
	strType2 = "2Dcode";
	//strText = strFileName;
	intLineSize = pImage.height();
	intRowSize = pImage.width(); 
	//intSW=1;
	//intSS=0;
	//booNEG=false;
	//booBWDx=false;
	//booBWDy=false;

	for(int y = 0; y< pImage.height(); y++)
	{  
		QRgb* line = (QRgb *)pImage.scanLine(y);  
		for(int x = 0; x< pImage.width(); x++)
		{  
			int average = (qRed(line[x]) + qGreen(line[x]) + qRed(line[x]))/3;  
			if(average < 200)
				boDotBmp[intRowStart +x][intLineStart+intLineSize -y-1] = true;
			else
				boDotBmp[intRowStart +x][intLineStart+intLineSize -y-1] = false;
		}  

	}  
	booFocus = true;
	QString get = QString(QLatin1String(strFileName)).toUtf8();
	//删除文件
	QFile::remove(get);
}

void OBJ_Control::CreateDMcode()
{
	struct zint_symbol *my_symbol;
	int error_number;
	int rotate_angle;
	int generated;
	int batch_mode;
	int mirror_mode;
	char filetype[4];
	int i;

	error_number = 0;

	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = 1;
	my_symbol->symbology = 71;
	my_symbol->scale =0.5;

	my_symbol->option_2 = intDMsize;

	batch_mode = 0;
	mirror_mode = 0;
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strDMContent.c_str(),strDMContent.length(),rotate_angle);

	generated = 1;

	int xPos=0;
	int yPos=0;
	/*for(int i=0;i<OBJ_Vec.size();i++)
	{
		if (booFocus)
		{
			booFocus=false;
			yPos = intLineStart;
			xPos = intRowSize+intRowStart;
		}
	}*/

	
	intLineStart=yPos;
	intRowStart=xPos;
	strType1="text";
	strType2="datamatrix";
	intLineSize=my_symbol->bitmap_height;
	intRowSize=my_symbol->bitmap_width;
	//intDMsize = nType;
	//bmpObj.strDMContent = strContent.toStdString();
	//bmpObj.strText = strContent.toStdString();
	//以下先写死
	/*bmpObj.intSW=1;
	bmpObj.intSS=1;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;*/
	i = 0;
	int r, g, b;

	for (int row = 0; row < my_symbol->bitmap_height; row++)
	{
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
			g = my_symbol->bitmap[i + 1];
			b = my_symbol->bitmap[i + 2];
			i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				//		bmpObj.boDotBmp[col][row-proportion] = true; //由于坐标系的原因，上下必须颠倒
				boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				//		bmpObj.boDotBmp[col][row-proportion] = false;
				boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
	}
	booFocus = true;
}

void OBJ_Control::GetVectorWordDots()
{
	//char* strFileName = new char[256];
	//sprintf(strFileName,"%s","..\\Debug\\HZKSLKTJ");
	FILE *pFile = fopen(m_WordStockFileName.c_str(),"rb");
 
	char* oneWord = new char[2];
	//sprintf(strText,"%s","口");
 
	//循环解码strText中字符的轨迹,根据strFont大小获得相应点阵信息 
	for(int i = 0; i < strText.length(); i++)
	{
		vector<vector<bool>> dots;//记录一个字符的点阵信息，其中高度是strFont，宽带按实际情况返回。
		int nWidth;
		char* oneWord = new char[2];
		sprintf(oneWord,"%s",strText.c_str()[i]);
		ReadOneVectorWord(pFile,oneWord,dots,nWidth);
		delete oneWord;
		//将dots合并到m_dots中
	}

	fclose(pFile);
}


void OBJ_Control::ReadOneVectorWord(FILE *pFile,char* strText,vector<vector<bool>>& dots,int& nWidth)
{ 
	hzPoint topleft(20,20); 
	CGetHZinfo hzInfo(pFile,(unsigned char*)strText,topleft);

}
