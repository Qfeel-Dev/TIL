
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
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
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
	화면의 크기 정보 활용

	*/
	CRect frame;


	
	

	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}

