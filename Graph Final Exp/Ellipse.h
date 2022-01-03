#include "AreaShape.h"
#include "Shape.h"

class CEllipse :virtual public CAreaShape
{
public:
	static int ShapeAmount;//��������ͳ������
	CEllipse();
	CEllipse(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint, int p_LineWidth);
	void draw(CDC* pDC);
	virtual int Length();
	virtual int Square();
	virtual void Revolve();
	virtual ~CEllipse();

};
