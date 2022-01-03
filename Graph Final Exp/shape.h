#include <vector>
#pragma once
class CShape
{
protected:
	int lineType;//����
	int LineWidth;//�߿�
	COLORREF borderColor;//�߿���ɫ
	COLORREF fillColor;//�����ɫ
	CPoint startPoint;//�������
	CPoint endPoint;//�����յ�
	enum shapeType { UNSURE, LINE, RECTANGLE, ELLIPSE, CIRCLE, TRIANGLE, POLYGON, SEGMENTLINES };//��״����
	shapeType type;
public:
	CShape();
	CShape(int p_lineType, COLORREF p_borderColor, COLORREF p_fillColor, CPoint p_startPoint, CPoint p_endPoint,int p_LineWidth);
	virtual void draw(CDC* pDC) = 0;//��ͼ�������������о���ʵ��
	//set
	std::vector<CPoint> LineNode;
	int setLineType(int type) { return lineType = type; }
	COLORREF setBorderColor(COLORREF color) { return borderColor = color; }//���ñ߿���ɫ
	COLORREF setFillColor(COLORREF color) { return fillColor = color; }//���������ɫ
	int setLineWidth(int width) { LineWidth = width; }
	CPoint setStartPoint(CPoint point) { return startPoint = point; }//�������
	CPoint setEndPoint(CPoint point) { return endPoint = point; }//�����յ�	
	CPoint setLinePoint(CPoint point) { LineNode.push_back(point); return point; }//�����յ�
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
