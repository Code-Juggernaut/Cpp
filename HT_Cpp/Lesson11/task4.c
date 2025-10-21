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
    char letter = ' ';
    printf("enter letter to replace\n");
    scanf("\n%c",&letter);
    char replace = 0;
    printf("enter you want place instead %c\n",letter);
    scanf("\n%c",&replace);
    pointer = (char*)replace_char(letter,replace,pointer,&size);
    
    for(uint8_t i = 0;i<size;i++){
        printf("%c",pointer[i]);
    }
    free(pointer);
}