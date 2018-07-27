#include "./chat_server.h"

#if !_WIN32
extern const char** __argv;
extern int __argc;
void outputDebugString(const char* inString)
{
	printf("%s", inString);
}
#endif

std::string StringUtil::getCommandLineArg(int inIndex)
{
	if (inIndex < __argc) {
		return std::string(__argv[inIndex]);
	}
	return std::string();
}

std::string StringUtil::sprintf(const char * inFormat, ...)
{
	// not thread safe... ?
	static char temp[4096];

	va_list args;
	va_start(args, inFormat);

#if _WIN32
	_vsnprintf_s(temp, 4096, 4096, inFormat, args);
#else
	vsnprintf(temp, 4096, inFormat, args);
#endif
	return std::string(temp);
}

// void StringUtil::Log(const char * inFormat)
// {
//
// }

void StringUtil::Log(const char * inFormat, ...)
{
	// not thread safe...
	static char temp[4096];

	va_list args;
	va_start(args, inFormat);

#if _WIN32
	_vsnprintf_s(temp, 4096, 4096, inFormat, args);
#else
	vsnprintf(temp, 4096, inFormat, args);
#endif
	// print message on debug window
	OutputDebugString(temp);
	OutputDebugString("\n");
}