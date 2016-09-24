#ifndef _DATE_H
#define _DATE_H
class Date {
	int year;
	int month;
	int day;

public:
	Date(int y, int m, int d);
	Date();
	~Date();
	static Date getDate();
};
#endif