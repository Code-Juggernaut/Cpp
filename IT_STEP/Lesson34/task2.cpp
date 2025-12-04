#include<iostream>
#include<string.h>
#include<limits.h>
#include<stdint.h>
using namespace std;

int main(){
    string line;
    cin>>line;
    try{
        if(stoi(line)   >=INT16_MAX || stoi(line)<=INT16_MIN){
            throw out_of_range("Too long");
        }
        cout<<stoi(line);
    }   
    catch(const out_of_range &error){
        cout<<error.what();
    }
}