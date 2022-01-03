
#include "pch.h"
#include "Ellipse.h"
#include "Shape.h"

int CEllipse::ShapeAmount = 0;//

CEllipse::CEllipse()
{

	setShapeType(ELLIPSE);

}
CEllipse::CEllipse(int p_lineType,
	COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint,
	int p_LineWidth) :
	CShape(p_lineType, p_borderColor, p_fillColor, p_startPoint, p_endPoint,p_LineWidth)
{
	ShapeAmount++;
	setShapeType(ELLIPSE);
}


void CEllipse::draw(CDC* pDC)
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
	pDC->Ellipse(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
	//ɾ����ʱ����
	pen.DeleteObject();
	brush.DeleteObject();
	//TRACE("%d %d %d %d", startPoint.x,startPoint.y, endPoint.x, endPoint.y);
	//TRACE("%d %d", Length(),Square());
}


int CEllipse::Square()
{
	return  3.14 * abs((int(startPoint.x) - int(endPoint.x)) * (int(startPoint.y) - int(endPoint.y))) / 400;//��Բ������� �߳�1��10��
}

int CEllipse::Length()
{
	int a = (int(startPoint.x) - int(endPoint.x)) / 2;
	int b = (int(startPoint.y) - int(endPoint.y)) / 2;
	int temp;
	if (a < b) { temp = a; a = b; b = temp; }
	return (2 * 3.14 * b + (a - b) * 4) / 10;


}


void CEllipse::Revolve() {
	CPoint midPoint;
	midPoint.x = (startPoint.x + endPoint.x) / 2;
	midPoint.y = (startPoint.y + endPoint.y) / 2;
	startPoint = PointRevolve(startPoint, midPoint);
	endPoint = PointRevolve(endPoint, midPoint);
}

CEllipse::~CEllipse()
{

}
