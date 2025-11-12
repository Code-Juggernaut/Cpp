#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    FILE *file_in;
    FILE *file_out;
    file_in = fopen("input.prog","r");
    file_out = fopen("file.prog","w");
    char *buffer = (char*)malloc(1);
    int counter = 0;
    while((buffer[counter] = fgetc(file_in))!= EOF){
        
        if(buffer[counter] == ' ' || buffer[counter] == '\n'){
            if(counter >=6){
                buffer = (char*)realloc(buffer,counter+1);
                buffer[counter+1] = '\0';
                for(int i = 0;i<counter;i++){
                    fputc(buffer[i],file_out);
                }
                fputc('\n',file_out);
            }
            counter = 0;
        }else{
            counter++;
            buffer = (char*)realloc(buffer,counter+1);
        }
    }
    fclose(file_in);
    fclose(file_out);
    free(buffer);
}