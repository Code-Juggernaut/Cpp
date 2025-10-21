#include<iostream>
using namespace std;
int main(){
    float num1=0,num2 =0;
    char symbol;
    cout<<"\033[93m-------Calculator--------\n";
    cout<<"enter number 1:";
    cin>>num1;
    error:
    cout<<"enter operator:";
    cin>>symbol;
    cout<<"enter number 2:";
    cin>>num2;
    cout<<"\033[94m";
    switch(symbol){
        case '+':cout<<"sum = \033[96m"<<num1+num2;break;
        case '-':cout<<"riz = \033[96m"<<num1-num2;break;
        case '*':cout<<"multiply = \033[96m"<<num1*num2;break;
        case '/':cout<<"division = \033[96m";
        if(num1!=0 && num2!=0){
            cout<<num1/num2;
        }else{
            cout<<"\033[91m DIV on ZERO\n";
            goto error;
        }break;
        default:cout<<"\033[91m NOT FOUND\n"; goto error;break;
    }
    delete &symbol,&num2,&num1;
}