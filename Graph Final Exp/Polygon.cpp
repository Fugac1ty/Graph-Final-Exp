#include "pch.h"
#include "Polygon.h"
int CPolygon::ShapeAmount = 0;
CPolygon::CPolygon()
{
	setShapeType(POLYGON);
}
CPolygon::CPolygon(int p_lineType,
	COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint,
	int p_LineWidth) :
	CShape(p_lineType, p_borderColor, p_fillColor, p_startPoint, p_endPoint, p_LineWidth)
{
	ShapeAmount++;
	setShapeType(POLYGON);
}
void CPolygon::AddNode(CPoint TempNode) {
	LineNode.push_back(TempNode);

};


//@funcName <draw>
//@statement <�������ݻ���ͼ��>
//@parameter <�������豸������:CDC>
void CPolygon::draw(CDC* pDC)
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
	/*if (LineNode.empty()) {
		pDC->MoveTo(startPoint);
		pDC->LineTo(endPoint);
	}
	else {
		int i = 0;
		pDC->MoveTo(startPoint);
		pDC->LineTo(LineNode[0]);
		for (i = 0; i < LineNode.size() - 1; i++) {
			pDC->MoveTo(LineNode[i]);
			pDC->LineTo(LineNode[i + 1]);
		}
		pDC->MoveTo(LineNode[i]);
		pDC->LineTo(endPoint);
		pDC->MoveTo(endPoint);
		pDC->LineTo(startPoint);
	}*/

	std::vector<CPoint> AllPoint(LineNode);				//�ñ������Դ�������ȫ������
	AllPoint.insert(AllPoint.begin(), startPoint);
	AllPoint.push_back(endPoint);
	pDC->Polygon(&AllPoint[0], AllPoint.size());

	//ɾ����ʱ����
	pen.DeleteObject();
	brush.DeleteObject();

}


int CPolygon::Length() {
	int i, l = 0;
	l = PointLine(startPoint, LineNode[0]);
	for (i = 0; i < LineNode.size() - 1; i++) {
		l += PointLine(LineNode[i], LineNode[i + 1]);
	}
	l += PointLine(LineNode[i], endPoint);
	l += PointLine(endPoint, startPoint);
	return l;
}
int CPolygon::Square() {
	int i, s = 0;
	if (LineNode.size() >= 3) {
		s = ThreePointSquare(startPoint, LineNode[0], LineNode[1]);
		TRACE("s=%d ", s);
		for (i = 0; i < LineNode.size() - 2; i++) {
			s += ThreePointSquare(LineNode[i], LineNode[i + 1], LineNode[i + 2]);
		}
		s += ThreePointSquare(LineNode[i], startPoint, endPoint);
	}
	else if (LineNode.size() == 0) {
		s = 0;
	}
	else if (LineNode.size() == 1) {
		s = ThreePointSquare(startPoint, LineNode[0], endPoint);
	}
	else if (LineNode.size() == 2) {
		s = ThreePointSquare(startPoint, LineNode[0], LineNode[1]) + ThreePointSquare(startPoint, LineNode[1], endPoint);
	}
	return s;
}

void CPolygon::Revolve() {
	CPoint midPoint, sumPoint;
	sumPoint.x = startPoint.x + endPoint.x;
	sumPoint.y = startPoint.y + endPoint.y;
	for (int i = 0; i < (LineNode.size()); i++) {
		sumPoint.x = sumPoint.x + LineNode[i].x;
		sumPoint.y = sumPoint.y + LineNode[i].y;

	}
	midPoint.x = sumPoint.x / (2 + LineNode.size());
	midPoint.y = sumPoint.y / (2 + LineNode.size());
	startPoint = PointRevolve(startPoint, midPoint);
	endPoint = PointRevolve(endPoint, midPoint);
	for (int i = 0; i < LineNode.size(); i++) {
		LineNode[i] = PointRevolve(LineNode[i], midPoint);
	}
}



CPolygon::~CPolygon()
{

}