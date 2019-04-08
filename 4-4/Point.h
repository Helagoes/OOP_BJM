#ifndef _POINT
#define _POINT

class Point {
private:
	double x;
	double y;
public:
	//standard methods
	Point(): x(0), y(0) {}
	Point(double _x, double _y): x(_x), y(_y) {}
	Point(const Point& ref)
	{
		this->x = ref.get_x();
		this->y = ref.get_y();
	}
	~Point() {}
	//getter-methods
	double get_x() const { return this->x; }
	double get_y() const { return this->y; }
	Point operator+=(const Point);
};

bool operator==(const Point, const Point);

#endif
