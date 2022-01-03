// BoredColorDlg.cpp: 实现文件
//

#include "pch.h"
#include "Graph Final Exp.h"
#include "afxdialogex.h"
#include "BoredColorDlg.h"


// BoredColorDlg 对话框

IMPLEMENT_DYNAMIC(BoredColorDlg, CDialogEx)

BoredColorDlg::BoredColorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BORED_COLOR, pParent), m_b(0),m_g(0),m_r(0)

{

}

BoredColorDlg::~BoredColorDlg()
{
}

void BoredColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_R, m_r);
	DDX_Text(pDX, IDC_G, m_g);
	DDX_Text(pDX, IDC_B, m_b);
}


BEGIN_MESSAGE_MAP(BoredColorDlg, CDialogEx)
	ON_COMMAND(ID_BORED_COLOR, &BoredColorDlg::OnBoredColor)
	ON_COMMAND(ID_LINETYPE_DASH, &BoredColorDlg::OnLinetypeDash)
END_MESSAGE_MAP()


// BoredColorDlg 消息处理程序


void BoredColorDlg::OnBoredColor()
{
	// TODO: 在此添加命令处理程序代码
	CDialog* dlg = new CDialog;
	dlg->Create(MAKEINTRESOURCE(IDD_BORED_COLOR));
	dlg->ShowWindow(1);
}


void BoredColorDlg::OnLinetypeDash()
{
	// TODO: 在此添加命令处理程序代码

}
