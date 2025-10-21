#include<iostream>
using namespace std;
int main(){
    int number1 = 20;
    int number2 = 10;
    int *pointer = &number1;
    int buffer = *pointer;
    *pointer = number2;
    number2 = buffer;
    cout<<number1<<" "<<number2;
}