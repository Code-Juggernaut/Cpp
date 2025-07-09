#include<iostream>
using namespace std;
int is_higher(int number1,int number2){
    if(number1>number2){
        return number1;
    }else if(number1 == number2){
        return 0;
    }else{
        return number2;
    }
}
int main(){
    int num1 = 0,num2 = 0;
    cout<<"Enter two numbers";
    cin>>num1>>num2;
    if(is_higher(num1,num2) == 0){
        cout<<"none";
    }else{
        cout<<"high number is: "<<is_higher(num1,num2);
    }
}