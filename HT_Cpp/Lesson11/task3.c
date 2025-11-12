#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#include"libs/str_functions.h" // please link before use

int main(){
    uint8_t size =0;
    printf("Enter string( max 254 symbols terminator:'.')\n");
    char* pointer = (char*)malloc(1);
    while(pointer[size]!='.'){
        scanf("%c",&pointer[size]);
        if(pointer[size]!='.'){
            size++;
            pointer = (char*)realloc(pointer,size);
        }
    }
    char letter = ' ';
    printf("enter letter to paste\n");
    scanf("\n%c",&letter);
    uint8_t pos = 0;
    printf("enter where you want to paste letter\n");
    scanf("%hhd",&pos);
    pointer = (char*)paste_char(pos,letter,pointer,&size);
    if(pointer == NULL){
        printf("\033[91mError -WOverflow");
    }
    for(uint8_t i = 0;i<size;i++){
        printf("%c",pointer[i]);
    }
    free(pointer);
}