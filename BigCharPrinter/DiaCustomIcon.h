#pragma once
#include "afxwin.h"


// CDiaCustomIcon �Ի���

class CDiaCustomIcon : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaCustomIcon)

public:
	CDiaCustomIcon(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaCustomIcon();

// �Ի�������
	enum { IDD = IDD_DIA_CUSTOM_ICON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_IconEdit;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
