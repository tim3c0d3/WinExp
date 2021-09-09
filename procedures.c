#include <windows.h>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam){
	PAINTSTRUCT ps;
	HDC hdc;
	switch (message) {
		
		case WM_PAINT:{
			
			hdc = BeginPaint(hwnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH)((COLOR_WINDOW)+1));
			EndPaint(hwnd, &ps);
			break;
		}
		case WM_QUERYENDSESSION:
			switch (lparam){
				case ENDSESSION_CLOSEAPP:
					break;
				case ENDSESSION_CRITICAL:/* application is forced to shut down*/
					break;
				case ENDSESSION_LOGOFF:
					break;
				case 0:
					break;
				case WM_ENDSESSION:
					if (wparam == TRUE){
						/* Dump state to disk */
					}
					else{
						/* Application on system has returned FALSE from WM_QUERYENDSESSION*/
					}
			}
			break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			DestroyWindow(hwnd);
			break;

		default:
			return DefWindowProc(hwnd, message, wparam, lparam);
	}
	return 0;
}
LRESULT WINAPI KeyboardProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam){
	switch (msg){
		case WM_KEYDOWN:
			break;
		case  WM_KEYUP:
			break;
	}

}
LRESULT WINAPI X(HWND hwnd, UNIT msg, WPARAM wparam, LPARAM lparam){
	if (InSendMessage()){

	}
}