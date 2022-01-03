#pragma once
#include "afxdialogex.h"


// lineWidth 对话框

class lineWidth : public CDialogEx
{
	DECLARE_DYNAMIC(lineWidth)

public:
	lineWidth(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~lineWidth();
	int width;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_lineWidth };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	DECLARE_MESSAGE_MAP()
};
