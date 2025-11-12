#include<iostream>
#include<sstream>
#include<stdint.h>
using namespace std;
int main(){
    char symbol;
    cin>>symbol;
    stringstream ss;
    ss<<hex<<static_cast<unsigned int>(symbol);
    cout<<"0x"<<ss.str()<<'\n';
    //cout<<0x61-1;

}