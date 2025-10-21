#include<iostream>
using namespace std;
#define size 4
void sum_and_mult(int *arr,int &sum,int &mult){
    for(int i = 0;i<size;i++){
        sum+=*(arr + i);
        mult*=*(arr+i);
    }
}
int main(){
    int sum = 0;
    int mult = 1;
    int arr[size] = {3,4,2,1};
    sum_and_mult(arr,sum,mult);
    cout<<sum<<" "<<mult;
}   