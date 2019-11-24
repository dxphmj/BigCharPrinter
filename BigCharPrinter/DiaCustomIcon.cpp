// DiaCustomIcon.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaCustomIcon.h"
#include "afxdialogex.h"


// CDiaCustomIcon �Ի���

IMPLEMENT_DYNAMIC(CDiaCustomIcon, CDialogEx)

CDiaCustomIcon::CDiaCustomIcon(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaCustomIcon::IDD, pParent)
{

}

CDiaCustomIcon::~CDiaCustomIcon()
{
}

void CDiaCustomIcon::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ICON_EDIT, m_IconEdit);
}


BEGIN_MESSAGE_MAP(CDiaCustomIcon, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDiaCustomIcon ��Ϣ�������


BOOL CDiaCustomIcon::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDiaCustomIcon::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������

	CDC* pDC = m_IconEdit.GetDC();
	for(int i = 0; i < 100; i=i+3)
		pDC->SetPixel(10,10+i,COLORREF(RGB(0,0,0)));

	//pDC->MoveTo(0,0);
	//pDC->LineTo(10,10);


	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}
