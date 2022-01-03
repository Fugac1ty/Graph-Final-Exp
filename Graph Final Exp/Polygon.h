#pragma once
#include "AreaShape.h"

class CPolygon :
	public CAreaShape
{
public:
	static int ShapeAmount;
	//std::vector<CPoint> LineNode; //����vector���ڴ���ڵ�


	CPolygon();
	CPolygon(int p_lineType);
	CPolygon(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint,int p_LineWidth);
	virtual int Length();
	virtual int Square();
	virtual void Revolve();
	void draw(CDC* pDC);
	void AddNode(CPoint TempNode);
	virtual ~CPolygon();
};

