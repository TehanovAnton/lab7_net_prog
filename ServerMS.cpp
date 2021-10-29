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
        if ((hMailslot = CreateMailslot(nameMailslot, NULL, MAILSLOT_WAIT_FOREVER, NULL)) == INVALID_HANDLE_VALUE)
            throw "CreateMailslot fail\n";

        cout << "Server start:" << endl;

        while (true)
        {
            char inBuf[SIZE];
            DWORD bytesRead;
            if (!ReadFile(hMailslot, inBuf, sizeof(inBuf), &bytesRead, NULL))
                throw "ReadFile fail";

            cout << "Read message: " << inBuf << endl << endl;
        }

        cout << "Server stop" << endl << endl;

        CloseHandle(hMailslot);

    }
    catch (const char* error)
    {
        cout << error;
    }
    
    system("pause");
    return 0;
}