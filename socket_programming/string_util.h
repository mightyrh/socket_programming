#pragma once

namespace StringUtil
{
std::string getCommandLineArg(int inIndex);
std::string sprintf(const char* inFormat, ...);

void Log(const char* inFormat);
void Log(const char* inFormat, ...);
}

#define LOG(...) StringUtil::Log(__VA_ARGS__);