#include "list.h"
#include <iostream>
#include <cstring>
#include <fstream>

List::List() {
    head = NULL;
    _size = 0;
}

List::~List() {

    while (head != NULL) {
        Info* temp = head->next();
        delete head;

        head = temp;
    }
}

int List::size() {
    return _size;
}

void List::add(string d_spec, string d_lname, string d_fname, string p_lname, string p_fname, int day, int month, int hour, int minutes) {
    Info* temp = new Info(d_spec, d_lname, d_fname, p_lname, p_fname, day, month, hour, minutes);
    temp->setNext(head);
    head = temp;

    _size++;
}

void List::remove(int n) {
    Info* temp = head;
    if (head == NULL || n > _size) {
        cout << "Enter the correct number" << endl;
        return;
    }
    else if (n == 0) {
        Info* nhead = head->next();
        delete head;
        head = nhead;
        _size = _size - 1;
        return;
    }
    else {
        for (int i = 0; i < n - 1; i++)
            temp = temp->next();


        Info* delEl = temp->next();
        temp->setNext(delEl->next());
        _size = _size - 1;

        delete delEl;
    }
}

void List::printAll() {
    Info* temp = head;
    while (temp != NULL) {
        cout << temp->d_spec() << " "<< temp->d_lname() << " " << temp->d_fname() << " " << temp->p_lname() << " " << temp->p_fname() << " " << temp->day() << "." << temp->month() << " " << temp->hour() << ":" << temp->minutes() << endl ;
        temp = temp->next();
    }
}


void List::editing(string usearch) {
    Info inf;
    Info* temp = head;
    string s1 = usearch;
    int flag = 0;
    for(int i = 0; i < _size; i++){
        if (temp->p_lname() == s1) {
            unsigned int nday, nmonth, nhour, nminutes;
            cout << "Enter new data and time: " << endl;
            cout << "New data: ";
            cin >> nday >> nmonth;
            cout << endl;
            cout << "New time: ";
            cin >> nhour >> nminutes;
            cout << endl;
            temp->setDay(nday);
            temp->setMonth(nmonth);
            temp->setHour(nhour);
            temp->setMinutes(nminutes);
            flag = flag + 1;
        }
        temp = temp->next();    
    }
    if (flag = 0) {
        cout << "Patient is not found!" << endl;
    }
}

void List::search(string usearch) {
    Info* temp = head;
    string s1 = usearch;
    int flag = 0;
    for (int i = 0; i < _size; i++) {
        if (temp->p_lname() == s1) {
            cout << temp->d_spec() << " " << temp->d_lname() << " " << temp->d_fname() << " " << temp->p_lname() << " " << temp->p_fname() << " " << temp->day() << "." << temp->month() << " " << temp->hour() << ":" << temp->minutes() << endl;
            flag = flag + 1;
        }
        temp = temp->next();
    }
    if (flag = 0) {
        cout << "Patient is not found!" << endl;
    }
}

void List::output(string _filename)
{
    ofstream out(_filename, ios_base::out);
    if (out)
    {
       Info* temp = head; 

        while (temp != NULL)
        {
            
            out << temp->d_spec() << " " << temp->d_lname() << " " << temp->d_fname() << " " << temp->p_lname() << " " << temp->p_fname() << " " << temp->day() << "." << temp->month() << " " << temp->hour() << ":" << temp->minutes() << endl;

            temp = temp->next();
        }
        out.close();
    }
    else
        cout << "Error creating file!" << endl;
}
