#ifndef book_H
#define book_H

#include<iostream>
#include<string.h>

using namespace std;


class Book{
    private:
    string _title;
    
    public:
    Book(const string &title);
    void print_title() const;
    void set_title(const string &title);
    ~Book();
};
#endif