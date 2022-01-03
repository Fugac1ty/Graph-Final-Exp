
#include "pch.h"
#include "Rectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif


int CRectangle::ShapeAmount = 0;

CRectangle::CRectangle()
{
	setShapeType(RECTANGLE);
}
CRectangle::CRectangle(int p_lineType,
	COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint,
	int p_LineWidth) :
	CShape(p_lineType, p_borderColor, p_fillColor, p_startPoint, p_endPoint,p_LineWidth)
{
	ShapeAmount++;
	setShapeType(RECTANGLE);
}
void CRectangle::draw(CDC* pDC)
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
	pDC->Rectangle(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
	//删除临时工具
	pen.DeleteObject();
	brush.DeleteObject();

}

int CRectangle::Square()
{
	return   abs((int(startPoint.x) - int(endPoint.x)) * abs((int(startPoint.y) - int(endPoint.y)))) / 100;
}

int CRectangle::Length()
{

	return   abs(abs((int(startPoint.x) - int(endPoint.x))) + abs((int(startPoint.y) - int(endPoint.y)))) / 10 * 2;

}
void CRectangle::Revolve() {
	CPoint midPoint;
	midPoint.x = (startPoint.x + endPoint.x) / 2;
	midPoint.y = (startPoint.y + endPoint.y) / 2;
	startPoint = PointRevolve(startPoint, midPoint);
	endPoint = PointRevolve(endPoint, midPoint);
}


CRectangle::~CRectangle()
{

}
