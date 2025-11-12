#include"book.h"

Book::Book(const string &title):_title(title){
    
}
void Book::print_title()const {
    cout<<"title: "<<_title<<'\n';
}
void Book::set_title(const string &title){
    _title = title;
}
Book::~Book(){
    cout<<"deleted";
}