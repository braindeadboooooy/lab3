#include "info.h"
#include <string>


using namespace std;

Info::Info()
{
	_d_spec = " ";
	_d_lname = " ";
	_d_fname = " ";
	_p_lname = " ";
	_p_fname = " ";
	_day = 0;
	_month = 0;
	_hour = 0;
	_minutes = 0;
	_next = NULL;
}

Info::Info(string d_spec, string d_lname, string d_fname, string p_lname, string p_fname,unsigned int day, unsigned  int month, unsigned  int hour, unsigned  int minutes)
{
	_d_spec = d_spec;
	_d_lname = d_lname;
	_d_fname = d_fname;
	_p_lname = p_lname;
	_p_fname = p_fname;
	_day = day;
	_month = month;
	_hour = hour;
	_minutes = minutes;
	_next = NULL;
}

void Info::setState(string d_spec, string d_lname, string d_fname, string p_lname, string p_fname, unsigned  int day, unsigned  int month, unsigned  int hour, unsigned  int minutes) {
	if ((_d_spec != d_spec) && (_d_lname != d_lname) && (_d_fname != d_fname) && (_p_lname != p_lname) && (_p_fname != p_fname) && (_day != day) && (_month != month) && (_hour != hour) && (_minutes = minutes)) {
		_d_spec = d_spec;
		_d_lname = d_lname;
		_d_fname = d_fname;
		_p_lname = p_lname;
		_p_fname = p_fname;
		_day = day;
		_month = month;
		_hour = hour;
		_minutes = minutes;
	}
}


Info* Info::next()
{
	return _next;
}

string Info::d_spec(){
	return _d_spec;
}

string Info::d_lname() {
	return _d_lname;
}

string Info::d_fname() {
	return _d_fname;
}

string Info::p_lname() {
	return _p_lname;
}

string Info::p_fname() {
	return _p_fname;
}

int Info::day() {
	return _day;
}

int Info::month() {
	return _month;
}

int Info::hour() {
	return _hour;
}

int Info::minutes() {
	return _minutes;
}



void Info::setNext(Info* next)
{
	if (_next != next) {
		_next = next;
	}
}

ostream & operator << (ostream& out, const Info& info){
	out << "Doctor specialization: " << info._d_spec << endl;
	out << "Doctor Last name: " << info._d_lname << endl;
	out << "Doctor First name: " << info._d_fname << endl;
	out << "Patient Last name: " << info._p_lname << endl;
	out << "Patient First name: " << info._p_fname << endl;
	out << "Date of recording: " << info._day  << "." << info._month << endl;
	out << "Time of recording: " << info._hour << ":" << info._minutes << endl;
	return out;
}

istream& operator >> (istream& input, Info& info){
	input >> info._d_spec;
	input >> info._d_lname;
	input >> info._d_fname;
	input >> info._p_lname;
	input >> info._p_fname;
	input >> info._day;
	input >> info._month;
	input >> info._hour;
	input >> info._minutes;
	return input;

}
