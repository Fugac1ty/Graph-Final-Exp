#pragma once
#include "Shape.h"
class CAreaShape :
    virtual public CShape
{
protected:
    //COLORREF fillColor;//�����ɫ
public:
    //COLORREF setFillColor(COLORREF color) { return fillColor = color; }//���������ɫ
    //COLORREF getFillColor() { return fillColor; }
    //virtual int Length() { return 0; }
    //virtual int Square() { return 0; }
    int ThreePointSquare(CPoint point_1, CPoint point_2, CPoint point_3);//����������Χ�ɵ����
    int PointLine(CPoint point_1, CPoint point_2);//�������㳤��
    CPoint PointRevolve(CPoint point_1, CPoint point_2);//������point_1��point_2��ת90�Ⱥ�ĵ�
};
