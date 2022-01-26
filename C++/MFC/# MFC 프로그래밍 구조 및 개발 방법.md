# MFC 프로그래밍💻

## MFC 프로그래밍의 구조

- Visua Studio를 통해서 MFC 앱 프로젝트를 개설시 `CMyApp`, `CMainFrame` , `CChildView` 클래스가 자동으로 만들어 진다.(CAbout 제외)

  - `CMyApp` : 프레임 윈도우 생성, 메시지 루프 제공

    ```cpp
    //BOOL CMFCApplication1App::InitInstance() 함수 중 일부 발췌
    CFrameWnd* pFrame = new CMainFrame;//mainframe 클래스 생성
    if (!pFrame)
      return FALSE;
    m_pMainWnd = pFrame;

    pFrame->LoadFrame(IDR_MAINFRAME,WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, nullptr,nullptr);//만들어진 프레임을 리소스와 함께 적재

    pFrame->ShowWindow(SW_SHOW);//적재한 리소스와 프레임을 화면에 출력
    pFrame->UpdateWindow();
    return TRUE;

    ```

  - `CMainFrame` : 화면에 보여지는 창(프레임,틀)과 관련, 윈도우 관련 기능 정의, 뷰를 생성

    ```cpp
    //int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 함수 중 일부 발췌
    if (CFrameWnd::OnCreate(lpCreateStruct) == -1)//메인프레임 생성
    if (!m_wndView.Create(nullptr, nullptr, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, nullptr))//뷰 생성

    if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY CBRS_SIZE_DYNAMIC) ||
    !m_wndToolBar.LoadToolBar(IDR_MAINFRAME))//툴바 생성

    if (!m_wndStatusBar.Create(this))//상태 표시줄 생성
    //

    BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)//창 생성전에 사전 정보(크기 좌표 등)를 변경하는 함수
    ```

  - `CChildView` : 화면에 보여지는 창(하얀 콘텐츠 영역)과 관련, 창과 관련 = 어플리케이션의 클라이언트 영역 + 메세지에 대응하는 이벤트들에 대응하는 메세지 맵이 존재

    ```cpp
    void CChildView::OnPaint() //창이 그려질때 실행되는 이벤트

    void CChildView::OnLButtonDown(UINT nFlags, CPoint point)//왼쪽 버튼을 눌렀을때 실행되는 이벤트
    ```

- MFC로 제작한 어플리케이션이 화면으로 보여지는 경로는 **APP -> 디바이스 컨텍스트(DC) -> GDI -> 드라이버 -> 출력장치** 를 따른다.

  - 디바이스 컨텍스트(DC)
    - 출력과 관련된 다양한 정보를 가짐
    - gdi가 생성하고 관리하는 데이터 구조체
    - 멀티태스킹 gui환경에서 발생할 수 있는 복잡한 상황들을 신경쓰지 않고 장치에 자유롭게 사용가능

- MFC 프로그램 기본 진행 순서
  - CMainFrame::LoadFrame()
  - CMainFrame::PreCreateWindow()
  - CMainFrame::PreSubclassWindow()
  - CMainFrame::OnCreate()
