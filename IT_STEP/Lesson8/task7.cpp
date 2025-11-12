#include<iostream>
using namespace std;
int main(){
    int array[5] = {3,2,4,1,2};
    int *pointer = array;
    int sum = 0;
    for(int i = 0;i<5;i++){
        sum+=*(pointer+i);
    }
    cout<<sum;
}