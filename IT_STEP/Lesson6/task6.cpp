#include<iostream>
using namespace std;
void array_get(int array[],int size){
    for(int i = 0;i<size;i++){
        cout<<array[i]<<" ";
    }
}
int main(){
    int array[4] = {0,3,6,1};
    array_get(array,4);
}