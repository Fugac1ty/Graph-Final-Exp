#pragma once
#include "AreaShape.h"
class CTriangle :
	public CAreaShape
{
public:
	static int ShapeAmount;//��������ͳ������
	CTriangle();
	CTriangle(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint, int p_LineWidth);
	CTriangle(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint);
	void draw(CDC* pDC);
	virtual int Length();
	virtual int Square();
	virtual void Revolve();
	virtual ~CTriangle();
};

