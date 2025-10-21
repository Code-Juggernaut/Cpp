#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
    FILE *file1;
    FILE *file2;

    file1 = fopen("input.prog","r");
    file2 = fopen("input2.prog","r");
    char *firstline = (char*)malloc(1);
    int fpos = 0;
    int spos = 0;
    char *secondline = (char*)malloc(1);
    
    while(!feof(file1)){
        firstline[0] = fgetc(file1);
        while(firstline[fpos]!= '.'){
            firstline[fpos] = fgetc(file1);
            if(firstline[fpos]!= '.'){
                fpos++;
                firstline = (char*)realloc(firstline,fpos+1);
            }
        }
        firstline[fpos] = '\0';
        secondline[0] = fgetc(file2);
        while(secondline[spos]!= '.'){
            secondline[spos] = fgetc(file2);
            if(secondline[spos]!= '.'){
                spos++;
                secondline = (char*)realloc(secondline,spos+1);
            }
        }
        secondline[spos] = '\0';
        if(strcmp(firstline,secondline)){
            printf("%s != %s",firstline,secondline);
        }
        firstline = (char*)realloc(firstline,1);
        spos = 0;
        secondline = (char*)realloc(secondline,1);
        fpos =0;
    }
    free(firstline);
    free(secondline);
    fclose(file1);
    fclose(file2);
}