#include "pch.h"
#include "Circle.h"
#include "Shape.h"

int CCircle::ShapeAmount = 0;//

CCircle::CCircle()
{
	setShapeType(CIRCLE);

}
CCircle::CCircle(int p_lineType,
	COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint,
	int p_LineWidth ):
	CShape(p_lineType, p_borderColor, p_fillColor, p_startPoint, p_endPoint,p_LineWidth)
{
	ShapeAmount++;
	setShapeType(CIRCLE);
}


void CCircle::draw(CDC* pDC)
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

	pDC->Ellipse(startPoint.x, startPoint.y, startPoint.x + endPoint.y - startPoint.y, endPoint.y);
	//ɾ����ʱ����
	pen.DeleteObject();
	brush.DeleteObject();


}


int CCircle::Square()
{
	return  3.14 * (endPoint.x - startPoint.x) * (endPoint.x - startPoint.x) / 400;//Բ��������� �߳�1��10��
}

int CCircle::Length()
{
	return 3.14 * abs(endPoint.x - startPoint.x) / 10;


}





CCircle::~CCircle()
{

}
