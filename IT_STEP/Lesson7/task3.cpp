#include<iostream>
using namespace std;
#ifndef ARR_SIZE
#define ARR_SIZE 3
#endif
#define __MIN__(a,b) ((a<b) ?  (a):(b) )
#define __IS_EVEN__(a) ((a%2 == 0 )? 1:0)
#define newline '\n'
int main(){
    int arr[ARR_SIZE];
    for(int i = 0;i<ARR_SIZE;i++){

        cin>>arr[i];
    }
    int min = 0;
    for(int i  = 1;i<ARR_SIZE;i++){
        min = __MIN__(arr[i-1],arr[i]);
        
    }
    cout<<min<<newline;
    cout<<__MIN__(3,4)<<newline;
    cout<<__IS_EVEN__(4)<<newline;
}