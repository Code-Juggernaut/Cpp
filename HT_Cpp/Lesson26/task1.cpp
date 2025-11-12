#include<iostream>
#include<string.h>

using namespace std;

class overcoat{
    string _type;
    int _price;
    public:
    overcoat(string type, int price):_type(type),_price(price){

    };
    overcoat(){

    }
    bool  operator==(class overcoat &other){
        if(_type == other._type){
            return 1;
        }else {
            return 0;
        }
    }
    class overcoat operator=(class overcoat &other){
        if(this != &other){
            _type = other._type;
            _price = other._price;
        }
        return *this;
    }
    bool operator<(class overcoat &other){
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
    overcoat obj1("Coat",33);
    overcoat obj2("Dress",50);

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
