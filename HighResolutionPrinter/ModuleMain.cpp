//#include "StdAfx.h"
#include "ModuleMain.h"
//#include "CodePrinter.h"
#include<cmath>
#include<algorithm>
#include <fstream>
#include<cstdio>
//#include <iostream>
#include <math.h>
#include <sstream>//ʹ�øÿ⺯����ostringstream����int���string
#include <TCHAR.H>
#include "time.h" 
#include "ClassMessage.h"

ModuleMain::ModuleMain(void)
{
}

ModuleMain::~ModuleMain(void)
{
}

bool ModuleMain::MesDisIsB(int MesDis,int isNumber)
{
	return MesDis & (1 << isNumber);
}
//�ַ�ת����
int ModuleMain::charToDigit(char c)
{
	if(c=='A'||c=='a')
		return 10;
	else if(c=='B'||c=='b')
		return 11;
	else if(c=='C'||c=='c')
		return 12;
	else if(c=='D'||c=='d')
		return 13;
	else if(c=='E'||c=='e')
		return 14;
	else if(c=='F'||c=='f')
		return 15;
	else
		return c-'0';
}

int ModuleMain::jinzhi16to10(string pre)
{
	int length=pre.size();
	int result=0;
	for(int i=0; i<length; i++)
	{
		result+=((charToDigit(pre[i]))*pow(16.0,length-1-i));
	}
	return result;
}

int ModuleMain::jinzhi8to10(string pre) {
	int length=pre.size();
	int result=0;
	for(int i=0; i<length; i++)
	{
		result+=((charToDigit(pre[i]))*pow(8.0,length-1-i));
	}
	return result;
}

int ModuleMain::jinzhi2to10(string pre)
{
	// �ڴ˴����������֤�Ƿ�Ϊ���������ֵ��߼�
	int length=pre.size();
	int result=0;
	for(int i=0; i<length; i++)
	{
		result+=((charToDigit(pre[i]))*pow(2.0,length-1-i));
	}
	return result;
}

string ModuleMain::jinzhi10to2(int pre) {
	ostringstream oss;
	while(pre!=0){
		oss<<pre%2;
		pre/=2;
	}
	string res=oss.str();
	oss.str("");//���ԭ������
	for(int i=0;i<res.length();i++){
		oss<<res[res.length()-i-1];
	}
	return oss.str();
}
string ModuleMain::jinzhi10to8(int pre) {
	ostringstream oss;
	while(pre!=0){
		oss<<pre%8;
		pre/=8;
	}
	string res=oss.str();
	oss.str("");//���ԭ������
	for(int i=0;i<res.length();i++){
		oss<<res[res.length()-i-1];
	}
	return oss.str();
}
string ModuleMain::jinzhi10to16(int pre) {
	//ostringstream oss;
	//while(pre!=0){
	//	oss<<pre%16;
	//	pre/=16;
	//}
	//string res=oss.str();
	//oss.str("");//���ԭ������
	//for(int i=0;i<res.length();i++){
	//	oss<<res[res.length()-i-1];
	//}
	//return oss.str();
	string str;
	long long Temp = pre / 16;
	int left = pre % 16;
	if (Temp > 0)
		str += jinzhi10to16(Temp);
	if (left < 10)
		str += (left + '0');
	else
		str += ('A' + left - 10);
	return str;
}

LPCWSTR ModuleMain::stringToLPCWSTR(string orig)
{
	//size_t origsize = orig.length() + 1;
	//const size_t newsize = 100;
	//size_t convertedChars = 0;
	//wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length()-1));
	//mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	//return wcstring;
	//return string2CString(orig);

	
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length()-1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
  
    USES_CONVERSION;  
	return A2W(orig.c_str());
  
}

string ModuleMain::WcharToChar(const wchar_t* wp, size_t m_encode)
{
	std::string str;
	int len = WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), NULL, 0, NULL, NULL);
	char	*m_char = new char[len + 1];
	WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), m_char, len, NULL, NULL);
	m_char[len] = '\0';
	str = m_char;
	delete m_char;
	return str;
}

//string ModuleMain::ReadXml(string xmlFileName,string nameStr,string faultText,string path)
//{
//	path=path+"\\"+xmlFileName;
//	TiXmlDocument mydoc(path.c_str());//xml�ĵ�����
//	bool loadOk=mydoc.LoadFile();//�����ĵ�
//	if(!loadOk)
//	{
//		return faultText;
//	}
//
//	TiXmlElement *RootElement=mydoc.RootElement();	//��Ԫ��
//	for(TiXmlElement *StuElement = RootElement->FirstChildElement();StuElement != NULL;StuElement = StuElement->NextSiblingElement())
//	{
//		string strValue = StuElement->Value();
//		if (strValue==nameStr)
//		{
//			return StuElement->GetText();
//		}
//
//		//��Ԫ��
//		TiXmlElement *childElm=StuElement->FirstChildElement();
//		while (childElm != NULL)
//		{
//			string strChiValue = childElm->Value();
//			if (strChiValue==nameStr)
//			{
//				return childElm->GetText();
//			}
//			childElm = childElm->NextSiblingElement();
//		}
//	}
//    return faultText;
//}

//bool ModuleMain::writeXml(string xmlFileName,string valueStr,string textStr,string path)
//{
//	path=path+"\\"+xmlFileName;
//	TiXmlDocument mydoc(path.c_str());//xml�ĵ�����
//	bool loadOk=mydoc.LoadFile();//�����ĵ�
//	if(!loadOk)
//	{
//		return false;
//	}
//
//	TiXmlElement *RootElement=mydoc.RootElement();	//��Ԫ��
//	for(TiXmlElement *StuElement = RootElement->FirstChildElement();StuElement != NULL;StuElement = StuElement->NextSiblingElement())
//	{
//		string strValue = StuElement->Value();
//		if (strValue==valueStr)
//		{
//			TiXmlText textCs(textStr.c_str());
//			StuElement->InsertEndChild(textCs);
//			mydoc.SaveFile();
//			return true;
//		}
//
//		//��Ԫ��
//		TiXmlElement *childElm=StuElement->FirstChildElement();
//		while (childElm != NULL)
//		{
//			string chiValue = childElm->Value();
//			if (strValue==valueStr)
//			{
//				TiXmlText textCs(textStr.c_str());
//				childElm->InsertEndChild(textCs);
//				mydoc.SaveFile();
//				return true;
//			}
//			childElm = childElm->NextSiblingElement();
//		}
//	}
//	return false;
//}

//bool ModuleMain::changeXml(string xmlFileName,string valueStr,string textStr,string path)
//{
//	path=path+"\\"+xmlFileName;
//	TiXmlDocument mydoc(path.c_str());//xml�ĵ�����
//	bool loadOk=mydoc.LoadFile();//�����ĵ�
//	if(!loadOk)
//	{
//		return false;
//	}
//
//	TiXmlElement *RootElement=mydoc.RootElement();	//��Ԫ��
//	for(TiXmlElement *StuElement = RootElement->FirstChildElement();StuElement != NULL;StuElement = StuElement->NextSiblingElement())
//	{
//		string strValue = StuElement->Value();
//		if (strValue==valueStr)
//		{
//			TiXmlNode *pValue = StuElement->FirstChild();
//			if (pValue)
//			{
//				pValue->SetValue(textStr.c_str());
//				mydoc.SaveFile();
//				return true;
//			}
//		}
//
//		//��Ԫ��
//		TiXmlElement *childElm=StuElement->FirstChildElement();
//		while (childElm != NULL)
//		{
//			string strChiValue = childElm->Value();
//			if (strChiValue==valueStr)
//			{
//				TiXmlNode *pValue = childElm->FirstChild();
//				if (pValue)
//				{
//					pValue->SetValue(textStr.c_str());
//					mydoc.SaveFile();
//					return true;
//				}
//			}
//			childElm = childElm->NextSiblingElement();
//		}
//	}
//	mydoc.SaveFile();
//	return false;
//	
//}

void ModuleMain::string2tchar(std::string &src, char* buf)
{
#ifdef UNICODE  
	//int sprintf_s(buf, MAX_PATH, "%S", src.c_str());//%S���ַ�  
	sprintf_s(buf, MAX_PATH, "%S", src.c_str());//%S���ַ�  
	//_stprintf_s(buf, MAX_PATH, "%S", src.c_str());//%S���ַ�  
#else  
	sprintf_s(buf, MAX_PATH, "%s", src.c_str());//%s���ַ�
	//_stprintf_s(buf, MAX_PATH, "%s", src.c_str());//%s���ַ�
#endif
}

string ModuleMain::TCHAR2STRING(TCHAR *STR)

{

	//int iLen = WideCharToMultiByte(CP_ACP, 0,STR, -1, NULL, 0, NULL, NULL);   //���ȼ���TCHAR ���ȡ�

	//char* chRtn =new char[iLen*sizeof(char)];  //����һ�� TCHAR ���ȴ�С�� CHAR ���͡�

	//WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);  //��TCHAR ���͵�����ת��Ϊ CHAR ���͡�

	//std::string str(chRtn); //���CHAR �������� ת��Ϊ STRING �������ݡ�

	//return str;

	return   UnicodeToUtf8(STR);  


}


const char* ModuleMain::CString2ConstChar(CString str)
{
	//CStringA     stra(str.GetBuffer(0));
	//str.ReleaseBuffer();
	//string          st(stra.GetBuffer(0));
	//const char*  cs = st.c_str();
	wchar_t szBuf[1024];
	wcscpy_s(reinterpret_cast<wchar_t*>(szBuf),	sizeof(szBuf) / sizeof(wchar_t),reinterpret_cast<const wchar_t*>(str.utf16()));
	char szStr[256] = {};  
	wcstombs(szStr, szBuf, sizeof(szBuf));//�����ַ�ת���ɶ��ַ�  
	const char* pBuf = szStr; 
	return pBuf;
}

//string ModuleMain::CString2string(CString csStrData)
//{
//	string strRet ;
//
//	char ss[2048];
//	memset(ss, 0, sizeof(char)*2048);
//	sprintf(ss, "%s", csStrData);
//
//	strRet = ss;
//	return strRet;
//}
/*
void ModuleMain::InitCommMsg()
{
	MyDcb tempDcb;
	tempDcb.nComPort=4;
	tempDcb.BaudRate=115200;
	tempDcb.ByteSize=(BYTE)8;
	tempDcb.Parity=(BYTE)0;
	tempDcb.StopBits=(BYTE)0;
	tempDcb.bIsSave=true;
	theApp.myCIOVsd.SetComIndx(tempDcb.nComPort);
	if (!theApp.myCIOVsd.OpenComm(tempDcb))
	{
		CString csMsg ;//= _T("����4��ʧ��!");
		csMsg.Format(_T("����%d��ʧ��!"),tempDcb.nComPort);
		AfxMessageBox(csMsg);
	}
}*/

//�������кŸ�ʽ������ӡ�ı�
string ModuleMain::SerialFormatToText(int Value, int Digits, int Format)
{
	string OutPutSerialText="";
	string strTemp="";
	switch(Format)
	{
	case 0:
		for (int a=0;a<Digits;a++)
		{
			strTemp=strTemp+"0";
		}
		strTemp=strTemp+OBJ_Control::to_String(Value);
		OutPutSerialText=strTemp.substr(strTemp.length()-Digits,Digits);
		break;
	case 1:
		for (int a=0;a<Digits;a++)
		{
			strTemp=strTemp+" ";
		}
		strTemp=strTemp+OBJ_Control::to_String(Value);
		OutPutSerialText=strTemp.substr(strTemp.length()-Digits,Digits);
		break;
	case 2:
		strTemp=OBJ_Control::to_String(Value);
		int n=Digits-strTemp.length();
		for(int a=0;a<n;a++)
		{
			strTemp=strTemp+" ";
		}
		OutPutSerialText=strTemp;
		break;
	}
	return OutPutSerialText;
}

string ModuleMain::TimeFormatToText(CString InPutTimeFormat,int tempstrETimeOffSet, int tempintTimeOffSet, int tempstrTimeOffSetUint)
{	
	time_t lt;
	struct tm *ptr;
	QDateTime NowTime1;
	QDateTime NowTime2;
	QDateTime NowTime3;
	QDateTime NowTime4;
	char buf[100];
	CString outCStr;
	if (tempstrETimeOffSet==0)
	{
		QDateTime NowTime=QDateTime::currentDateTime();
		//CTime NowTime=CTime::currentTime();
		lt=time(NULL);
		ptr=localtime(&lt);
		
		strftime(buf,100,InPutTimeFormat.toStdString().c_str(),ptr);
		outCStr=buf;
		//outCStr=NowTime.toString(InPutTimeFormat);
	} 
	else
	{
		CTime tempTime=CTime::currentTime();
		QDate tempTime1=QDate::currentDate();
		//outCStr=NowTime.Format(InPutTimeFormat);
		QDateTime NowTime=QDateTime::currentDateTime();

		int addYear=0,addMonth=0,addDay=0,addHour=0,addMinute=0;
		switch(tempstrTimeOffSetUint)
		{
		case 0:
			if (tempTime1.year()+tempintTimeOffSet<3000)
			{
				addYear=tempintTimeOffSet;
				
				lt=NowTime.addYears(addYear).toTime_t();
				ptr=localtime(&lt);

				//NowTime=QDateTime(tempTime1.year(),tempTime1.month(),tempTime1.day(),tempTime.hour(),tempTime.minute(),tempTime.second());
			}
			break;
		case 1:
			while(tempTime1.month()+tempintTimeOffSet>12)
			{
				addYear++;
				tempintTimeOffSet-=12;
			}
			addMonth=tempintTimeOffSet;
			
			NowTime1=NowTime.addYears(addYear);
			lt=NowTime1.addMonths(addMonth).toTime_t();
			ptr=localtime(&lt);
			//NowTime.addYears(addYear);
			//NowTime.addMonths(tempintTimeOffSet);

			//NowTime=CTime(tempTime1.year()+addYear,tempTime1.month()+addMonth,tempTime1.day()+addDay,tempTime.hour()+addHour,tempTime.minute()+addMinute,tempTime.second());

			break;
		case 2:
			while (tempTime1.day()+tempintTimeOffSet>31)
			{
				addMonth++;
				tempintTimeOffSet-=31;
			}
			addDay=tempintTimeOffSet;
			while(tempTime1.month()+addMonth>12)
			{
				addYear++;
				addMonth-=12;
			}
			
			NowTime1=NowTime.addYears(addYear);
			NowTime2=NowTime1.addMonths(addMonth);
			lt=NowTime2.addDays(addDay).toTime_t();
			ptr=localtime(&lt);
			
			//NowTime.addYears(addYear);
			//NowTime.addMonths(addMonth);
			//NowTime.addDays(addDay);

			//NowTime=CTime(tempTime1.year()+addYear,tempTime1.month()+addMonth,tempTime1.day()+addDay,tempTime.hour()+addHour,tempTime.minute()+addMinute,tempTime.second());
			break;
		case 3:
			while(tempTime.hour()+tempintTimeOffSet>23)
			{
				addDay++;
				tempintTimeOffSet-=24;
			}
			addHour=tempintTimeOffSet;
			while(tempTime1.day()+addDay>31)
			{
				addMonth++;
				addDay-=31;
			}
			while(tempTime1.month()+addMonth>12)
			{
				addYear++;
				addMonth-=12;
			}
			NowTime1=NowTime.addYears(addYear);
			NowTime2=NowTime1.addMonths(addMonth);
			NowTime3=NowTime2.addDays(addDay);
			lt=NowTime3.addSecs(addHour*3600).toTime_t();
			ptr=localtime(&lt);
			
			//NowTime.addYears(addYear);
			//NowTime.addMonths(addMonth);
			//NowTime.addDays(addDay);
			//NowTime.addSecs(addHour*3600);
			//NowTime=CTime(tempTime1.year()+addYear,tempTime1.month()+addMonth,tempTime1.day()+addDay,tempTime.hour()+addHour,tempTime.minute()+addMinute,tempTime.second());
			break;
		case 4:
			while(tempTime.minute()+tempintTimeOffSet>59)
			{
				addHour++;
				tempintTimeOffSet-=60;
			}
			addMinute=tempintTimeOffSet;
			while(tempTime.hour()+addHour>23)
			{
				addDay++;
				addHour-=24;
			}
			while(tempTime1.day()+addDay>31)
			{
				addMonth++;
				addDay-=31;
			}
			while(tempTime1.month()+addMonth>12)
			{
				addYear++;
				addMonth-=12;
			}
			
			
			NowTime1=NowTime.addYears(addYear);
			NowTime2=NowTime1.addMonths(addMonth);
			NowTime3=NowTime2.addDays(addDay);
			NowTime4=NowTime3.addSecs(addHour*3600);
			lt=NowTime4.addSecs(addMinute*60).toTime_t();//��Ϊû��ֱ�Ӷ�hour��minute����ƫ�Ƶĺ�����ֻ��ͨ��ƫ����������ɶ�hour��minute��ƫ��
			ptr=localtime(&lt);
			/*NowTime.addYears(addYear);
			NowTime.addMonths(addMonth);
			NowTime.addDays(addDay);
			NowTime.addSecs(addHour*3600);
			NowTime.addSecs(addMinute*60);*/
			//NowTime=CTime(tempTime1.year()+addYear,tempTime1.month()+addMonth,tempTime1.day()+addDay,tempTime.hour()+addHour,tempTime.minute()+addMinute,tempTime.second());
			break;
		}
		strftime(buf,100,InPutTimeFormat.toStdString().c_str(),ptr);
		outCStr=buf;
		//outCStr=NowTime.toString(InPutTimeFormat);
	}
	return CString2string(outCStr);
}
std::string ModuleMain::ASCToUTF8(const std::string& str) 
{
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);   
	wchar_t *pUnicode = new  wchar_t[unicodeLen + 1];   
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));  
	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, (LPWSTR)pUnicode, unicodeLen);  
	std::wstring wrt = (wchar_t*)pUnicode;    delete  pUnicode;   
	int iTextLen = WideCharToMultiByte(CP_UTF8, 0, wrt.c_str(), -1, NULL, 0, NULL, NULL);  
	char *pElementText = new char[iTextLen + 1];   
	memset((void*)pElementText, 0, sizeof(char) * (iTextLen + 1)); 
	::WideCharToMultiByte(CP_UTF8, 0, wrt.c_str(), -1, pElementText, iTextLen, NULL, NULL);   
	std::string strText = pElementText;    delete pElementText;    
	return strText;
}


//�ַ�ת����
wstring ModuleMain::AsciiToUnicode(const string& str) {  
	// Ԥ��-�������п��ֽڵĳ���    
	int unicodeLen = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, nullptr, 0);  
	// ��ָ�򻺳�����ָ����������ڴ�    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);  
	// ��ʼ�򻺳���ת���ֽ�    
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, pUnicode, unicodeLen);  
	wstring ret_str = pUnicode;  
	free(pUnicode);  
	return ret_str;  
}  
string ModuleMain::UnicodeToAscii(const wstring& wstr) {  
	// Ԥ��-�������ж��ֽڵĳ���    
	int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);  
	// ��ָ�򻺳�����ָ����������ڴ�    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);  
	// ��ʼ�򻺳���ת���ֽ�    
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);  
	string ret_str = pAssii;  
	free(pAssii);  
	return ret_str;  
}  
wstring ModuleMain::Utf8ToUnicode(const string& str) {  
	// Ԥ��-�������п��ֽڵĳ���    
	int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);  
	// ��ָ�򻺳�����ָ����������ڴ�    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);  
	// ��ʼ�򻺳���ת���ֽ�    
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);  
	wstring ret_str = pUnicode;  
	free(pUnicode);  
	return ret_str;  
}  
string ModuleMain::UnicodeToUtf8(const wstring& wstr) {  
	// Ԥ��-�������ж��ֽڵĳ���    
	int ansiiLen = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);  
	// ��ָ�򻺳�����ָ����������ڴ�    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);  
	// ��ʼ�򻺳���ת���ֽ�    
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, pAssii, ansiiLen, nullptr, nullptr);  
	string ret_str = pAssii;  
	free(pAssii);  
	return ret_str;  
}  
string ModuleMain::AsciiToUtf8(const string& str) {  
	return UnicodeToUtf8(AsciiToUnicode(str));  
}  
string ModuleMain::Utf8ToAscii(const string& str) {  
	return UnicodeToAscii(Utf8ToUnicode(str));  
}  
 
// string �� Int ��ת  
int ModuleMain::StringToInt(const string& str) {  
	return atoi(str.c_str());  
}  
string ModuleMain::IntToString(int i) {  
	char ch[1024];  
	memset(ch, 0, 1024);  
	sprintf_s(ch, sizeof(ch), "%d", i);  
	return ch;  
}  
string ModuleMain::IntToString(char i) {  
	char ch[1024];  
	memset(ch, 0, 1024);  
	sprintf_s(ch, sizeof(ch), "%c", i);  
	return ch;  
}  
string ModuleMain::IntToString(double i) {  
	char ch[1024];  
	memset(ch, 0, 1024);  
	sprintf_s(ch, sizeof(ch), "%f", i);  
	return ch;  
}  