
// Graph Final ExpView.cpp: CGraphFinalExpView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Graph Final Exp.h"
#endif

#include "Graph Final ExpDoc.h"
#include "Graph Final ExpView.h"

#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Circle.h"
#include "Triangle.h"
#include "SegmentLines.h"
#include "Polygon.h"
#include"BoredColorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "setWidth.h"
#include "lineWidth.h"

int borded_r;
int borded_g;
int borded_b;
int fill_r;
int fill_g;
int fill_b;
bool saveTag=FALSE;
CString saveFilePath;
// CGraphFinalExpView

IMPLEMENT_DYNCREATE(CGraphFinalExpView, CView)

BEGIN_MESSAGE_MAP(CGraphFinalExpView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGraphFinalExpView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
//	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_SHAPE_ELLIPSE, &CGraphFinalExpView::OnShapeEllipse)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SHAPE_MOVE, &CGraphFinalExpView::OnShapeMove)
	ON_COMMAND(ID_SHAPE_REVOLVE, &CGraphFinalExpView::OnShapeRevolve)
	ON_COMMAND(ID_SHAPE_DRAW, &CGraphFinalExpView::OnShapeDraw)
	ON_COMMAND(ID_SHAPE_LINE, &CGraphFinalExpView::OnShapeLine)
	ON_COMMAND(ID_SHAPE_SEGMENTLINES, &CGraphFinalExpView::OnShapeSegmentlines)
	ON_COMMAND(ID_SHAPE_POLYGON, &CGraphFinalExpView::OnShapePolygon)
	ON_COMMAND(ID_SHAPE_RECTANGLE, &CGraphFinalExpView::OnShapeRectangle)
	ON_COMMAND(ID_SHAPE_CIRCLE, &CGraphFinalExpView::OnShapeCircle)
	ON_COMMAND(ID_BORED_COLOR, &CGraphFinalExpView::OnBoredColor)
	ON_COMMAND(ID_FILL_COLOR, &CGraphFinalExpView::OnFillColor)
	ON_COMMAND(ID_CLEAR, &CGraphFinalExpView::OnClear)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_LINETYPE_SOLID, &CGraphFinalExpView::OnLinetypeSolid)
	ON_COMMAND(ID_LINETYPE_DASH, &CGraphFinalExpView::OnLinetypeDash)
	ON_COMMAND(ID_LINETYPE_DOT, &CGraphFinalExpView::OnLinetypeDot)
	ON_COMMAND(ID_LINETYPE_DASHDOT, &CGraphFinalExpView::OnLinetypeDashdot)
	ON_COMMAND(ID_LINETYPE_DASHDOTDOT, &CGraphFinalExpView::OnLinetypeDashdotdot)
	ON_COMMAND(ID_SAVE, &CGraphFinalExpView::OnSave)
	ON_COMMAND(ID_SET_LINEWIDTH, &CGraphFinalExpView::OnSetLinewidth)
END_MESSAGE_MAP()

// CGraphFinalExpView 构造/析构

CGraphFinalExpView::CGraphFinalExpView() noexcept : 
	m_lineType(PS_SOLID),
	m_borderColor(RGB(0, 0, 0)),//黑色
	m_fillColor(RGB(255, 255, 255)),//白色
	m_shapeType(LINE),//直线
	m_drawState(0),
	m_shapeState(1),
	a(1)
{
	// TODO: 在此处添加构造代码

}

CGraphFinalExpView::~CGraphFinalExpView()
{
}

BOOL CGraphFinalExpView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGraphFinalExpView 绘图

void CGraphFinalExpView::OnDraw(CDC* pDC)
{
	CGraphFinalExpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->draw(pDC);
	// TODO: 在此处为本机数据添加绘制代码
}


// CGraphFinalExpView 打印


void CGraphFinalExpView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGraphFinalExpView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGraphFinalExpView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGraphFinalExpView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

//void CGraphFinalExpView::OnRButtonUp(UINT /* nFlags */, CPoint point)
//{
//
//}

void CGraphFinalExpView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGraphFinalExpView 诊断

#ifdef _DEBUG
void CGraphFinalExpView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphFinalExpView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphFinalExpDoc* CGraphFinalExpView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphFinalExpDoc)));
	return (CGraphFinalExpDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphFinalExpView 消息处理程序


void CGraphFinalExpView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CView::OnLButtonDown(nFlags, point);
	if (m_shapeState == 1) {
		m_drawState = 1;//开始绘图

		CShape* newShape = NULL;//新形状


		switch (m_shapeType)
		{
		case POLYGON:
			newShape = new CPolygon(m_lineType, m_borderColor, m_fillColor, point, point, a);
			break;
		case SEGMENTLINES:
			newShape = new CSegmentLines(m_lineType, m_borderColor, m_fillColor, point, point,a);
			break;
		case LINE://直线
			newShape = new CLine(m_lineType, m_borderColor, m_fillColor, point, point,a);
			//终点未定

			break;
		case RECTANGLE://矩形
			newShape = new CRectangle(m_lineType, m_borderColor, m_fillColor, point, point,a);

			break;
		case ELLIPSE:
			//TRACE("1");
			newShape = new CEllipse(m_lineType, m_borderColor, m_fillColor, point, point,a);
			break;
		case CIRCLE:
			//TRACE("1");
			newShape = new  CCircle(m_lineType, m_borderColor, m_fillColor, point, point,a);
			break;
		case TRIANGLE:
			//TRACE("1");
			newShape = new  CTriangle(m_lineType, m_borderColor, m_fillColor, point, point,a);
			break;

		}


		//获取文档指针以存入数据
		CGraphFinalExpDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);

		pDoc->push_back(newShape);
	}
	else if (m_shapeState == 2) {
		m_drawState = 1;
		LastMousePoint = point;
	}
	else if (m_shapeState == 4) {
		CGraphFinalExpDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->setLineType(m_lineType);
		pDoc->setBorderColor(m_borderColor);
		pDoc->setFillColor(m_fillColor);
		Invalidate();


		//pDoc.bac;
	}
	else if (m_shapeState == 3) {
		CGraphFinalExpDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->shapes.back()->Revolve();
		Invalidate();


	}
}


void CGraphFinalExpView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	if (m_shapeState == 1) {

		m_drawState = 0;//结束绘图
		//获取文档指针以存入数据
		CGraphFinalExpDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);

		pDoc->setEndPoint(point);
		//TRACE("%d %d", pDoc->Square(), pDoc->Length());
		//Invalidate();//将客户区无效化，导致刷新
		CPoint TempPoint;//该变量用于计算图像中心
		CPoint SumPoint;
		SumPoint.x = pDoc->shapes.back()->getStartPoint().x + pDoc->shapes.back()->getEndPoint().x;				//***********************************************/
		SumPoint.y = pDoc->shapes.back()->getStartPoint().y + pDoc->shapes.back()->getEndPoint().y;				//
		for (int i = 0; i < (pDoc->shapes.back()->LineNode.size()); i++) {										//			
			SumPoint.x = SumPoint.x + pDoc->shapes.back()->LineNode[i].x;										//			
			SumPoint.y = SumPoint.y + pDoc->shapes.back()->LineNode[i].y;										//
																												//
		}																										//
		TempPoint.x = SumPoint.x / (2 + pDoc->shapes.back()->LineNode.size());									//			此段为计算图像中心点
		TempPoint.y = SumPoint.y / (2 + pDoc->shapes.back()->LineNode.size());									//			并在中间标出图像信息
		CClientDC dc(this);

		//Invalidate();
	}
	else if (m_shapeState == 2) {

		m_drawState = 0;//结束绘图
		//获取文档指针以存入数据
		CGraphFinalExpDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		CPoint TempPoint;//该变量用于计算图像中心
		CPoint SumPoint;
		SumPoint.x = pDoc->shapes.back()->getStartPoint().x + pDoc->shapes.back()->getEndPoint().x;				//***********************************************/
		SumPoint.y = pDoc->shapes.back()->getStartPoint().y + pDoc->shapes.back()->getEndPoint().y;				//
		for (int i = 0; i < (pDoc->shapes.back()->LineNode.size()); i++) {										//			此段为计算图像中心点
			SumPoint.x = SumPoint.x + pDoc->shapes.back()->LineNode[i].x;										//			并在中间标出图像信息
			SumPoint.y = SumPoint.y + pDoc->shapes.back()->LineNode[i].y;										//
																												//***********************************************/
		}
		TempPoint.x = SumPoint.x / (2 + pDoc->shapes.back()->LineNode.size());
		TempPoint.y = SumPoint.y / (2 + pDoc->shapes.back()->LineNode.size());
		CClientDC dc(this);
	}
	else if (m_shapeState == 4) {
		CGraphFinalExpDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		CPoint TempPoint;//该变量用于计算图像中心
		CPoint SumPoint;

		SumPoint.x = pDoc->shapes.back()->getStartPoint().x + pDoc->shapes.back()->getEndPoint().x;				//***********************************************/
		SumPoint.y = pDoc->shapes.back()->getStartPoint().y + pDoc->shapes.back()->getEndPoint().y;				//
		for (int i = 0; i < (pDoc->shapes.back()->LineNode.size()); i++) {										//			
			SumPoint.x = SumPoint.x + pDoc->shapes.back()->LineNode[i].x;										//			
			SumPoint.y = SumPoint.y + pDoc->shapes.back()->LineNode[i].y;										//
																												//
		}																										//
		TempPoint.x = SumPoint.x / (2 + pDoc->shapes.back()->LineNode.size());									//			此段为计算图像中心点
		TempPoint.y = SumPoint.y / (2 + pDoc->shapes.back()->LineNode.size());									//			并在中间标出图像信息
		CClientDC dc(this);

	}
	else if (m_shapeState == 3) {
		CGraphFinalExpDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		CPoint TempPoint;//该变量用于计算图像中心
		CPoint SumPoint;

		SumPoint.x = pDoc->shapes.back()->getStartPoint().x + pDoc->shapes.back()->getEndPoint().x;				//***********************************************/
		SumPoint.y = pDoc->shapes.back()->getStartPoint().y + pDoc->shapes.back()->getEndPoint().y;				//
		for (int i = 0; i < (pDoc->shapes.back()->LineNode.size()); i++) {										//			
			SumPoint.x = SumPoint.x + pDoc->shapes.back()->LineNode[i].x;										//			
			SumPoint.y = SumPoint.y + pDoc->shapes.back()->LineNode[i].y;										//
																												//
		}																										//
		TempPoint.x = SumPoint.x / (2 + pDoc->shapes.back()->LineNode.size());									//			此段为计算图像中心点
		TempPoint.y = SumPoint.y / (2 + pDoc->shapes.back()->LineNode.size());									//			并在中间标出图像信息
		CClientDC dc(this);

	}
}


void CGraphFinalExpView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnMouseMove(nFlags, point);

	static int refreshFlag = 0;//防止刷新过快造成闪烁
	int time = 256;//refreshFlag的循环周期，不会影响刷新频率
	int interval = 1;//每interval次调用此函数就刷新一次
	if (m_shapeState == 1) {
		if (m_drawState == 1)//只在绘画过程刷新，以免闪烁
		{
			CGraphFinalExpDoc* pDoc = GetDocument();
			ASSERT_VALID(pDoc);
			pDoc->setEndPoint(point);
			if (refreshFlag >= time)
			{
				refreshFlag = 0;//循环
			}
			if (refreshFlag % interval == 0)
			{
				Invalidate();
			}
						
			refreshFlag++;

		}

	}
	else if (m_shapeState == 2) {
		if (m_drawState == 1)//只在绘画过程刷新，以免闪烁
		{
			CPoint TempPoint;
			CGraphFinalExpDoc* pDoc = GetDocument();
			ASSERT_VALID(pDoc);
			TempPoint.x = point.x - LastMousePoint.x;
			TempPoint.y = point.y - LastMousePoint.y;
			pDoc->Move(TempPoint);

			LastMousePoint.x = point.x;
			LastMousePoint.y = point.y;
			if (refreshFlag >= time)
			{
				refreshFlag = 0;//循环
			}
			if (refreshFlag % interval == 0)
			{
				Invalidate();
			}
			refreshFlag++;
		}
	}

}


void CGraphFinalExpView::OnShapeMove()
{
	// TODO: 在此添加命令处理程序代码
	m_shapeState = 2;
}


void CGraphFinalExpView::OnShapeRevolve()
{
	// TODO: 在此添加命令处理程序代码
	m_shapeState = 3;
}


void CGraphFinalExpView::OnShapeDraw()
{
	// TODO: 在此添加命令处理程序代码
	m_shapeState = 1;
}


void CGraphFinalExpView::OnShapeLine()
{
	// TODO: 在此添加命令处理程序代码
	m_shapeType = LINE;
}


void CGraphFinalExpView::OnShapeSegmentlines()
{
	// TODO: 在此添加命令处理程序代码
	m_shapeType = SEGMENTLINES;
}



void CGraphFinalExpView::OnShapePolygon()
{
	// TODO: 在此添加命令处理程序代码
	m_shapeType = POLYGON;
}


void CGraphFinalExpView::OnShapeRectangle()
{
	// TODO: 在此添加命令处理程序代码
	m_shapeType = RECTANGLE;
}


void CGraphFinalExpView::OnShapeCircle()
{
	// TODO: 在此添加命令处理程序代码
	m_shapeType = CIRCLE;
}

void CGraphFinalExpView::OnShapeEllipse()
{
	m_shapeType = ELLIPSE;
}

void CGraphFinalExpView::OnBoredColor()
{
	// TODO: 在此添加命令处理程序代码
	BoredColorDlg dia;

	if (dia.DoModal() == IDOK)
	{
		borded_b = dia.m_b;
		borded_g = dia.m_g;
		borded_r = dia.m_r;
	}
	m_borderColor = RGB(borded_r, borded_g, borded_b);
}


void CGraphFinalExpView::OnFillColor()
{
	// TODO: 在此添加命令处理程序代码
	BoredColorDlg dia;

	if (dia.DoModal() == IDOK)
	{
		fill_b = dia.m_b;
		fill_g = dia.m_g;
		fill_r = dia.m_r;
	}
	m_fillColor = RGB(fill_r, fill_g, fill_b);
}


void CGraphFinalExpView::OnClear()
{
	// TODO: 在此添加命令处理程序代码
	CGraphFinalExpDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->clear();
	Invalidate();
}


void CGraphFinalExpView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_drawState == 1 && (m_shapeType == SEGMENTLINES || m_shapeType == POLYGON)) {
		CGraphFinalExpDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pDoc->setLinePoint(point);
	}
	CView::OnRButtonDown(nFlags, point);
}


void CGraphFinalExpView::OnLinetypeSolid()
{
	// TODO: 在此添加命令处理程序代码
	m_lineType = PS_SOLID;
}


void CGraphFinalExpView::OnLinetypeDash()
{
	// TODO: 在此添加命令处理程序代码
	m_lineType = PS_DASH;
}


void CGraphFinalExpView::OnLinetypeDot()
{
	// TODO: 在此添加命令处理程序代码
	m_lineType = PS_DOT;
}


void CGraphFinalExpView::OnLinetypeDashdot()
{
	// TODO: 在此添加命令处理程序代码
	m_lineType = PS_DASHDOT;
}


void CGraphFinalExpView::OnLinetypeDashdotdot()
{
	// TODO: 在此添加命令处理程序代码
	m_lineType = PS_DASHDOTDOT;
}




void CGraphFinalExpView::OnSave()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CRect rect;
	BOOL  showMsgTag;                  //是否要弹出”图像保存成功对话框" 
	GetClientRect(&rect);                  //获取画布大小
	HBITMAP hbitmap = CreateCompatibleBitmap(dc, rect.right - rect.left, rect.bottom - rect.top);

	//创建兼容位图

	HDC hdc = CreateCompatibleDC(dc);      //创建兼容DC，以便将图像保存为不同的格式

	HBITMAP hOldMap = (HBITMAP)SelectObject(hdc, hbitmap);

	//将位图选入DC，并保存返回值 

	BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, dc, 0, 0, SRCCOPY);

	//将屏幕DC的图像复制到内存DC中
	CImage image;
	image.Attach(hbitmap);                //将位图转化为一般图像
	if (!saveTag)                          //如果图像是第一次被写入,则打开对话框
	{
		saveTag = TRUE;
		showMsgTag = TRUE;
		CString  strFilter = _T("位图文件(*.bmp)|*.bmp|JPEG 图像文件|*.jpg|GIF图像文件 | *.gif | PNG图像文件 | *.png |其他格式(*.*) | *.* || ");
			CFileDialog dlg(FALSE, _T("bmp"), _T("iPaint1.bmp"), NULL, strFilter);
		if (dlg.DoModal() != IDOK)
			return;
		CString strFileName;          //如果用户没有指定文件扩展名，则为其添加一个
		CString strExtension;
		strFileName = dlg.m_ofn.lpstrFile;
		if (dlg.m_ofn.nFileExtension = 0)               //扩展名项目为0
		{
			switch (dlg.m_ofn.nFilterIndex)
			{

			case 1:

				strExtension = "bmp"; break;

			case 2:

				strExtension = "jpg"; break;

			case 3:

				strExtension = "gif"; break;

			case 4:

				strExtension = "png"; break;

			default:

				break;

			}

			strFileName = strFileName + "." + strExtension;

		}

		saveFilePath = strFileName;     //saveFilePath为视类中的全局变量,类型为CString

	}

	else

	{

		showMsgTag = FALSE;

	}



	AfxMessageBox(saveFilePath);               //显示图像保存的全路径(包含文件名)

	HRESULT hResult = image.Save(saveFilePath);     //保存图像

	if (FAILED(hResult))

	{

		MessageBox(_T("保存图像文件失败！"));

	}

	else

	{

		if (showMsgTag)

			MessageBox(_T("文件保存成功！"));

	}

	image.Detach();

	SelectObject(hdc, hOldMap);

}

void CGraphFinalExpView::OnSetLinewidth()
{
	// TODO: 在此添加命令处理程序代码
	 lineWidth dia1;

	if (dia1.DoModal() == IDOK)
	{
		a = dia1.width;
	}
}
