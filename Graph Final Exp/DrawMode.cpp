#include "pch.h"
#include "DrawMode.h"

int DrawMode::drag(CDC* pDC, int oldx, int oldy, int newx, int newy, COLORREF color)
{
	pDC->SetROP2(R2_NOTXORPEN);//���û�ͼģʽΪR2_NOTXORPEN
	this->draw(pDC, lastx.back(), lasty.back(), oldx, oldy, color);
	this->draw(pDC, lastx.back(), lasty.back(), newx, newy, color);
	return 0;
}

int DrawMode::update(CDC* pDC, int x, int y, COLORREF color)
{
	if (!isOver())
	{
		this->draw(pDC, lastx.back(), lasty.back(), x, y, color);
	}
	lastx.push_back(x);
	lasty.push_back(y);
	return 0;
}


bool DrawMode::isOver()//��ʾ�Ƿ��ڻ滭�У���������������Ļ�����false
{
	return lastx.size() % 2 == 0;
}
