#ifndef _LINE
#define _LINE
#include "Point.h"
class Line {
private:
	Point start;
	Point end;

public:
	Line(): start(0,0), end(0,0) {};
	Line(Point strt, Point nd): start(strt), end(nd) {}
	~Line() {}
	Point get_start() const {return this->start; }
	Point get_end() const {return this->end; }
	Line operator+=(const Point val)
	{
		this->start += val;
		this->end += val;
		return *this;
	}

};

bool operator==(Line a, Line b)
{
	if((a.get_start() == b.get_start()) && (a.get_end() == b.get_end()))
		return true;
	else
		return false;
}
#endif
