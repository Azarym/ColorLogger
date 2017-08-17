/*
 * debugger.h
 *
 *  Created on: 3 févr. 2016
 *      Author: guillaume
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>
#include <stdarg.h>

class Logger
{
public:
	enum LogType
	{
		LOGTYPE_CRIT = 1,
		LOGTYPE_WARN = 2,
		LOGTYPE_INIT = 3,
		LOGTYPE_INFO = 4
	};

	static Logger* createDefault(int pOutFile);

	Logger(int pOutFile);
	~Logger();

	void setVerbose(int v);
	int getVerbose();

	void printLog(const char* name, LogType type, const char* msg, ...);

private:
	int gVerbose;
	bool gColor;

};

#endif /* LOGGER_H_ */
