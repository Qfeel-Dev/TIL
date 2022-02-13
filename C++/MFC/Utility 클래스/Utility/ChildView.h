
// ChildView.h: CChildView 클래스의 인터페이스
//


#pragma once


// CChildView 창

class CChildView : public CWnd
{
// 생성입니다.
public:
	CChildView();

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CChildView();

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CRect rect;
	bool m_mouseIn;
	//afx_msg void OnSize(UINT nType, int cx, int cy);
	//afx_msg void OnTimer(UINT_PTR nIDEvent);
	//afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//afx_msg void OnDestroy();
	//CArray<CPoint, CPoint&> m_arr;//template? - 1차원
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMButtonDown(UINT nFlags, CPoint point);
	CArray<CPoint, CPoint &> m_arr[10]; //2차원 10 층 동적 방
};

