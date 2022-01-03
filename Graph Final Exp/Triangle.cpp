#include "pch.h"
#include "Triangle.h"
#include "Shape.h"

int CTriangle::ShapeAmount = 0;//

CTriangle::CTriangle()
{

	setShapeType(TRIANGLE);

}
CTriangle::CTriangle(int p_lineType,
	COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint,
	int p_LineWidth) :
	CShape(p_lineType, p_borderColor, p_fillColor, p_startPoint, p_endPoint, p_LineWidth)
{
	ShapeAmount++;
	setShapeType(TRIANGLE);
}

void CTriangle::draw(CDC* pDC)
{
	;
	//������ʱ���ʣ����ڱ߿���ɫ
	CPen pen;
	pen.CreatePen(lineType, LineWidth, borderColor);
	pDC->SelectObject(&pen);//�ѻ���ѡ���豸
	//������ʱ��ˢ�����������ɫ
	CBrush brush;
	brush.CreateSolidBrush(fillColor);
	pDC->SelectObject(&brush);
	//����
	CPoint Pt[3];
	Pt[0] = CPoint(startPoint.x, endPoint.y);
	Pt[1] = CPoint((startPoint.x + endPoint.x) / 2, startPoint.y);
	Pt[2] = CPoint(endPoint.x, endPoint.y);
	pDC->Polygon(Pt, 3);
	//pDC->Ellipse(startPoint.x, startPoint.y, startPoint.x + endPoint.y - startPoint.y, endPoint.y);
	//ɾ����ʱ����
	pen.DeleteObject();
	brush.DeleteObject();
	//TRACE("%d %d %d %d", startPoint.x,startPoint.y, endPoint.x, endPoint.y);
	//TRACE("%d %d", Length(), Square());

}


int CTriangle::Square()
{
	return  (endPoint.x - startPoint.x) * (endPoint.y - startPoint.y) / 200;//Բ��������� �߳�1��10��
}

int CTriangle::Length()
{
	int h = abs(endPoint.y - startPoint.y);
	int d = abs((endPoint.x - startPoint.x) / 2);
	int l = sqrt(h * h + d * d);
	return (l + d) / 5;


}

void CTriangle::Revolve() {
	CPoint tempPoint;
	tempPoint = startPoint;
	startPoint = endPoint;
	endPoint = tempPoint;
}



CTriangle::~CTriangle()
{

}
