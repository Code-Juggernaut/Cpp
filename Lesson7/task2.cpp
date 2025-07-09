#include<iostream>
#include<cmath>
using namespace std;

#ifndef number
    #define number 1
#endif

#define POW(num,step) pow((num),(step))
int main(){
    long int sum = POW(number,5) + POW(number,3) + number;
    long long output = POW(sum,4);
    cout<<output;
}