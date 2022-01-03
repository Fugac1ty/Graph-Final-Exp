
// Graph Final ExpDoc.h: CGraphFinalExpDoc 类的接口
//


#pragma once

#include "shape.h"
#include <vector>
using namespace std;//vector需要

class CGraphFinalExpDoc : public CDocument
{
protected: // 仅从序列化创建
	CGraphFinalExpDoc() noexcept;
	DECLARE_DYNCREATE(CGraphFinalExpDoc)

// 特性
public:
	vector<CShape*> shapes;
// 操作
public:
	void setLineType(int type) { shapes.back()->setLineType(type); }
	void setBorderColor(COLORREF color) { shapes.back()->setBorderColor(color); }//设置边框颜色
	void setFillColor(COLORREF color) { shapes.back()->setFillColor(color); }//设置填充颜色
	void setEndPoint(CPoint point) { shapes.back()->setEndPoint(point); }
	void setLinePoint(CPoint point) { shapes.back()->setLinePoint(point); }
	//新增指向形状的指针
	void Move(CPoint DistanceShape) { shapes.back()->Move(DistanceShape); }
	void push_back(CShape* p_shape) { shapes.push_back(p_shape); }
	bool empty() { return shapes.empty(); }
	size_t size() { return shapes.size(); }
	void pop_back() { shapes.pop_back(); }
	int Square() { return shapes.back()->Square(); }
	int Length() { return shapes.back()->Length(); }
	//将存储的形状全画出来
	void draw(CDC* pDC);
	//清除整个画板
	void clear();
// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CGraphFinalExpDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
