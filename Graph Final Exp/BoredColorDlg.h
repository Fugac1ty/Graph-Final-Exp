#pragma once
#include "afxdialogex.h"


// BoredColorDlg 对话框

class BoredColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BoredColorDlg)

public:
	BoredColorDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~BoredColorDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BORED_COLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_b;
	int m_g;
	int m_r;
	afx_msg void OnBoredColor();
	afx_msg void OnLinetypeDash();
};
