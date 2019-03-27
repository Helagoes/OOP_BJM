#include "ntime.h"
void ntime::normalize()
		{
			//Normalize positive ntimes
			//seconds
			while(this->_seconds >= 60)
				{
					this->_minutes += 1;
					this->_seconds -= 60;
				}
			//minutes
			while(this->_minutes >= 60)
				{
					this->_minutes -= 60;
					this->_hours +=1;
				}
			if(this->_hours <0 || (this->_hours == 0 && this->_minutes <0) ) //if h<0 it cannot ever become positive since max value of m is 59, same for s, which is less than h=1
				{
					this->_hours = 0;
					this->_minutes = 0;
					this->_seconds = 0;
				}

			//Normalize negative ntimes
			//minutes
			while(this->_minutes <0 && this->_hours>0)
				{
					this->_minutes += 60;
					this->_hours -=1;
				}
			//seconds
			while(this->_seconds<0 && this->_minutes>0)
			{
					this->_seconds +=60;
					this->_minutes -=1;
			}
			while(this->_seconds<0 && this->_hours>0)
			{
				this->_seconds += 60;
				this->_minutes += 59;
				this->_hours -= 1;
			}
			if((this->_hours==0 && this->_minutes<0) || (this->_hours == 0 && this->_minutes==0 && this->_seconds<0)) //set time to null since it is negative
			{
				this->_hours = 0;
				this->_minutes = 0;
				this->_seconds = 0;
			}
		}
ntime::ntime():_hours(0), _minutes(0), _seconds(0)
{}
ntime::ntime(int hours, int minutes, int seconds):
		_hours(hours), _minutes(minutes), _seconds(seconds)
	{
	normalize();
	}
ntime::~ntime(){ }
ntime::ntime(const ntime &ref_ntime){
		_hours = ref_ntime._hours;
		_minutes = ref_ntime._minutes;
		_seconds = ref_ntime._seconds;
	}
void ntime::add(const ntime ref)
{
	this->_hours += ref.get_hours();
	this->_minutes += ref.get_minutes();
	this->_seconds += ref.get_seconds();
	this->normalize();
}
//more elegant way of implementing "add" as the binary + operator
ntime& ntime::operator+(ntime const &ref)
{
	this->_hours += ref.get_hours();
	this->_minutes += ref.get_minutes();
	this->_seconds += ref.get_seconds();
	this->normalize();
	return *this;
}
ntime& ntime::operator-(ntime const &ref)
{
	this->_hours -= ref.get_hours();
	this->_minutes -= ref.get_minutes();
	this->_seconds -= ref.get_seconds();
	this->normalize();
	return *this;
}


std::ostream& operator<<(std::ostream &stream, ntime const ref)
	{
		stream << ref.get_hours() << ":" << ref.get_minutes() << ":" << ref.get_seconds();
		return stream;
	}
