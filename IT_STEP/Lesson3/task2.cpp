#include<iostream>
#include<cstring>
#include<stdint.h>
using namespace std;
int main(){
    int amount =0;
    string word;
    getline(cin,word);
    cin>>amount;
    while(amount>0){
        cout<<"\033[96m"<<word<<'\n';
        amount--;
    }
}