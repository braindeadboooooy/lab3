#include "list.h"
#include <iostream>
#include <cstring>

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
    if (head == NULL || n > _size)
        return;
    

    for (int i = 0; i < n - 1; i++)
        temp = temp->next();

 
    Info* delEl = temp->next();
    temp->setNext(delEl->next());

    delete delEl;
}

void List::printAll() {
    Info* temp = head;
    while (temp != NULL) {
        cout << temp->d_spec() << " "<< temp->d_lname() << " " << temp->d_fname() << " " << temp->p_lname() << " " << temp->p_fname() << " " << temp->day() << "." << temp->month() << " " << temp->hour() << ":" << temp->minutes() << endl ;
        temp = temp->next();
    }
}


void List::search(string usearch) {
    Info* temp = head;
    string s1 = usearch;
    
    for(int i = 0; i < _size; i++){
        if (temp->p_lname() == s1) {
            cout << temp->d_spec() << " " << temp->d_lname() << " " << temp->d_fname() << " " << temp->p_lname() << " " << temp->p_fname() << " " << temp->day() << "." << temp->month() << " " << temp->hour() << ":" << temp->minutes() << endl;
            break;
        }
        temp = temp->next();    
    }
}
