
// LabVezba1View.cpp : implementation of the CLabVezba1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LabVezba1.h"
#endif

#include "LabVezba1Doc.h"
#include "LabVezba1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLabVezba1View

IMPLEMENT_DYNCREATE(CLabVezba1View, CView)

BEGIN_MESSAGE_MAP(CLabVezba1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CLabVezba1View construction/destruction

CLabVezba1View::CLabVezba1View() noexcept
{
	// TODO: add construction code here

}

CLabVezba1View::~CLabVezba1View()
{
}

BOOL CLabVezba1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CLabVezba1View drawing

void CLabVezba1View::DrawTriangle(CDC* pDC, POINT p1, POINT p2, POINT p3, COLORREF clr)
{
	POINT tacke[] = { p1, p2, p3 };
	CBrush cetkica(clr);
	CBrush *stara=pDC->SelectObject(&cetkica);
	pDC->Polygon(tacke, 3);
	pDC->SelectObject(&stara);
	DeleteObject(cetkica);
	
}

void CLabVezba1View::DrawCetvorougao(CDC* pDC, POINT p1, POINT p2, POINT p3, POINT p4, COLORREF clr)
{
	POINT tacke[] = { p1,p2,p3,p4 };
	CBrush cetkica(clr);
	CBrush* stara = pDC->SelectObject(&cetkica);
	pDC->Polygon(tacke, 4);
	pDC->SelectObject(&stara);
	DeleteObject(cetkica);
}

void CLabVezba1View::DrawRegularPolygon(CDC* pDC, int cx, int cy, int r, int n, float rotAngle)
{
	CPen olovka(PS_SOLID, 3, RGB(255, 0, 255));
	CPen* prethodna = pDC->SelectObject(&olovka);
	pDC->SelectStockObject(NULL_BRUSH);
	float ugao = 2 * 3.1415926535 / n;
	POINT* tacke = new POINT[n];
	for (int i = 0; i < n; i++) {
		tacke[i].x = cx + r * cos(ugao * i + rotAngle);
		tacke[i].y = cy + r * sin(ugao * i + rotAngle);
	}
	pDC->Polygon(tacke, n);
}

void CLabVezba1View::OnDraw(CDC* pDC)
{
	CLabVezba1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CBrush background(RGB(220, 220, 220));
	CBrush* old = pDC->SelectObject(&background);
	CRect bck(0, 0, 500, 500);
	pDC->Rectangle(&bck);

	CPen slika(PS_SOLID, 5, RGB(255, 0, 255));
	pDC->SelectObject(&slika);
	CBrush srafura;
	srafura.CreateHatchBrush(HS_HORIZONTAL, RGB(0, 0, 255));
	pDC->SelectObject(&srafura);
	POINT tacke[] = { { 15,145 }, { 95,70 }, { 170,145 } };
	pDC->Polygon(tacke, 3);
	DrawTriangle(pDC, { 170,215 }, { 380,215 }, { 275,315 }, RGB(0, 255, 0)); //green 
	DrawTriangle(pDC, { 325,265 }, { 420,170 }, { 420,360 }, RGB(255, 0, 0)); //red
	DrawTriangle(pDC, {265,425}, {345,425}, {345,345}, RGB(128,0,128 )); //purple
	DrawTriangle(pDC, { 420,320 }, {470 ,375 }, {420 ,430 }, RGB(255,192 ,203 )); //pastel pink
	DrawCetvorougao(pDC, {95,145}, {170,145},  {245,215}, { 170,215 }, RGB(255, 255, 0)); //yellow
	DrawCetvorougao(pDC, {275,315}, {325,265}, {375,315}, {325,365}, RGB(255,165,0)); //orange

	DrawRegularPolygon(pDC, 95, 115, 15, 5, 0);
	DrawRegularPolygon(pDC, 270, 255, 20, 4, 0);
	DrawRegularPolygon(pDC, 385, 260, 20, 6, 0);
	DrawRegularPolygon(pDC, 440, 375, 10, 7, 0);
	DrawRegularPolygon(pDC, 320, 400, 15, 8, 0);

	if (flag == 1) {
		CPen grid(PS_SOLID, 1, RGB(210, 210, 210));
		pDC->SelectObject(&grid);
		int j = 0;
		while (j <= 500) {
			pDC->MoveTo(0, j);
			pDC->LineTo(500, j);
			j += 25;
		}
		int i = 0;
		while (i <= 500) {
			pDC->MoveTo(i, 0);
			pDC->LineTo(i, 500);
			i += 25;
		}
	}
}


// CLabVezba1View printing

BOOL CLabVezba1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLabVezba1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLabVezba1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CLabVezba1View diagnostics

#ifdef _DEBUG
void CLabVezba1View::AssertValid() const
{
	CView::AssertValid();
}

void CLabVezba1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLabVezba1Doc* CLabVezba1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLabVezba1Doc)));
	return (CLabVezba1Doc*)m_pDocument;
}
#endif //_DEBUG


// CLabVezba1View message handlers


void CLabVezba1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == 'K') {
		if (flag == 0)
			flag = 1;
		else
			flag = 0;
		Invalidate();
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
