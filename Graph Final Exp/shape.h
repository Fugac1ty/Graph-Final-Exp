#include <vector>
#pragma once
class CShape
{
protected:
	int lineType;//线性
	int LineWidth;//线宽
	COLORREF borderColor;//边框颜色
	COLORREF fillColor;//填充颜色
	CPoint startPoint;//绘制起点
	CPoint endPoint;//绘制终点
	enum shapeType { UNSURE, LINE, RECTANGLE, ELLIPSE, CIRCLE, TRIANGLE, POLYGON, SEGMENTLINES };//形状类型
	shapeType type;
public:
	CShape();
	CShape(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint,int p_LineWidth);
	virtual void draw(CDC* pDC) = 0;//绘图函数，在子类中具体实现
	//set
	std::vector<CPoint> LineNode;
	int setLineType(int type) { return lineType = type; }
	COLORREF setBorderColor(COLORREF color) { return borderColor = color; }//设置边框颜色
	COLORREF setFillColor(COLORREF color) { return fillColor = color; }//设置填充颜色
	int setLineWidth(int width) { LineWidth = width; }
	CPoint setStartPoint(CPoint point) { return startPoint = point; }//设置起点
	CPoint setEndPoint(CPoint point) { return endPoint = point; }//设置终点	
	CPoint setLinePoint(CPoint point) { LineNode.push_back(point); return point; }//设置终点
	shapeType setShapeType(shapeType p_type) { return type = p_type; }
	//get
	int getLineType() { return lineType; }
	COLORREF getBorderColor() { return borderColor; }
	COLORREF getFillColor() { return fillColor; }
	CPoint getStartPoint() { return startPoint; }
	CPoint getEndPoint() { return endPoint; }
	shapeType getShapeType() { return type; }
	void AddNode(CPoint TempNode) {};
	void Move(CPoint PointDistance);
	int getLineNode() { return LineNode.size(); }
	virtual void Revolve() {};
	virtual int Square() { return 0; };
	virtual int Length() { return 0; };
	virtual int Node() { return 0; };
	virtual ~CShape();

};
