#include <iostream>
#include <Windows.h>
#include <string>

const int MESSAGE_SIZE = 512;

int main(int argc,char* argv[])
{
	std::string pipestr = argv[1];

	printf("\nConnecting to pipe %s", argv[1]);

	
	std::wstring pipewstring = std::wstring(pipestr.begin(), pipestr.end());
	LPCWSTR pipeName = pipewstring.c_str();
	HANDLE clientPipe = NULL;
	BOOL isPipeRead = true;
	wchar_t message[MESSAGE_SIZE] = { 0 };
	DWORD bytesRead = 0;

	std::wcout << "Connecting to " << pipeName << std::endl;
	clientPipe = CreateFile(pipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);

	while (isPipeRead) {
		isPipeRead = ReadFile(clientPipe, &message, MESSAGE_SIZE, &bytesRead, NULL);
		std::wcout << "Received message: " << message;
	}

	return 0;
}