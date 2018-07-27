#include "chat_server.h"

// POSIX 플랫폼에선 소켓 라이브러리를 활성화 할 필요가 없음.
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

// 라이브러리 사용 종료도 POSIX는 별다른 행동이 필요 없음.
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
	// 전역변수로, 덮어 쓰일 수 있으므로 에러를 감지한 시점에
	// 즉시 확인해야 한다.
#endif
}
