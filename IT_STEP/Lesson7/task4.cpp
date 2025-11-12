#include<iostream>
using namespace std;
template <typename t> t compare(t num1,t num2){
    return num1>num2 ? num1:num2;
}
int main(){
    cout<<compare(2,4)<<'\n';
    cout<<compare('a','b')<<'\n';
    cout<<compare(2.234,4.22245)<<'\n';
}