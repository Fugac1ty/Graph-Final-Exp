
#include "pch.h"
#include "Line.h"
#include "Shape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

int CLine::ShapeAmount = 0;

CLine::CLine()
{
	setShapeType(LINE);
}
CLine::CLine(int p_lineType,
	COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint,
	int p_LineWidth) :
	CShape(p_lineType, p_borderColor, p_fillColor, p_startPoint, p_endPoint, p_LineWidth)
{
	ShapeAmount++;
	setShapeType(LINE);
}


void CLine::draw(CDC* pDC)
{
	//创建临时画笔，用于边框颜色
	CPen pen;
	pen.CreatePen(lineType, LineWidth, borderColor);
	pDC->SelectObject(&pen);//把画笔选入设备
	//创建临时画刷，用于填充颜色
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	pDC->SelectObject(&brush);
	//绘制
	pDC->MoveTo(startPoint);
	pDC->LineTo(endPoint);
	//删除临时工具
	pen.DeleteObject();
	brush.DeleteObject();

}
void CLine::Revolve() {
	CPoint midPoint;
	midPoint.x = (startPoint.x + endPoint.x) / 2;
	midPoint.y = (startPoint.y + endPoint.y) / 2;
	startPoint = PointRevolve(startPoint, midPoint);
	endPoint = PointRevolve(endPoint, midPoint);
}

int CLine::Length()
{
	return  PythagorenTheorem(startPoint, endPoint);//；
}

int CLine::Node()
{
	return  getLineNode() + 2;//；
}


CLine::~CLine()
{

}
