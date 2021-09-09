#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

//unicode declarations
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

#pragma comment(lib, "Ws2_32.lib")

#include <winsock2.h>
#include <windows.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include "memalloc.h"

int main(){
	SOCKET connsock = INVALID_SOCKET;
	WSADATA wsd;
	int ret;
	wchar_t *fn;
	LPSOCKADDR socketaddr_v6;
	struct sockaddr_in clientaddr;
	ret = WSAStartup(MAKEWORD(2, 2), &wsd);
	if (ret != 0){
		return EXIT_FAILURE;
	}
	GetModuleFileNameW(0, fn, 1024);
	connsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (connsock == INVALID_SOCKET){
		printf("Error : %ld\n", WSAGetLastError());
		WSACleanup();
		return EXIT_FAILURE;
	}
	struct addrinfoW *result = NULL, *ptr = NULL, hints;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	ret = GetAddrInfoW(L"http://www.google.com", L"80", &hints, &result);
	if (ret != 0){
		wprintf(L"Could not get address: %d\n", ret);
		WSACleanup();
		return 1;
	}
	for (ptr = result; ptr != NULL; ptr = result->ai_next){
		clientaddr.sin_family = AF_INET;
		clientaddr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr *)ptr->ai_addr));
		clientaddr.sin_port = htons(80);
	}


	char *cbuf = (char*)save_buffer(4096);
	do {
		ret = recv(connsock, cbuf, sizeof(*cbuf), 0);
	} while (ret > 0);
	FreeAddrInfoW(result);
	closesocket(connsock);
	WSACleanup();
	return 0;
}