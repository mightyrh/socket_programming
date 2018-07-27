#include "chat_server.h"

// POSIX �÷������� ���� ���̺귯���� Ȱ��ȭ �� �ʿ䰡 ����.
bool SocketUtil::staticInit()
{
#if _WIN32
	WSADATA wsaData;
	int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != NO_ERROR) {
		reportError("starting up");
		return false;
	}
#endif
	return true;
}

// ���̺귯�� ��� ���ᵵ POSIX�� ���ٸ� �ൿ�� �ʿ� ����.
void SocketUtil::cleanUp()
{
#if _WIN32
	WSACleanup();
#endif
}

void SocketUtil::reportError(const char * inOperationDesc)
{
#if _WIN32
	LPVOID msgBuf;
	DWORD errorNum = getLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		errorNum,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&msgBuf,
		0, NULL);
	
	LOG("Error %s: %d- $s", inOperationDesc, errorNum, msgBuf);
#else

#endif
}

int SocketUtil::getLastError()
{
#if _WIN32
	return WSAGetLastError();
#else
	return errno;	
	// ����������, ���� ���� �� �����Ƿ� ������ ������ ������
	// ��� Ȯ���ؾ� �Ѵ�.
#endif
}
