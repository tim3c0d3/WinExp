#include <windows.h>
#include <stdio.h>
#include <UserEnv.h>
#include "paths.h"

const wchar_t *lpszDefaultDirectory = "";
int CreateFileStructure(wchar_t *pDefaultDirectory){// Creates the default directory structure  

	HANDLE hndFile;

	/* Create security attribute with object
	** handle inheritance
	*/

	SECURITY_ATTRIBUTES secAttr;
	secAttr.bInheritHandle = TRUE;
	secAttr.nLength = sizeof(secAttr);
	secAttr.lpSecurityDescriptor = NULL;

	// Create directory in default program files directory
	BOOL dirCreate = CreateDirectoryExW(NULL, L"C:\Program Files\FreeCredit", &secAttr);

	if (dirCreate == 0){
		printf("Could not create directory\n");
		return EXIT_FAILURE;
	}

	// Create Directory in User AppData directory



}