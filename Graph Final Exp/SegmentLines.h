#pragma once
#include <vector>
#include "LineShape.h"
#include "Shape.h"

class CSegmentLines :virtual public CLineShape

{
public:
	static int ShapeAmount;
	//std::vector<CPoint> LineNode; //����vector���ڴ���ڵ�


	CSegmentLines();
	CSegmentLines(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint, int p_LineWidth);
	CSegmentLines(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint);
	void draw(CDC* pDC);
	void AddNode(CPoint TempNode);
	virtual int Length();
	virtual int Node();
	virtual void Revolve();
	virtual ~CSegmentLines();
};

