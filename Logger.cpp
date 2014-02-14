/*
 * Logger.cpp
 *
 *  Created on: 14.2.2014
 *      Author: Heikki
 */

#include "Logger.h"

using namespace std;

Logger::Logger() {
	// TODO Auto-generated constructor stub
}

Logger::~Logger() {
	delete oFile;
}

/*template <typename T>
Logger& operator<< (Logger& logger, T stream_item)
{
    return logger.Display(stream_item);
}*/
template <typename T>
Logger& operator<< (Logger& logger,T stream_item)
{
    logger.Display(stream_item);
}

int Logger::OpenFile(std::string fileName) {

	if (fileName.empty()) {
		cout << "Fatal: file name is empty" << endl;
	}

	/* //errors handled by exception
	try {
		oFile = new ofstream(fileName.c_str());
		oFile->exceptions ( ostream::failbit | ostream::badbit );
	} catch (std::exception const& e) {
		cout << "Error when opening log file: " << e.what() << endl;
	}*/

	//errors handled by return -1
	oFile = new ofstream(fileName.c_str());

	if (oFile->bad() || oFile->fail()) {
		cout << "Error when opening log file" << endl;
		return -1;
	}

	return 0;
}

int Logger::CloseFile() {
	oFile->flush();
	oFile->clear();
	oFile->close();
	delete oFile;
	oFile = NULL;
	return 0;
}
