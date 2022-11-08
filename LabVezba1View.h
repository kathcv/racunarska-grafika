
// LabVezba1View.h : interface of the CLabVezba1View class
//

#pragma once


class CLabVezba1View : public CView
{
protected: // create from serialization only
	CLabVezba1View() noexcept;
	DECLARE_DYNCREATE(CLabVezba1View)

// Attributes
public:
	CLabVezba1Doc* GetDocument() const;
	int flag = 0;
// Operations
public:
	void DrawTriangle(CDC* pDC, POINT p1, POINT p2, POINT p3, COLORREF clr);
	void DrawCetvorougao(CDC* pDC, POINT p1, POINT p2, POINT p3, POINT p4, COLORREF clr);
	void DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle);
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CLabVezba1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // debug version in LabVezba1View.cpp
inline CLabVezba1Doc* CLabVezba1View::GetDocument() const
   { return reinterpret_cast<CLabVezba1Doc*>(m_pDocument); }
#endif

