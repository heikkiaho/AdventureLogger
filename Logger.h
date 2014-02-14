/*
 * Logger.h
 *
 *  Created on: 14.2.2014
 *      Author: Heikki
 *
 * http://stackoverflow.com/questions/290632/how-to-overload-operator-that-doesnt-take-or-return-ostream
 * @"James Curran"
 * http://stackoverflow.com/questions/3629321/try-catch-block-for-c-file-io-errors-not-working
 * @"dirkgently"
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include "CSingleton.h"
#include <iostream>
#include <fstream>

using namespace std;

class Logger: public CSingleton<Logger> {
	friend class CSingleton<Logger>;
protected:
	Logger();
public:
	Logger * GetLogger( const char *loggerName );
	template <typename T>
	inline Logger& Display(T stream_item)
	{
		//file write and it's exception handling
		try {
			oFile->exceptions ( ofstream::eofbit | ofstream::failbit | ofstream::badbit );
			oFile << stream_item;
			//flush between writes is very time consuming
			oFile->flush();
		} catch(std::exception const& e) {
		     cout << "Error when writing log file: " << e.what() << endl;
		}
	    return *this;
	}

	int OpenFile(std::string fileName);
	int CloseFile();
	virtual ~Logger();
private:
    std::ofstream *oFile;
};
// Usage syntax resembles now global object
#define g_Logger Logger::GetInstance()
#endif //LOGGER_H_

