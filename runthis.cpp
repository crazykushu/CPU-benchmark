#include <iostream>
#include <time.h>
#include <algorithm>
#include <windows.h>
#include <tchar.h>

using namespace std;

int main(int argc, char* argv[])
{
    int times;
    cout << "Plese input the number of instances you need for this performance evaluation: (only an integer larger than 0)" << endl;
    cin >> times;
    
    for (int i = 0; i < times; i++)
    {
    STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );
	if (!
	CreateProcess
			(
			TEXT(".\\evaluation.exe"),
			NULL,NULL,NULL,FALSE,
			CREATE_NEW_CONSOLE,
			NULL,NULL,
			&si,
			&pi
			)
			)
		{
			cout << "Unable to execute.";
		}
    }

    return 0;
}