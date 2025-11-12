#include<iostream>
using namespace std;
void calc(float *output,int number1,int number2,char operation){
    switch(operation){
        case '+':*output = number1+number2;break;
        case '-':*output = number1-number2;break;
        case '*':*output = number1*number2;break;
        case '/':*output = number1/number2;break;
    }
}
int main(){
    int number1 = 0;
    int number2 = 0;
    float out = 0;
    char operand;
    cin>>number1>>operand>>number2;
    calc(&out,number1,number2,operand);
    cout<<out;
}