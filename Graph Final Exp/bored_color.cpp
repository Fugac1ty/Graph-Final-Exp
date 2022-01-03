// bored_color.cpp: 实现文件
//

#include "pch.h"
#include "Graph Final Exp.h"
#include "afxdialogex.h"
#include "bored_color.h"


// bored_color 对话框

IMPLEMENT_DYNAMIC(bored_color, CDialogEx)

bored_color::bored_color(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BORED_COLOR, pParent)
{

}

bored_color::~bored_color()
{
}

void bored_color::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(bored_color, CDialogEx)
	ON_COMMAND(ID_BORED_COLOR, &bored_color::OnBoredColor)
END_MESSAGE_MAP()


// bored_color 消息处理程序


void bored_color::OnBoredColor()
{
	// TODO: 在此添加命令处理程序代码
}
