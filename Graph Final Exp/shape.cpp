
#include "pch.h"
#include "Shape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif


CShape::CShape() :
	lineType(PS_SOLID),//ֱ��
	LineWidth(1),//�߿�Ĭ��Ϊ1
	borderColor(RGB(0, 0, 0)),//Ĭ�Ϻ�ɫ
	fillColor(RGB(255, 255, 255)),//Ĭ�ϰ�ɫ
	startPoint(100, 100),//�޹ؽ�Ҫ��Ĭ��ֵ
	endPoint(200, 200),
	type(UNSURE)
{

}

CShape::CShape(int p_lineType,
	COLORREF p_borderColor,
	COLORREF p_fillColor,
	CPoint p_startPoint,
	CPoint p_endPoint,
	int p_LineWidth) 
	:
	LineWidth(p_LineWidth),
	lineType(p_lineType),
	borderColor(p_borderColor),
	fillColor(p_fillColor),
	startPoint(p_startPoint),
	endPoint(p_endPoint),
	type(UNSURE)
{

}

void CShape::Move(CPoint PointDistance) {
	startPoint.x = startPoint.x + PointDistance.x;
	startPoint.y = startPoint.y + PointDistance.y;
	endPoint.x = endPoint.x + PointDistance.x;
	endPoint.y = endPoint.y + PointDistance.y;
	for (int i = 0; i < LineNode.size(); i++) {
		LineNode[i].x = LineNode[i].x + PointDistance.x;
		LineNode[i].y = LineNode[i].y + PointDistance.y;

	}
}

CShape::~CShape()
{

}
