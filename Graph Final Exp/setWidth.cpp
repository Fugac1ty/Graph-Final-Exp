// setWidth.cpp: 实现文件
//

#include "pch.h"
#include "Graph Final Exp.h"
#include "afxdialogex.h"
#include "setWidth.h"


// setWidth 对话框

IMPLEMENT_DYNAMIC(setWidth, CDialogEx)

setWidth::setWidth(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_lineWidth,pParent)
{

}

setWidth::~setWidth()
{
}

void setWidth::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(setWidth, CDialogEx)
END_MESSAGE_MAP()


// setWidth 消息处理程序
