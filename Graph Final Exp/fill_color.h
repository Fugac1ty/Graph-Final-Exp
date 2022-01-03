#pragma once
#include "afxdialogex.h"


// fill_color 对话框

class fill_color : public CDialogEx
{
	DECLARE_DYNAMIC(fill_color)

public:
	fill_color(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~fill_color();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FILL_COLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
