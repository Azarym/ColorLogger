/*
 * debugger.h
 *
 *  Created on: 3 févr. 2016
 *      Author: guillaume
 */

#include "logger.h"

static Logger* gDefaultLogger = NULL;

Logger* Logger::createDefault(int pOutFile)
{
	if (gDefaultLogger)
		return NULL;
	else
	{
		gDefaultLogger = new Logger(pOutFile);
		return gDefaultLogger;
	}
}

Logger::Logger(int pOutFile)
{

}

Logger::~Logger()
{

}

void Logger::setVerbose(int v)
{
	gVerbose = v;
}

int Logger::getVerbose()
{
	return gVerbose;
}

void Logger::printLog(const char* name, LogType type, const char* msg, ...)
{
	if (type > gVerbose)
	{
		return;
	}

	int errNum = 30;
	int style = 0;

	switch (type)
	{
	case LOGTYPE_INFO:
		errNum = 34;
		break;
	case LOGTYPE_WARN:
		errNum = 33;
		break;
	case LOGTYPE_INIT:
		errNum = 35;
		break;
	case LOGTYPE_CRIT:
		errNum = 31;
		style = 1;
		break;
	}

	flockfile(stdout);

	if (name)
	{
		printf("\033[%d;36m[%s] ", style, name);
	}

	printf("\033[%d;%dm", style, errNum);

	va_list args;
	va_start(args, msg);

	vprintf(msg, args);
	va_end(args);

	printf("\033[0m\n");
	funlockfile(stdout);
}
