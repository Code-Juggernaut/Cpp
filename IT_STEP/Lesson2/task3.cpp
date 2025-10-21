#include<iostream>
using namespace std;
int main(){
    int key;
    cin>>key;
    switch(key){
        case 0:cout<<"Hello";break;
        case 1:cout<<"bye";break;
        case 2:cout<<"how are you?";break;
        default:cout<<"not found";break;
    }
    char chars = ' ';
    cin>>chars;
    switch(chars){
        case 'a':cout<<"apelsin";break;
        case 'b':cout<<"banana";break;

    }
}