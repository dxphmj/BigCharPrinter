// DiaCustomIcon.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaCustomIcon.h"
#include "afxdialogex.h"



// CDiaCustomIcon �Ի���

IMPLEMENT_DYNAMIC(CDiaCustomIcon, CDialogEx)

	
int nStep = 10;

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
	DDX_Control(pDX, IDC_PIC, m_drawPic);
}


BEGIN_MESSAGE_MAP(CDiaCustomIcon, CDialogEx)
	
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	
END_MESSAGE_MAP()


// CDiaCustomIcon ��Ϣ�������





BOOL CDiaCustomIcon::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	for(int i = 0; i < 16; i++)
		for(int j = 0; j < 16; j++)
			m_arrData[i][j] = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDiaCustomIcon::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	CDC *pDC = m_drawPic.GetDC();
	//pDC->SetPixel(10,10,RGB(0,0,0));
	int i;
	//int nStep = 10;
	
		for (i = 0; i <= 16; i++)
		{		 
			pDC->MoveTo(0,i*nStep);
			pDC->LineTo(16*nStep,i*nStep);			 
		}

		for (i = 0; i <= 16; i++)
		{		 
			pDC->MoveTo(i*nStep,0);
			pDC->LineTo(i*nStep,16*nStep);			 
		}

		//����m_arrData����

		for(int nRow = 0; nRow < 16; nRow++)
			for(int nCol = 0; nCol < 16; nCol++)
			{
				if(m_arrData[nRow][nCol])
				{
					//����,�һ���Բ�ĵ��ú���
					//pDC->SetPixel(i*nStep+nStep/2,j*nStep+nStep/2,RGB(255,0,0));
					CBrush *pOldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);

					//ѡ�뻭��
					CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
					CPen *pOldPen = pDC->SelectObject(&pen);

					pDC->Ellipse(nRow*nStep,nCol*nStep,(nRow+1)*nStep,(nCol+1)*nStep);

					//�ָ�����
					pDC->SelectObject(pOldPen);

					//�ָ���ˢ
					pDC->SelectObject(pOldBrush);
					
				}
			}
		
		
	
	
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
}



void CDiaCustomIcon::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//////////////////////////////////////////////////////////////////////////
	/*CDC *pDC = m_drawPic.GetDC();
	CString str;
	str.Format(TEXT("%d,%d"),point.x,point.y);
	pDC->FillSolidRect(0,0,100,100,GetSysColor(COLOR_WINDOW));
	pDC->TextOut(0,0,str);
	ReleaseDC(pDC);*/
	//////////////////////////////////////////////////////////////////////////
	GetCursorPos(&point);
	//Ȼ��õ�static�ؼ���rect����
	CRect pRect;
	CWnd *pWnd = GetDlgItem(IDC_PIC);
	pWnd->GetClientRect(&pRect);
	//���ѵ�ǰ��������ת��Ϊ�����rect������
	pWnd->ScreenToClient(&point);
	CDialogEx::OnLButtonDown(nFlags, point);
	int nRow;
	int nCol;
	//GetPosition(point,&nRow,&nCol)
	//bool bIn = GetPosition(point,&nRow,&nCol);
	//�����鸳ֵ
	
	if (point.x <= 16*nStep && point.y <= 16*nStep )
	{
		nRow = point.x / nStep;
		nCol = point.y / nStep;
		m_arrData[nRow][nCol] = 1; //�����鸳ֵ
	}
		
}