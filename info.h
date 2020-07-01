#ifndef INFO_H
#define INFO_H

#include<iostream>
#include<string>

using namespace std;


class Info {
public:
	Info();
	Info(string d_spec, string d_lname, string d_fname, string p_lname, string p_fname, unsigned int day, unsigned int month, unsigned int hour, unsigned int minutes);
	Info* next();
	string d_spec();
	string d_lname();
	string d_fname();
	string p_lname();
	string p_fname();
	int day();
	int month();
	int hour();
	int minutes();


	string _d_spec, _d_lname, _d_fname, _p_lname, _p_fname;
    
	unsigned int _day, _month, _hour, _minutes;



	void setState(string d_spec, string d_lname, string d_fname, string p_lname, string p_fname, unsigned int day, unsigned int month, unsigned int hour, unsigned int minutes);
	void setDay(unsigned int day);
	void setMonth(unsigned int month);
	void setHour(unsigned int hour);
	void setMinutes(unsigned int minutes);
	

	friend ostream& operator << (ostream& out, const Info& info);
	friend istream& operator >> (istream& in, const Info& info);
	

	void setNext(Info* next);


private:
	Info* _next;
};

#endif // LIST_H
