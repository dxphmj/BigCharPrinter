#pragma once
#include "afxwin.h"
#include "ObjectFileDeal.h"


#define m_nRowSum 16
#define m_nColSum 195

// CDiaPrintEdit �Ի���

class CDiaPrintEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrintEdit)

public:
	CDiaPrintEdit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaPrintEdit();

// �Ի�������
	enum { IDD = IDD_DIA_PRINT_EDIT };
public:
	bool m_bDesign;	 
	int  m_nStepPixels;

	bool m_arrPrintData[m_nRowSum][m_nColSum];
	CObjectFileDeal m_PrintObjectsDeal;

public:
	void DrawOnePoint(CDC* pDC ,int row,int col);


protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ComParam;
	virtual BOOL OnInitDialog();
	CComboBox m_ComData;
	CStatic m_designArea;
	afx_msg void OnPaint();
	afx_msg void OnBnClickedButDesignView();
	afx_msg void OnBnClickedButPrintView();
	afx_msg void OnBnClickedButDesignClean();
	afx_msg void OnBnClickedButDesignSave();
	afx_msg void OnBnClickedButOpenDesign();
	afx_msg void OnBnClickedButInsertParam();
	afx_msg void OnBnClickedButInsertDada();
};
