#include<iostream>
using namespace std;
int main(){
    int value = 10;
    int *pointer = &value;
    int **pointer_to_pointer = &pointer;
    int &address = value;
    
    cout<<value<<" "<<address;
    int array[5] = {1,2,3,4,5};
    int *point;
    point = array;
    *(point+1) = 2130;
    cout<<'\n'<<*(point+1)<<" "<<*(point+2)<<" "<<array[1];
}