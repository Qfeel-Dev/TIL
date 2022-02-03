
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "GDI_Output.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	:m_flag(false)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CChildView 메시지 처리기
//invalidate - true  : 뒷배경 초기화
//invalidate - false : 뒷배경 초기화하지 않음


/*
출력 방법 비교

SDK 
- (클래스 없음)
- DC 객체 요청
- DC 핸들을 사용하여 출력을 한다
- DC 사용을 중지하여 객체 삭제(필수)

MFC
- (클래스 있음 - 삭제 자동)
- DC객체 생성 
- 객체의 멤버 함수를 호출하여 출력한다

DC 종류 - CDC 클래스 파생
- CPaintDC : 클라이언트 영역에 출력 - WM_PAINT(ON_PAINT)에만 사용
- CClientDC : 클라이언트 영역에 출력 - WM_PAINT에는 출력 못 함
- CWindoeDC : 전체 영역에 출력 가능
- CMetaFiledDC : 메타 파일에 출력 - 파일에다가 출력명령을 저장해놓고 그것을 실행시켜 화면에 그려주는?

*/


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
	//DC생성 CChildeView 객체
	/*
	CRect rect;
	GetClientRect(rect);

	dc.MoveTo(rect.left,rect.top);
	dc.LineTo(rect.right, rect.bottom);

	dc.LineTo(rect.right, rect.top);
	dc.LineTo(rect.left, rect.bottom);
	*/
	//wm_timer
	/*
	for (int x = 0; x < 255; x++)
	{
		for (int y = 0; y < 255; y++)
		{
			
			dc.SetPixelV(x, y, RGB(x, y, 0));
		}
	}*/


	/*
	화면의 크기 정보 활용
	클라이언트 영역이 사각형 이기때문에 사각형 정보가 필요
	*/
	//CRect rect;
	//GetClientRect(rect);//클라이언트의 사각형 창 크기 정보를 가져오는 함수 = 매개변수에다가
	//dc.Rectangle(rect);//클라이언트 크기의 사각형을 그려라!
	//dc.Ellipse(rect);
	//CPoint pt = rect.CenterPoint();//중앙 좌표값을 리턴하는 함수
	//dc.Ellipse(pt.x - 50, pt.y - 50, pt.x + 50, pt.y + 50);//중앙에 반지름이 50인 원을 그리기

	//최소화 -> 최대화 시 wm_paint 메시지 발생

	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);//그리는 놈

	if (m_flag == false) 
	{
		b_point= point;
		
		m_flag = true;
	}

	else 
	{
		dc.MoveTo(b_point);
		dc.LineTo(point);
		m_flag = false;
	}


//	COLORREF color = dc.GetPixel(point);
//	TRACE("r %d g %d b %d",GetRValue(color), GetGValue(color), GetBValue(color));
/*	dc.Ellipse(point.x-20, point.y - 20, point.x +20, point.y+ 20);
	m_flag = true;
	
	CWnd *pt = GetDesktopWindow();

	CWindowDC dc2(pt);
	dc2.FillSolidRect(CRect(100, 100, 300, 300), RGB(50, 30, 20));

	Invalidate(true);//false 시 이레이즈 백 그라운드 실행 x
*/
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_flag = false;

	Invalidate(true);
	CWnd::OnRButtonDown(nFlags, point);
}


BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_flag == true) { pDC->TextOutW(10, 10, _T("홍길동")); return true; }
	else return CWnd::OnEraseBkgnd(pDC);//윈도우 창을 모두 지운다}

	
	
	//
	//무효영역 생성! -> 이레이즈백그라운드 -> 온페인트
}
