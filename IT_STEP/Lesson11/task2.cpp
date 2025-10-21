#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
void change_symbol(char* buffer,int size){
    for(int i = 0;i<size;i++){
        if(buffer[i]==' '){
            buffer[i] = '\t';
        }
    }
}
int main(){
    char *ptr = (char*)malloc(sizeof(char));
    char terminator;
    int pos = 0;
    while(ptr[pos]!='|'){
        pos++;
        ptr = (char*)realloc(ptr,pos+1);
        //ptr[pos];
        scanf("%c",&ptr[pos]);
    }

    ptr = (char*)realloc(ptr,pos+1);
    ptr[pos+1] = '\0';
    change_symbol(ptr,pos+1);
    for(int i = 0;i<pos;i++){
        cout<<ptr[i];
    }
    free(ptr);
}