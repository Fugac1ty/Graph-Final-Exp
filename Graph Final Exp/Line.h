#include "LineShape.h"

class CLine :virtual public CLineShape
{
public:
	static int ShapeAmount;
	CLine();
	CLine(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint, int p_LineWidth);
	CLine(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint);
	void draw(CDC* pDC);
	virtual void Revolve();
	virtual int Length();
	virtual int Node();
	virtual ~CLine();

};
