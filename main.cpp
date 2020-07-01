#include <iostream>
#include <fstream>
#include "info.h"
#include "list.h"
#include <cstring>


using namespace std;


int main(int argc, char *argv[]) {
		ofstream out;
		string filename;
		
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
		
		if (argc >= 2) {
			filename = string(argv[1]);
			out.open(argv[1], ios_base::out);
		}
		else {
			cout << "Enter filename: \n";
			cin >> filename;
			out.open(filename, ios_base::out);
		}

		do {
			cout << "Select option number. Enter 0 to exit." << endl;
			cout << "1. Add to list." << endl;
			cout << "2. Remove node." << endl;
			cout << "3. Print list." << endl;
			cout << "4. Size of list" << endl;
			cout << "5. Search by patient last name." << endl;
			cout << "6. Change recording date and time." << endl;

			cin >> option;


			switch (option) {
			case 0:
				break;
			case 1:
				cout << "Enter doctor specialization: ";
				cin >> d_spec1;
				cout << endl;
				cout << "Enter doctor last name: ";
				cin >> d_lname1;
				cout << endl;
				cout << "Enter doctor first name: ";
				cin >> d_fname1;
				cout << endl;
				cout << "Enter patient last name: ";
				cin >> p_lname1;
				cout << endl;
				cout << "Enter patient first name: ";
				cin >> p_fname1;
				cout << endl;
				cout << "Enter data of recording: ";
				cin >> day1 >> month1;
				cout << endl;
				cout << "Enter time of recording: ";
				cin >> hour1 >> minutes1;
				cout << endl;
				lst.add(d_spec1, d_lname1, d_fname1, p_lname1, p_fname1, day1, month1, hour1, minutes1);
				cout << endl;
				break;
			case 2:
				lst.printAll();
				cout << "Enter node number to delete: ";
				cin >> del;
				cout << endl;
				lst.remove(del);
				cout << endl;
				break;
			case 3:
				lst.printAll();
				cout << endl;
				break;
			case 4:
				cout << "Size of list : " << lst.size() << endl;
				break;
			case 5:
				cout << "Enter patient last name: ";
				cin >> usearch1;
				lst.search(usearch1);
				cout << endl;
				break;
			case 6: 
				lst.printAll();
				cout << "Enter patient last name: ";
				cin >> usearch1;
				lst.editing(usearch1);
				lst.printAll(); 
				cout << endl;
				break;
			}
		} while (option != 0);
		lst.output(filename);
		return 0;
}
