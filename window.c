#include "window.h"
#include "resource.h"
HINSTANCE hgInstance;
const wchar_t szcls[] = L"WindowClass";
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nCmdShow){
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
    wc.style = CS_VREDRAW | CS_HREDRAW;
	wc.lpfnWndProc = (WNDPROC)WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = szcls;
	wc.lpszMenuName = NULL;
	wc.hIcon = LoadImage(wc.hInstance, MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CXSMICON), LR_DEFAULTCOLOR);
	wc.hIconSm = LoadImage(wc.hInstance, MAKEINTRESOURCE(IDI_ICON4), IMAGE_ICON, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CXSMICON), LR_DEFAULTCOLOR);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	if (!RegisterClassEx(&wc)){
		return FALSE;
	}
	hgInstance = hInstance;
	HWND hWindow = CreateWindow(szcls, L"Window", 
		WINDOWSTYLE, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);
	if (!hWindow){
		return 1;
	}
	ShowWindow(hWindow, nCmdShow);
	UpdateWindow(hWindow);
	MSG msg;
	BOOL mret;
	while ((mret = GetMessage(&msg, hWindow, 0, 0)) != 0){

		if (mret == -1){
			GetLastError();
			break;
		}

		else{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;
}
