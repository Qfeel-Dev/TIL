#include <windows.h>//Window API file 

LRESULT CALLBACK WndProc(HWND , UINT , WPARAM , LPARAM );
//�ü������ ȣ����ϴ� �Լ� -callback - �޽��� ó��, 
// HWND : 
// UINT :
// WPARAM :
// LPARAM :

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR IpcmdLine, int nCmdShow) //Window pgm������ ���� �Լ�
{
	WNDCLASS wndclass;//������ Ŭ���� -> ������ �Ӽ� ����   ����
	HWND hwnd;//������ ������ Ŭ������ �ڵ� h - handle		���̽�ƽ
	MSG msg;//���� �޼���

	//������ Ŭ���� �ʱ�ȭ �۾�
	wndclass.style = CS_HREDRAW | CS_VREDRAW;//��Ÿ�� ����
	wndclass.lpfnWndProc = WndProc;//ȣ����ϴ� �Լ� ���� -���ν��� �̸�
	wndclass.cbClsExtra = 0;//���� �޸�
	wndclass.cbWndExtra = 0;//���� �޸�
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//������ ���
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);//Ŀ�� ���
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//������
	wndclass.lpszMenuName = NULL;//�޴�
	wndclass.lpszClassName = TEXT("HelloClass");//������ Ŭ���� �̸�

	if (!RegisterClass(&wndclass)) {
		return 1;
	}
	
	//������ â�� ���� 
	hwnd = CreateWindow(TEXT("HelloClass"), TEXT("HelloSDK"),
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	
	//������ â�� ȭ�鿡 ����
	ShowWindow(hwnd, nCmdShow);

	//�޽��� ť���� �޽����� �ϳ��� ������ ó���Ѵ�.
	while (GetMessage(&msg,NULL,0,0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);//�޼��� ���� -> �ݹ� �Լ���
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
			MessageBox(hwnd, TEXT("���콺 Ŭ��!"), TEXT("���콺 �޽���"), MB_OK);
			return 0;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);//ȭ�� ��±��
			TextOut(hdc, 100, 100, str, lstrlen(str));
			EndPaint(hwnd, &ps);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		//�޽��� ���Ǹ� �� �Ұ�� �ٽ� �ü���� ��ȯ�ȴ�
	}

	return DefWindowProc(hwnd, message, wParam, IParan);
}

