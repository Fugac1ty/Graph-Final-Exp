
#include "pch.h"
#include "AreaShape.h"

int CAreaShape::ThreePointSquare(CPoint point_1, CPoint point_2, CPoint point_3) {
	int temp = abs(point_1.x * point_2.y + point_2.x * point_3.y + point_3.x * point_1.y - point_2.x * point_1.y - point_3.x * point_2.y - point_1.x * point_3.y) / 100 / 2;
	//TRACE("d");
	return temp;
}//����������Χ�ɵ����

CPoint CAreaShape::PointRevolve(CPoint point_1, CPoint point_2) {
	CPoint tempPoint, resultPoint;
	tempPoint.x = point_1.x - point_2.x;
	tempPoint.y = point_1.y - point_2.y;
	resultPoint.x = point_2.x - tempPoint.y;
	resultPoint.y = point_2.y + tempPoint.x;
	return resultPoint;


}

int CAreaShape::PointLine(CPoint point_1, CPoint point_2) {
	return sqrt((point_1.x - point_2.x) * (point_1.x - point_2.x) + (point_1.y - point_2.y) * (point_1.y - point_2.y)) / 10;
}//�������㳤��