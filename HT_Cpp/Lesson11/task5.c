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
    printf("enter letter to find\n");
    scanf("\n%c",&letter);

    uint8_t howmany_chars = find_howmany_char(letter,pointer,&size);
    
    
    printf("%d",howmany_chars);
    
}