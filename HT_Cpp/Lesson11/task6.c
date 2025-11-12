#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"libs/str_functions.h" // please link before use

int main(){
    uint8_t size =0;
    printf("Enter string( max 255 symbols terminator:'|')\n");
    char* pointer = (char*)malloc(1);
    while(pointer[size]!='|'){
        scanf("%c",&pointer[size]);
        if(pointer[size]!='|'){
            size++;
            pointer = (char*)realloc(pointer,size);
        }
    }


    uint8_t howmany_nums = find_howmany_nums(pointer,&size);
    uint8_t howmany_letters = find_howmany_letters(pointer,&size);
    uint8_t howmany_symbols = find_howmany_symbols(pointer,&size);
    printf("chars in string = %hhd \n nums in string = %hhd \n symbols in string = %hhd",howmany_letters,howmany_nums,howmany_symbols);
    
    free(pointer);
}