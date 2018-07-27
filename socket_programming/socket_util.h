#pragma once

enum class SocketAddressFamily
{
	INET = AF_INET,
	INET6 = AF_INET6
};

class SocketUtil
{
private:
public:
	static bool staticInit();
	static void cleanUp();

	static void reportError(const char* inOperationDesc);
	static int getLastError();
};