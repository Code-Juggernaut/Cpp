#include<iostream>
using namespace std;
int main(){
    int number1 = 10;
    int number2 = 40;
    int *pointer =&number1;
    int *pointer2 = &number2;
    if(*pointer > *pointer2){
        cout<<*pointer;
    }else{
        cout<<*pointer2;
    }
}