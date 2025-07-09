#include<iostream>
using namespace std;
//---------------------------block1
void func();

int sum(int number1, int number2);
//----------------------------block2
int main(){
    
    func();
    int summa = sum(3,4);
    cout<<"\033[95m"<<"Sum = "<<summa;
    int num1 = 5;
    int num2 = 100;
    cout<<"\033[96m\n"<<"Sum = "<<sum(num1,num2);

}
//----------------------------block3
void func(){
    cout<<"hello\n";
}

int sum(int number1, int number2){
    int sum = 0;
    sum = number1+number2;
    return sum;
}