#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    FILE *file;
    file = fopen("file.prog","w");
    char symbol= ' ';
    while(symbol !='*'){
        symbol = getchar();
        fputc(symbol,file);
    }
    fclose(file);
    file = fopen("file.prog","r");
    while(!feof(file)){
        symbol = fgetc(file);
        cout<<symbol;

    }
    fclose(file);
}