
// Graph Final ExpView.h: CGraphFinalExpView 类的接口
//

#pragma once


class CGraphFinalExpView : public CView
{
protected: // 仅从序列化创建
	CGraphFinalExpView() noexcept;
	DECLARE_DYNCREATE(CGraphFinalExpView)

// 特性
public:
	CGraphFinalExpDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CGraphFinalExpView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_lineType;
	COLORREF m_borderColor;//边框颜色
	COLORREF m_fillColor;//填充颜色
	int a;
	enum shapeType { UNSURE, LINE, RECTANGLE, ELLIPSE, CIRCLE, TRIANGLE, POLYGON, SEGMENTLINES };//形状类型
	shapeType m_shapeType;
	//状态
	int m_shapeState;//1为画图，2为移动，3为旋转
	int m_drawState;//1为正在画，0为没在画
	CPoint LastMousePoint;//改变了用以移动中记录上次鼠标位子
// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
//	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnShapeEllipse();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnShapeMove();
	afx_msg void OnShapeRevolve();
	afx_msg void OnShapeDraw();
	afx_msg void OnShapeLine();
	afx_msg void OnShapeSegmentlines();
	afx_msg void OnShapePolygon();
	afx_msg void OnShapeRectangle();
	afx_msg void OnShapeCircle();
	afx_msg void OnBoredColor();
	afx_msg void OnFillColor();
	afx_msg void OnClear();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLinetypeSolid();
	afx_msg void OnLinetypeDash();
	afx_msg void OnLinetypeDot();
	afx_msg void OnLinetypeDashdot();
	afx_msg void OnLinetypeDashdotdot();
	afx_msg void OnSave();
	afx_msg void OnSetLinewidth();
};

#ifndef _DEBUG  // Graph Final ExpView.cpp 中的调试版本
inline CGraphFinalExpDoc* CGraphFinalExpView::GetDocument() const
   { return reinterpret_cast<CGraphFinalExpDoc*>(m_pDocument); }
#endif

