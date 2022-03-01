
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "IO_Eventhandler.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView():m_draw(false),m_mousein(false)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
//	ON_WM_LBUTTONDBLCLK()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()

//처음은 플래그값 -- 비트 마스크 값 - 특정 키보드와 마우스가 같이 눌렸을 겨우
//

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

	//CRect rect;
	//GetClientRect(rect);
	//dc.SelectStockObject(BLACK_BRUSH);
	//dc.Rectangle(rect);

	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}


//클라이언트 영역에서의 마우스 메시지 - 좌표는 픽셀단위로 들어옴
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//if (nFlags & MK_SHIFT) {//SHIFT 키가 눌러진 상태에서 LBTN이 실행되었다면
	//nFlagse 는 메시지가 생성될때 마우스, 키보드의 상태를 나타내는 비트 마스크
	//}
	/*
	CClientDC dc(this); 
	dc.SetROP2(R2_NOT);//그리기 모드 변경
	dc.Rectangle(point.x - 50, point.y - 50, point.x + 50, point.y + 50);
	*/
	m_draw = true;
	m_start = m_end = point;

	SetCapture();//마우스 캡쳐 시작 -> 캡쳐시 마우스 커서의 위치에 상관없이 마우스 메시지를 받음
	

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	m_draw = false;
	m_end = point;

	CClientDC dc(this);
	dc.Ellipse(CRect(m_start, m_end));

	ReleaseCapture();//마우스 캡쳐  종료
	//GetCapture 어느 윈도우가 캡처를 하고 있는지 알아낸다

	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	/*
	if(m_draw){

		CClientDC dc(this);
		dc.SelectStockObject(NULL_BRUSH);
		dc.SetROP2(R2_NOT);
		dc.Ellipse(CRect(m_start, m_end));

		m_end = point;
		dc.Ellipse(CRect(m_start, m_end));
	}
	*/

	if (m_mousein == false) {
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.dwFlags = TME_LEAVE;
		tme.dwHoverTime = HOVER_DEFAULT;
		tme.hwndTrack = this->m_hWnd;		
		TrackMouseEvent(&tme);
		CRect rect;
		AfxGetMainWnd()->GetWindowRect(rect);
		rect.right = rect.left + 300;
		rect.bottom = rect.top + 300;
		AfxGetMainWnd()->MoveWindow(rect);
		m_mousein = true;
		//GetWindowRect(&rect);
	}
	CWnd::OnMouseMove(nFlags, point);
}
//마우스 캡처 - 마우스  커서의 위치에 ㅅ ㅏㅇ관없이 마우스 메시지를 받을 수 있따,

void CChildView::OnMouseLeave()
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CRect rect;
	AfxGetMainWnd()->GetWindowRect(rect);
	rect.right = rect.left + 200;
	rect.bottom = rect.top + 200;
	m_mousein = false;
	AfxGetMainWnd()->MoveWindow(rect);

	CWnd::OnMouseLeave();
}
