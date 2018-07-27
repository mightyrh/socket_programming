#pragma once

#ifdef _WIN32	// windows platforms
	#define WIN32_LEAN_AND_MEAN
	#define NOMINMAX

	#include <Windows.h>
	#include <WinSock2.h>	// socket
	#include <WS2tcpip.h>	// �ּҺ�ȯ
#else			// POSIX platforms
	#include <sys/socket.h>	// socket
	#include <netinet/in.h>	// IPv4
	#include <arpa/inet.h>	// �ּҺ�ȯ
	#include <netdb.h>		// name resolution
#endif

#include <string>

#include "./socket_util.h"
#include "./string_util.h"
