#ifndef LIST_H
#define LIST_H

#include "info.h"
#include <string>
using namespace std;

class List {
public:
    List();
    ~List();

    int size();

    void add(string d_spec, string d_lname, string d_fname, string p_lname, string p_fname, int day, int month, int hour, int minutes);
    void remove(int n);
    void printAll();
    void removeAll();
    void search(string usearch);

private:
    Info* head;
    int _size;
};

#endif // LIST_H
