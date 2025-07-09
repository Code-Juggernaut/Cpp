#include<iostream>
using namespace std;
int main(){
    int *pointer = new int(10);
    char *pointer_to_string = new char[10];
    for(int i = 0;i<10;i++){
        cin>>*(pointer_to_string+i);
    }
    cout<<*pointer_to_string;
    cout<<*pointer;
    *pointer = 23;
    cout<<'\n'<<*pointer;
    delete pointer;
    delete []pointer_to_string;
}