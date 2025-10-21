#include<iostream>
#include<stdint.h>
using namespace std;

void function(){
    printf("%s","Hello World! ");
}
void printNum(){
    printf("%d",132);
}
int main(){
    
    void (*ptr)();
    ptr = &function;

    ptr();
    
    ptr = &printNum;
    ptr();
    
}