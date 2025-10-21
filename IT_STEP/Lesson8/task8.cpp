#include<iostream>
using namespace std;
int main(){
    int size = 10;
    int array[size] = {1,2,3,4,5,6,7,8,9,10};
    int *pointer = array;
    int buffer = 0;
    for(int i = 0;i<size-1;i+=2){
        buffer = pointer[i];
        pointer[i] = pointer[i+1];
        pointer[i+1] = buffer;
    }
    for(int i = 0;i<size;i++){
        cout<<*(pointer+i)<<" ";
    }
}