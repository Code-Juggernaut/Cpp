#include<iostream>
#include<stdint.h>
using namespace std;
int main(){
    int year = 0;
    cout<<"Enter your age :";
    cin>>year;
    cout<<"\033[93mYou are:";
    switch(year){
        case 0 ... 11:cout<<"\033[96mchild";break;
        case 12 ... 17:cout<<"\033[94mteen";break;
        case 18 ... 64:cout<<"\033[92madult";break;
        default:cout<<"\033[91mold";break;
    }
}