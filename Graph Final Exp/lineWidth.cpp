// lineWidth.cpp: 实现文件
//

#include "pch.h"
#include "Graph Final Exp.h"
#include "afxdialogex.h"
#include "lineWidth.h"


// lineWidth 对话框

IMPLEMENT_DYNAMIC(lineWidth, CDialogEx)

lineWidth::lineWidth(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_lineWidth, pParent), width(1)
{

}

lineWidth::~lineWidth()
{
}

void lineWidth::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, width);
}


BEGIN_MESSAGE_MAP(lineWidth, CDialogEx)
END_MESSAGE_MAP()


// lineWidth 消息处理程序
