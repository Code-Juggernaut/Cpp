#include<iostream>
#include<stdio.h>
#include<stdint.h>
using namespace std;
uint8_t is_palindrom(char *buffer,int size){
    char *temp = (char*)malloc(size);
    for(int i = size-1;i>=0;i--){
        temp[i] = buffer[size-1-i];
    }
    for(int i = 0;i<size;i++){
        if(temp[i]!=buffer[i]){
            return 0xEE;
        }
    }
    return 0xAA;
}
int main(){
    char *ptr = (char*)malloc(1);
    int pos = 0;
    while(ptr[pos]!= '|'){
        scanf("%c",&ptr[pos]);
        if(ptr[pos] !='|'){
            pos++;
            ptr = (char*)realloc(ptr,(pos+1));
        }
    }
    is_palindrom(ptr,pos) == 0xAA?printf("Yes"):printf("No");
    
    free(ptr);
}