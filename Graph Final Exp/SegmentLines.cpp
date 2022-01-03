#include "pch.h"
#include "SegmentLines.h"


int CSegmentLines::ShapeAmount = 0;
CSegmentLines::CSegmentLines()
{
	setShapeType(SEGMENTLINES);
}
CSegmentLines::CSegmentLines(int p_lineType,
	COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint,
	int p_LineWidth) :
	CShape(p_lineType, p_borderColor, p_fillColor, p_startPoint, p_endPoint, p_LineWidth)
{
	ShapeAmount++;
	setShapeType(SEGMENTLINES);
}
void CSegmentLines::AddNode(CPoint TempNode) {
	LineNode.push_back(TempNode);

};


//@funcName <draw>
//@statement <�������ݻ���ͼ��>
//@parameter <�������豸������:CDC>
void CSegmentLines::draw(CDC* pDC)
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
	if (LineNode.empty()) {
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
	}
	//ɾ����ʱ����
	pen.DeleteObject();
	brush.DeleteObject();

}

int CSegmentLines::Length()
{
	int length = 0;
	if (LineNode.empty()) {
		length = PythagorenTheorem(startPoint, endPoint);
	}
	else {
		int i = 0;
		length = PythagorenTheorem(startPoint, LineNode[0]);

		for (i = 0; i < LineNode.size() - 1; i++) {
			length += PythagorenTheorem(LineNode[i], LineNode[i + 1]);
			TRACE("%d", length);

		}
		length += PythagorenTheorem(LineNode[i], endPoint);
		TRACE("%d", length);

	}
	return length;
}

int CSegmentLines::Node()
{
	return  getLineNode() + 2;//��
}

void CSegmentLines::Revolve() {
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



CSegmentLines::~CSegmentLines()
{

}
