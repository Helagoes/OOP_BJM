#ifndef _STUDI
#define _STUDI

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <fstream>

class studi {
public:
	bool in(std::string, size_t);
	//getter
	long g_matnr() const { return this->matnr; }
	std::string g_vorname() const { return this->vorname; }
	std::string g_nachname() const { return this->nachname; }
	//setter
	void s_matnr(long value) { this->matnr = value; }
	void s_vorname(std::string value) { this->vorname = value; }
	void s_nachname(std::string value) { this->nachname = value; }


private:
	long matnr;
	std::string vorname;
	std::string nachname;
};

std::ostream& operator<<(std::ostream&, const studi);
bool operator>>(std::ifstream&, studi&);
#endif
