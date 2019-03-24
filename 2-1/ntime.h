/*
 * This class enables the use of the class ntime. An entered time cannot be negative, although single parts of the time (hours, minutes etc.) can
 * be entered as negative values. Every entered time will be normalized to positive values (or to 0:0:0 if negative), where minutes and seconds are
 * always between 0 and 59. Hours can be as large as wished.
 * Accessible methods are:
 * get_hours	-	returns hours of time
 * get_minutes	-	returns minutes of time
 * get_seconds	-	returns seconds of time
 * justseconds	-	returns the whole time converted to seconds
 * add			-	adds a given ntime-value to the current class-instance (same as operator+ does directly)
 * operator -	-	was used to realize method diff instead
 * operator <<	-	was used to realize an easy way for outputting times
 */

#ifndef _NTIME
#define _NTIME

#include <math.h>
#include <iostream>
class ntime
{
private:
	int _hours;
	int _minutes;
	int _seconds;
	void normalize();

public:
	ntime(int ,int ,int);
	~ntime();
	ntime(const ntime&);
	int get_hours() const;
	int get_minutes() const;
	int get_seconds() const;
	int justseconds() const;
	void add(const ntime);
	ntime& operator+(ntime const&);
	ntime& operator-(ntime const&);
};
std::ostream& operator<<(std::ostream &, ntime const);
#endif
