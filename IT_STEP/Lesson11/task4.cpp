#include<stdio.h>
#include<stdlib.h>
int howmany_words(char* buffer,int size){
    int word_len = 1;
    for(int i= 0;i<size;i++){
        if(buffer[i] == ' '){
            word_len++;
        }
    }
    return word_len;
}
int main(){
    char *ptr = (char*)malloc(1);
    int pos = 0;
    int isfirst = 1;
    while(ptr[pos]!= '.' ){
        read:
        scanf("%c",&ptr[pos]);
        if((ptr[pos] == ' ' || ptr[pos] == '\t' )&& isfirst == 1){
            goto read;
        }else{
            isfirst = 0;
        }
        if(ptr[pos] !='.'){
            pos++;
            ptr = (char*)realloc(ptr,(pos+1));
        }
    }
    printf("%d",howmany_words(ptr,pos));
}