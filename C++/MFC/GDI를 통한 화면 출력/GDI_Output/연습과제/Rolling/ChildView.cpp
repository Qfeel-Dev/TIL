
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Rolling.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView():m_sflag(false)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.


	if (m_sflag == false)
	{

		CRect rect;

		GetClientRect(rect);

		CFont font;
		font.CreatePointFont(100, _T("궁서체"));

		dc.SelectObject(&font);
		dc.DrawText(_T("클릭하시면 공이 움직입니다."), rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);


		m_point = rect.BottomRight();

		dc.Ellipse(m_point.x, m_point.y, m_point.x - 30, m_point.y - 30);
		m_sflag = true;
	}
	else
	{
		dc.Ellipse(m_point.x, m_point.y, m_point.x - 30, m_point.y - 30);
	}

	m_point.x -= 5;

	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}




void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	
	Invalidate(true);
	
	//Invalidate(true);

	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnLButtonDown(nFlags, point);
}
