#ifndef _DATE_H
#define _DATE_H

class Date {
	int year;
	int month;
	int day;

public:
	Date(int y, int m, int d);
	Date(int y);
	Date();
	~Date();
	static Date getDate();
	int getYear();
	int getMonth();
	int getDay();
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
};
#endif