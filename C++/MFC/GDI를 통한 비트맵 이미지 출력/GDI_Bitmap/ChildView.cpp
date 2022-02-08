
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "GDI_Bitmap.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()//창 크기가 변경될때 전달되는 메세지
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

	/*
	비트맵 출력 과정(더블 버퍼링)

	비트맵 이미지 입력 -> 메모리 DC -> 화면 DC -> 화면 출력
	(화면 출력은 메모리 DC가 입력을 다 받은 후 최초 1번만 한다 -> 그렇지 않으면 끔벅임)

	*/

	//Bitmap 출력 과정
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다. //화면 dc
	
	CDC memdc;//메모리 dc
	memdc.CreateCompatibleDC(&dc);//메모리 DC와 화면 DC연결

	CBitmap binfo;
	binfo.LoadBitmapW(IDB_BITMAP1);//bitmap 정보 읽어오기

	BITMAP bmpinfo;
	binfo.GetBitmap(&bmpinfo);//예외) 비트맵의 대한 정보를 넘겨주는 방법  - 선택적

	memdc.SelectObject(&binfo);//메모리dc 에다가 bitmap 정보 입력
	memdc.Ellipse(0, 0, 10, 10);

	dc.StretchBlt(0, 0, m_Clientrect.Width() , m_Clientrect.Height() , &memdc, 0, 0, bmpinfo.bmWidth,bmpinfo.bmHeight, SRCCOPY);//Bitmap 출력 //;그림에 특정 부분을 가져올 수 있는 방식
	//dc.BitBlt(0, 0, m_Clientrect.Width(), m_Clientrect.Height(), &memdc, 0, 0, SRCCOPY);//Bitmap 출력 //;그림에 특정 부분을 가져올 수 있는 방식
													 
	CRect rect;
	GetClientRect(&rect);

	//dc.StretchBlt(0,0,500,500,&memdc,rect.)//축소나 확대 가 가능한  비트맵 출력 함수

	/*
	CRect rect;
	GetClientRect(&rect);

	CFont font;
	//font.CreateFontIndirectW()
	//추후의 다이얼로그를 이용하여 글꼴 변경(종합적으로) -> 지금은 글꼴과 크기만 함수로 변경(제한적)
	
	font.CreatePointFont(400, _T("궁서체"));
	dc.SelectObject(font);	
	//dc.TextOutW(rect.Width()/ 2, rect.Height() / 2, _T("18012209 부규필"));
	dc.DrawText(_T("18012209 부규필"), rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//중앙 출력 방법
	*/
	/*
	GDI 객체 말고도 MFC 내에 내장되어있는 객체들이 존재
	-> 이것들은 객체를 따로 생성하지 않고 바로 SelectStockObject(SelectObject 아님!!)로 설정하면 사용 가능
	*/

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnSize(UINT nType, int cx, int cy)//창크기 변경 + 창 생성시 실행되는 메세지
{
	CWnd::OnSize(nType, cx, cy);

	GetClientRect(m_Clientrect);


	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
