#include<iostream>
#include<fstream>
#include"info.h"
#include"list.h"
#include <cstring>


using namespace std;


int main() {
	ofstream out;
	out.open("D:\\otput.txt");
	if (!(out.is_open())) {
		cout << "File not found!";
		cout << "Exit....";
		return -1;
	}
	else{
		string d_spec1;
		string d_lname1;
		string d_fname1;
		string p_lname1;
		string p_fname1;
		string usearch1;
		unsigned int day1;
		unsigned int month1;
		unsigned int hour1;
		unsigned int minutes1;
		int del;


		List lst;

		int option;

		do {
			cout << "Select option number. Enter 0 to exit." << endl;
			cout << "1. Add to list." << endl;
			cout << "2. Remove node." << endl;
			cout << "3. Print list." << endl;
			cout << "4. Size of list" << endl;
			cout << "5. Delete all list" << endl;
			cout << "6. Search by patient last name." << endl;

			cin >> option;


			switch (option) {
			case 0:
				break;
			case 1:
				cout << "Enter doctor specialization: ";
				cin >> d_spec1;
				out << d_spec1;
				cout << endl;
				cout << "Enter doctor last name: ";
				cin >> d_lname1;
				out << d_lname1;
				cout << endl;
				cout << "Enter doctor first name: ";
				cin >> d_fname1;
				out << d_fname1;
				cout << endl;
				cout << "Enter patient last name: ";
				cin >> p_lname1;
				out << d_lname1;
				cout << endl;
				cout << "Enter patient first name: ";
				cin >> p_fname1;
				out << d_fname1;
				cout << endl;
				cout << "Enter data of recording: ";
				cin >> day1 >> month1;
				out << day1 << month1;
				cout << endl;
				cout << "Enter time of recording: ";
				cin >> hour1 >> minutes1;
				out << hour1 << minutes1;
				cout << endl;
				lst.add(d_spec1, d_lname1, d_fname1, p_lname1, p_fname1, day1, month1, hour1, minutes1);
				break;
			case 2:
				lst.printAll();
				cout << "Enter the number: ";
				cin >> del;
				cout << endl;
				lst.remove(del);
				lst.printAll();
				break;
			case 3:
				lst.printAll();
				break;
			case 4:
				lst.size();
				break;

			case 5:
				lst.removeAll();
				break;

			case 6:
				cout << "Enter search string:";
				cin >> usearch1;
				lst.search(usearch1);
				break;
			}
		} while (option != 0);

		return 0;
	}
}