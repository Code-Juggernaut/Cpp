#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string value;
    float amount;
    cout<<"\033[93m -------CURRENCY EXCHANGE------\n";
    start:
    cout<<">_enter currency:";
    cin>>value;
    error:
    cout<<">_enter value:";
    cin>>amount;
    
    if(amount == 0){
        cout<<"\n\033[91m>_ERROR\033[93m\n";
        amount = 1;
        goto start;
    }
    cout<<"\033[96m";
    if(value == "USD"){
        cout<<">_USD->UAH\033[98m"<<amount*44.05;
    }else if(value == "EUR"){
        cout<<">_EUR->UAH\033[98m"<<amount*47.05;
    }else if(value == "GBP"){
        cout<<">_GBP->UAH\033[98m"<<amount*56.12;
    }else if(value == "USDT"){
        cout<<">_USDT->UAH\033[98m"<<amount*41.05;
    }else{
        cout<<"\n\033[91m>_ERROR\033[93m\n";
        goto start;
    }
}