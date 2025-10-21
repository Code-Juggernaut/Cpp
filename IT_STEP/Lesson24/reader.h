#pragma once;

#include<iostream>
#include<string.h>
using namespace std;

class Reader{
    private:
        char *_name;
        int sizeof_name;
        char **_books;
        int _books_x;
        int _books_y;
    public:
        Reader(const char *name,const char **books,int books_x,int books_y){
        }
        Reader(const Reader& _new){
        }
        Reader operator=(const Reader &_new){
            for(int i = 0;i<_books_y;i++){
                delete[]_books[i];
            }
            delete[]_books;
            delete[]_name;
        }
        ~Reader(){
            
        }

        void add_book(){
            
        }
    };
