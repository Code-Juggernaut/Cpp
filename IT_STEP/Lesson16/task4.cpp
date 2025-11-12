#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *file_in;
    file_in = fopen("input.prog","r");
    
    char *buffer = (char*)malloc(1);
    int counter = 0;
    char search = 'f';
    int flag = 0;
    int wordcount = 0;
    while((buffer[counter] = fgetc(file_in))!=EOF){
        if(buffer[0] == search){
            
            if(flag == 0){
                wordcount++;
            }
            flag = 1;
        }else{
            flag = 0;
            counter = 0;
        }
        if(buffer[counter] == ' ' || buffer[counter] == '\n'){
            flag  =0;
        }

    }
    fclose(file_in);
    printf("%d",wordcount);
    free(buffer);
}