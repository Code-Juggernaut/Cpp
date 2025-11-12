#include<iostream>

using namespace std;

class Complex{
    private:
        double number;
    public:

    Complex(double num):number(num){

    }
    Complex(){
        number = 0.00;
    }
    class Complex operator+(const class Complex &other){
        return Complex(this->number+other.number);
    }

    class Complex operator-(const class Complex &other){
        return Complex(this->number - other.number);
    }
    class Complex operator*(const class Complex &other){
        return Complex(this->number * other.number);
    }
    class Complex operator/(const class Complex &other){
        if(other.number == 0 || this->number == 0){
            return *this;
        }
        return Complex(this->number/other.number);
    }
    class Complex &operator=(const class Complex &other){
        if(this != &other){
            number = other.number;
        }
        
        return *this;
    }
    double getnum(){
        return number;
    }
};

int main(){
    class Complex num1(9.94530);
    class Complex num2(3.14159265);
    class Complex result;

    result = num1 - num2;
    cout<<num1.getnum()<<" - "<<num2.getnum()<<" = "<<result.getnum()<<endl;
    result = num1 + num2;
    cout<<num1.getnum()<<" + "<<num2.getnum()<<" = "<<result.getnum()<<endl;
    result = num1 / num2;
    cout<<num1.getnum()<<" / "<<num2.getnum()<<" = "<<result.getnum()<<endl;
    result = num1 * num2;
    cout<<num1.getnum()<<" * "<<num2.getnum()<<" = "<<result.getnum()<<endl;
}