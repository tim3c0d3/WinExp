#ifndef UNICODE
#define UNICODE
#endif

#ifdef UNICODE
#ifndef _UNICODE
#define _UNICODE
#endif
#endif

#ifdef _UNICODE
#ifndef UNICODE
#define UNICODE
#endif
#endif
#include <windows.h>
#define WINDOWSTYLE WS_OVERLAPPEDWINDOW 
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);