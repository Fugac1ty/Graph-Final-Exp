#pragma once
#include "afxdialogex.h"


// bored_color 对话框

class bored_color : public CDialogEx
{
	DECLARE_DYNAMIC(bored_color)

public:
	bored_color(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~bored_color();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BORED_COLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBoredColor();
};
