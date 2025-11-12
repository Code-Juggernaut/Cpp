#include<iostream>
#include<string.h>

using namespace std;

template<typename t>
class Container{
    private:
        t value;
    public:

    void set(t val){
        value = val;
    }
    t get() const {
        return value;
    }
};

int main(){
    Container <int>cont;
    int buffer = 42;
    cout<<"enter buffer";
    cont.set(buffer);
    cout<<cont.get()<<endl;
    
    Container <string> cont2;
    string message = "Hello World!";

    cont2.set(message);
    cout<<cont2.get()<<endl;
}