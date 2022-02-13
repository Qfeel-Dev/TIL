
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Utility.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView() :m_mouseIn(FALSE), rect(200, 200, 400, 400)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
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

	//배열 사용시 CArray = 배열 크기가 가변적입니다! - afxtempl.h
	//비 템플릿 클래스도 있음!! ex| CStringArray 
	


	/*
	빙글빙글돌아가는 현재 시간을 CLIENT 창의 표시하는 프로그램 + ONCREATE,ONDESTROY,ONSIZE,ONTIMER
	CTime ctime = CTime::GetCurrentTime();
	CString str;
	str.Format(_T("%2d시 %2d분 %2d초"), 
		ctime.GetHour(), 
		ctime.GetMinute(), 
		ctime.GetSecond());

	
	dc.DrawText(str, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//dc가 화면 중간에 문자열 name을 표시
	*/

	//클래스의 스태틱 멤버 변수,함수 - 객체를 따로 만들 필요 없고, *여러 객체들이 공용으로 사용할 경우*


	/*
	CRect,CPoint 내용 - 구조체 였던 것
	마우스가 원,사각형 안에 들어왔을때 색상을 변경하는 프로그램 + MouseMove

	사각형이 아닌 다른 도형일 경우 crgn,brush 클래스 활용 필요 + 부분이기 때문에 invalidate
	
	CBrush brush;
	
	if (m_mouseIn == TRUE) {
		//dc.FillSolidRect(rect, RGB(255, 0, 0));
		brush.CreateSolidBrush(RGB(255, 0, 0));

	}
	else {
		//dc.FillSolidRect(rect, RGB(0, 0, 255));
		brush.CreateSolidBrush(RGB(0, 0, 255));
	}

	dc.SelectObject(&brush);

	dc.Ellipse(rect);
	
	//리전 렉트가 아니여도 들어왔는지 확인가능
	*/


	/*
	CString 내용 정리

	가변 길이 문자열 지원 -> lpctstr 대신 사용 가능 -> cout으론 출력 무리무리(형변환 해야함)
	mfc에서 출력되는 모든건 스트링 이다...

	CString name;//문자열 객체
	name.LoadStringW(IDS_NAME);//문자열을 리소스에서 불러와서 객체에 할당
	CRect rect;//사각형 객체
	GetClientRect(&rect);//클라이언트 크기(사각형 정보)를 rect 객체에 전달
	CFont font;//폰트 객체
	font.CreatePointFont(100, _T("궁서체"));//사용할 폰트의 크기와 체를 선택
	dc.SelectObject(&font);//dc에게 사용할 폰트 정보를 전달

	dc.DrawText(name, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//dc가 화면 중간에 문자열 name을 표시
	*/
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}


/*
void CChildView::OnMouseMove(UINT nFlags, CPoint point)//프레임 워크는 마우스 커서가 이동할 때 이 멤버 함수를 호출 합니다.
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	CRgn rgn;//사각형이 아닌 다른 도형을 활용할 경우 rgn을 사용한다
	rgn.CreateEllipticRgnIndirect(rect);//기존 사각형 정보가지고 원 구역을 생성


	if (rgn.PtInRegion(point)) {//사각형 안에 들어왔을 경우 빨간색
		TRACE("mouse in!!\n");
		m_mouseIn = TRUE;
	}
	else {//사각형 밖에 커서가 있을 경우 초록색
		TRACE("mouse out!!\n");
		m_mouseIn = FALSE;
	}
	Invalidate(false);
	

	CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnSize(UINT nType, int cx, int cy)//창이 만들어지거나 창크기가 변경될때 자동 호출되는 함수
{

	GetClientRect(&rect);//창크기가 변경될때 클라이언트 크기를 재 정의 // 여기가 적정

	CWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CChildView::OnTimer(UINT_PTR nIDEvent)//시간이 지남에 따라서 이 함수 호출
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}


int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)//창 열릴 때 호출되는 핸들러
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	SetTimer(1, 1000, NULL);//1번 타이머 1초마다 실행


	return 0;
}


void CChildView::OnDestroy()//창 닫힐때 호출되는 핸들러
{
	CWnd::OnDestroy();
	KillTimer(1);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
*/

void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_arr.Add(point);


	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);

	for (int i = 0; i < m_arr.GetSize(); i++) {
		dc.Rectangle(m_arr[i].x - 50, m_arr[i].y - 50, m_arr[i].x + 50, m_arr[i].y + 50);
	}

	m_arr.RemoveAll();
	//Invalidate();

	CWnd::OnRButtonDown(nFlags, point);
}
