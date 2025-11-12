#include<iostream>
#include<string.h>

using namespace std;

class flat{
    string _type;
    int _price;
    int _square;
    public:
    flat(string type, int price,int square):_type(type),_price(price),_square(square){

    };
    flat(){

    }
    bool  operator==(class flat &other){
        if(_square == other._square){
            return 1;
        }else {
            return 0;
        }
    }
    class flat operator=(class flat &other){
        if(this != &other){
            _type = other._type;
            _price = other._price;
            _square = other._square;
        }
        return *this;
    }
    bool operator<(class flat &other){
        if(_price<other._price){
            return 1;
        }else{
            return 0;
        }
    }
    string get()const{
        return _type;
    }
};


int main(){
    flat obj1("Flat",33,120);
    flat obj2("House",50,400);

    cout<<obj1.get()<<endl;
    cout<<obj2.get()<<endl;
    if(obj1<obj2){
        cout<<obj1.get()<<"<"<<obj2.get()<<endl;
    }else{
        cout<<obj1.get()<<">"<<obj2.get()<<endl;
    }
    if(obj1 == obj2){
        cout<<obj1.get()<<" == "<<obj2.get()<<endl;
    }else{
        cout<<obj1.get()<<"!="<<obj2.get()<<endl;
    }
    obj1 = obj2;
    cout<<obj1.get()<<endl;
    cout<<obj2.get()<<endl;
}   
