#include<iostream>
#include<string.h>

using namespace std;

template<typename t>

class CPU{
    private:

    public:

    t process(const t &input){
        return input;
    }
    template<typename uni>
    uni convert(const t &input);
};

template <typename t>
class Printer{
    private:

    public:
    void print(const t &data){
        cout<<"========Kernel Printer_V2.0========="<<endl;
        cout<<data<<endl;
    }
    template<typename bin>
    void print_special(const bin &data){
        cout<<"========Binnary Printer_V2.0========="<<endl;
        cout<<data<<endl;
    }
};
template <>
template <>

void Printer<string>::print_special(const string &data){
    cout<<"========Text Printer_V2.0========="<<endl;
    cout<<data<<endl;
}
//====================== Functions ================
template<typename t>
template<typename uni>

uni CPU<t>::convert(const t &input){
    return static_cast<uni>(input); 
}

int main(){
    CPU <float>cpu0;
    cpu0.process(10.031);
    double result = cpu0.convert<double>(100.1);
    cout<<result<<endl;
    


    Printer <int>  print;
    print.print(123);
    print.print_special<float>(123.123);
    print.print_special("Hello World!");

    Printer <string> print_str;
    print_str.print("Hi");
    print_str.print_special<string>("->special case");
}