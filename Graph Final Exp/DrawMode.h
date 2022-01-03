#pragma once
#include<vector>
class DrawMode//���࣬�����˴󲿷ֹ��ýӿ�
{
public:
	virtual int drag(CDC* pDC, int oldx, int oldy, int newx, int newy, COLORREF color);//ʵ����Ƥ�߹��ܵĺ���
	virtual int update(CDC* pDC, int x, int y, COLORREF color);//������������õĺ���
	virtual int draw(CDC* pDC, int startx, int starty, int endx, int endy, COLORREF color) = 0;//���Ƶ���ͼԪ�ĺ���
	std::vector<int>lastx;//��¼���ĵ����
	std::vector<int>lasty;//
	virtual bool isOver();//ָʾ��λ����Ƿ����
};

