
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
	//������ʱ���ʣ����ڱ߿���ɫ
	CPen pen;
	pen.CreatePen(lineType, LineWidth, borderColor);
	pDC->SelectObject(&pen);//�ѻ���ѡ���豸
	//������ʱ��ˢ�����������ɫ
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	pDC->SelectObject(&brush);
	//����
	pDC->Rectangle(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
	//ɾ����ʱ����
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
