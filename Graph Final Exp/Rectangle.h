#pragma once
#include"AreaShape.h"
class CRectangle :virtual public CAreaShape
{
public:
	static int ShapeAmount;
	CRectangle();
	CRectangle(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint, int p_LineWidth);
	CRectangle(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint);
	void draw(CDC* pDC);
	virtual int Length();
	virtual int Square();
	virtual void Revolve();
	virtual ~CRectangle();

};