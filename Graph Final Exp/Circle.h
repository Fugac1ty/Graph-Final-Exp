#pragma once
#include "AreaShape.h"
class CCircle :
	public CAreaShape
{
public:
	static int ShapeAmount;//变量用以统计数量
	CCircle();
	CCircle(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint, int p_LineWidth);
	void draw(CDC* pDC);
	virtual int Length();
	virtual int Square();
	virtual ~CCircle();
};

