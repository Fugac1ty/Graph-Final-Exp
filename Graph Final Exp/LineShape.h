
#include "pch.h"
#include "AreaShape.h"
#pragma once
class CLineShape :
	virtual public CShape
{
public:
	CPoint PointRevolve(CPoint point_1, CPoint point_2);//������point_1��point_2��ת90�Ⱥ�ĵ�
	int PythagorenTheorem(CPoint point_1, CPoint point_2);//���ɶ���
	int getNode() {}
};

