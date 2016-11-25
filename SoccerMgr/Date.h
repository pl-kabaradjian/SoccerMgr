#ifndef _DATE_H
#define _DATE_H
#include <string>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

using namespace std;

class Date {
	int year;
	int month;
	int day;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version) {
		ar << year;
		ar << month;
		ar << day;
	}

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
	string toString();
};
#endif