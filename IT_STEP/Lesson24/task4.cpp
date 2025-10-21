#include<iostream>
#include<string.h>
using namespace std;
#include"reader.h"
// class Reader{
//     private:
//         char *_name;
//         int sizeof_name;
//         char **_books;
//         int _books_x;
//         int _books_y;
//     public:
//         Reader(const char *name,const char **books,int books_x,int books_y){
//             sizeof_name = strlen(name);
//             _name = new char[sizeof_name];
//             _books = new char*[_books_y];
//             for(int i = 0;i<_books_y;i++){
//                 _books[i] = new char[_books_x];
//             }
//         }
//         Reader(const Reader& _new){
//             sizeof_name = _new.sizeof_name;
//             _name = new char[sizeof_name];
//             _books_x = _new._books_x;
//             _books_y = _new._books_y;
//             _books = new char*[_books_y];
//             for(int i = 0;i<_books_y;i++){
//                 _books[i] = new char[_books_x];
//             }
//         }
//         Reader operator=(const Reader &_new){
//             for(int i = 0;i<_books_y;i++){
//                 delete[]_books[i];
//             }
//             delete[]_books;
//             delete[]_name;
//         }
//         ~Reader(){
//             delete[]_name;
//             for(int i = 0;i<_books_y;i++){
//                 delete[]_books[i];
//             }
//             delete[]_books;
//         }

//         void add_book(){
            
//         }
//     };

int main(){

}