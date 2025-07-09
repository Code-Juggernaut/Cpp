#include <iostream>
#include <stdint.h>
#include <cstring>
using namespace std;
int main(){
    string var;
    cout<<"enter your name"<<'\n';
    getline(cin,var);
    //cin>>var;
    cout<<"Hello "<<var<<" Welcome"<<'\n';
    cout<<"\033[91m"<<"Hi my name is Code"<<'\n'<<'\t'<<'\t'<<"Juggernaut";
    cout<<"\033[90m";
}