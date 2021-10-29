#include <Windows.h>
#include <string>
#include <iostream>

#define NAME_MS "\\\\.\\mailslot\\Slot"
#define SIZE 100

using namespace std;

int main()
{
	try
	{
		LPCWSTR nameMailslot = TEXT(NAME_MS);
		HANDLE hMailslot;
		if ((hMailslot = CreateFile(nameMailslot, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL)) == INVALID_HANDLE_VALUE)
			throw "CreatFile fail\n";

		char outBuf[SIZE] = "Hello Server";
		DWORD bytrsWritten;
		if (!WriteFile(hMailslot, outBuf, sizeof(outBuf), &bytrsWritten, NULL))
			throw "WriteFile fail\n";

		CloseHandle(hMailslot);
	}
	catch (const char* error)
	{

	}

	system("pause");
	return 0;
}
