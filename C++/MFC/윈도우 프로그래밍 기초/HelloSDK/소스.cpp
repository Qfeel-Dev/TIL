#include <windows.h>//Window API file 

LRESULT CALLBACK WndProc(HWND , UINT , WPARAM , LPARAM );
//운영체제에게 호출당하는 함수 -callback - 메시지 처리, 
// HWND : 
// UINT :
// WPARAM :
// LPARAM :

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR IpcmdLine, int nCmdShow) //Window pgm에서의 메인 함수
{
	WNDCLASS wndclass;//윈도우 클래스 -> 윈도우 속성 설정   모터
	HWND hwnd;//제작한 윈도우 클래스의 핸들 h - handle		조이스틱
	MSG msg;//전달 메세지

	//윈도우 클래스 초기화 작업
	wndclass.style = CS_HREDRAW | CS_VREDRAW;//스타일 지정
	wndclass.lpfnWndProc = WndProc;//호출당하는 함수 지정 -프로시저 이름
	wndclass.cbClsExtra = 0;//여분 메모리
	wndclass.cbWndExtra = 0;//여분 메모리
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//아이콘 모양
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//커서 모양
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//배경색상
	wndclass.lpszMenuName = NULL;//메뉴
	wndclass.lpszClassName = TEXT("HelloClass");//윈도우 클래스 이름

	if (!RegisterClass(&wndclass)) {
		return 1;
	}
	
	//윈도우 창을 생성 
	hwnd = CreateWindow(TEXT("HelloClass"), TEXT("HelloSDK"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	
	//윈도우 창을 화면에 제공
	ShowWindow(hwnd, nCmdShow);

	//메시지 큐에서 메시지를 하나씩 꺼내서 처리한다.
	while (GetMessage(&msg,NULL,0,0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);//메세지 배포 -> 콜백 함수로
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM IParan) 
{
	HDC hdc;
	PAINTSTRUCT ps;
	const TCHAR* str = TEXT("Hello SDK");

	switch (message) {//WM = Window Message
		case WM_CREATE:
			return 0;
		case WM_LBUTTONDBLCLK:
			MessageBox(hwnd, TEXT("마우스 클릭!"), TEXT("마우스 메시지"), MB_OK);
			return 0;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);//화면 출력기능
			TextOut(hdc, 100, 100, str, lstrlen(str));
			EndPaint(hwnd, &ps);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		//메시지 정의를 안 할경우 다시 운영체제로 반환된다
	}

	return DefWindowProc(hwnd, message, wParam, IParan);
}

