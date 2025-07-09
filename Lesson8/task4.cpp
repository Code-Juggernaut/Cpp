#include<iostream>
using namespace std;
int main(){
    int value;
    cin>>value;
    int *pointer=&value;
    if(*pointer>0){
        cout<<">0";
    }else if(*pointer == 0){
        cout<<" = 0";
    }else{
        cout<<"<0";
    }
}