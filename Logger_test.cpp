/*
 * Logger_test.cpp
 *
 *  Created on: 14.2.2014
 *      Author: Heikki
 */

#include "Logger.h"

using namespace std;

int main () {
	Logger * log = g_Logger;
    log->OpenFile("logFile.txt");

    *log << "File is open";
    *log << "let us write some lines";
    *log << "hahahaa";
    log->CloseFile();
    delete log;
	return 0;
}

