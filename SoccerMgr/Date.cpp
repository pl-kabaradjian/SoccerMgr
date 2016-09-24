#include "Date.h"
#include <iostream>
#include <ctime>

using namespace std;

Date::Date(int y = 2000, int m = 1, int d = 1)
{
	year = y;
	month = m;
	day = d;
}

Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}

Date::~Date()
{
	//cout << "Date detruite" << endl;
}

Date Date::getDate()
{
	time_t t = time(0);   // get time now
	struct tm now;
	localtime_s(&now, &t);

	/*//Code d'affichage de la date
	cout << (now.tm_year + 1900) << '-'
		<< (now.tm_mon + 1) << '-'
		<< now.tm_mday
		<< endl;*/
	return Date(now.tm_year + 1900, now.tm_mon + 1, now.tm_mday);
}
