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

    ```

    ```

  - `CChildView` : 화면에 보여지는 창(하얀 콘텐츠 영역)과 관련, 창과 관련 = 어플리케이션의 클라이언트 영역

    ```

    ```
