#pragma once
#include<vector>
class DrawMode//基类，定义了大部分共用接口
{
public:
	virtual int drag(CDC* pDC, int oldx, int oldy, int newx, int newy, COLORREF color);//实现橡皮线功能的函数
	virtual int update(CDC* pDC, int x, int y, COLORREF color);//鼠标左键点击调用的函数
	virtual int draw(CDC* pDC, int startx, int starty, int endx, int endy, COLORREF color) = 0;//绘制单个图元的函数
	std::vector<int>lastx;//记录鼠标的点击点
	std::vector<int>lasty;//
	virtual bool isOver();//指示这次绘制是否结束
};

