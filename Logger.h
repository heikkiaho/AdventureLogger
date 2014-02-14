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
 * http://stackoverflow.com/questions/14370279/prevent-endline-after-printing-system-time
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include "CSingleton.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

class Logger: public CSingleton<Logger> {
	friend class CSingleton<Logger>;
protected:
	Logger();
public:
	Logger * GetLogger( const char *loggerName );
	template <typename T>
	Logger& operator<< (T stream_item)
	{
	    WriteToFile(stream_item);
	    return *this;
	}

	template <typename T>
	inline void WriteToFile(T stream_item)
	{
		//file write and it's exception handling
		try {
			oFile->exceptions ( ofstream::eofbit | ofstream::failbit | ofstream::badbit );
		   // current date/time based on current system
		   time_t now = time(0);
		   // convert now to string form
		   char* dt = ctime(&now);
		   dt[strlen(dt) - 1] = '\0';
			*oFile <<  dt << " <LOG> " << stream_item << "\n";
			//flush between writes is very time consuming
			oFile->flush();
		} catch(std::exception const& e) {
		     cout << "Error when writing log file: " << e.what() << endl;
		}
		//cout << stream_item << "\n";
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

