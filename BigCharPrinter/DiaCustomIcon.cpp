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
	m_nStep = 10;
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


	//���������
	CBrush cbrush;
	CBrush* pBrush; //�ɱ�ˢ
	CRect rect;
	m_drawPic.GetClientRect(&rect);
	cbrush.CreateSolidBrush(RGB(255,255,255)); 
	pBrush = pDC->SelectObject(&cbrush); //�����ˢ
	pDC->Rectangle(&rect); //���ƾ���		
	pDC->SelectObject(pBrush); //�ָ���ˢ
	cbrush.DeleteObject();
	pBrush->DeleteObject();


	m_drawPic.SetWindowPos(NULL, -1, -1, 16*m_nStep, 16*m_nStep, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
	int i;
	for (i = 0; i <= 16; i++)
	{		 
		pDC->MoveTo(0,i*m_nStep);
		pDC->LineTo(16*m_nStep,i*m_nStep);			 
	}

	for (i = 0; i <= 16; i++)
	{		 
		pDC->MoveTo(i*m_nStep,0);
		pDC->LineTo(i*m_nStep,16*m_nStep);			 
	}

	//����m_arrData����
	for(int nRow = 0; nRow < 16; nRow++)
	{
		for(int nCol = 0; nCol < 16; nCol++)
		{
			if(m_arrData[nRow][nCol])
			{
				CBrush cbrush;
				CBrush* pBrush; //�ɱ�ˢ				 
				cbrush.CreateSolidBrush(RGB(255,0,0)); //��ɫ
				pBrush = pDC->SelectObject(&cbrush); //�����ˢ	
				pDC->Ellipse(nRow*m_nStep,nCol*m_nStep,(nRow+1)*m_nStep,(nCol+1)*m_nStep);

				pDC->SelectObject(pBrush); //�ָ���ˢ
				cbrush.DeleteObject();
				pBrush->DeleteObject();
			}
		}
	}
}



void CDiaCustomIcon::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonDown(nFlags, point);
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//////////////////////////////////////////////////////////////////////////	
	//���ѵ�ǰ��������ת��Ϊ�����rect������
	CRect lRect;
	m_drawPic.GetWindowRect(&lRect);  //��ȡ�ؼ��������Ļ��λ��
	ScreenToClient(&lRect);

	if((point.x >= lRect.left && point.x <= lRect.right) && (point.y >= lRect.top && point.y <= lRect.bottom))
	{
		point.x -= lRect.left;
		point.y -= lRect.top;
		int nRow;
		int nCol;	 
		nRow = point.x / m_nStep;
		nCol = point.y / m_nStep;
		m_arrData[nRow][nCol] = !m_arrData[nRow][nCol]; //�����鸳ֵ,ȡ��
	}
	OnPaint();	
}