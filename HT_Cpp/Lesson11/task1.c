#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#include"libs/str_functions.h" // please link before use
// command to compile : g++ taskx.c libs\str_functions.c 

int main(){
    uint8_t size = 0;
    printf("Enter string( max 256 symbols)\n");
    char* pointer = (char*)malloc(1);
    while(pointer[size]!='.'){
        scanf("%c",&pointer[size]);
        if(pointer[size]!='.'){
            size++;
            pointer = (char*)realloc(pointer,size);
        }
    }
    uint8_t pos = 0;
    printf("Enter delete pos(!Note min = 0 max = 255)\n");
    scanf("%hhd",&pos);
    pointer =(char*) delete_char(pos,pointer,&size);
    for(uint8_t i = 0;i<size;i++){
        printf("%c",pointer[i]);
    }
    free(pointer);
}