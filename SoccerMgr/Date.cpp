#include "Date.h"
#include <iostream>
#include <ctime>

using namespace std;

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

Date::Date(int y) {
	year = y;
	month = 1;
	day = 1;
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

//Cette fonction renvoie un objet date avec la date du jour
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

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

void Date::setYear(int y)
{
	year = y;
}

void Date::setMonth(int m)
{
	month = m;
}

void Date::setDay(int d)
{
	day = d;
}

string Date::toString()
{
	string res = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
	return (res);
}
