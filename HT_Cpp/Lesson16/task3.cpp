#include<stdio.h>

int main(){
    FILE *filein = fopen("input.prog","r");
    FILE *fileout = fopen("output.prog","w");
    char symbol;
    int pos;
    printf("enter shift amount:");
    scanf("%d",&pos);
    while(!feof(filein)){
        symbol = fgetc(filein);
        if(symbol>='a' && symbol<='z'){
            symbol = (symbol-'a'+pos )%26+'a';
        }else if(symbol >='A' && symbol<='Z'){
            symbol = (symbol - 'A'+pos)%26+'A';
        }
        fprintf(fileout,"%c",symbol);
    }
    fclose(filein);
    fclose(fileout);
}