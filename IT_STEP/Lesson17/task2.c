#include<stdio.h>
#include<stdlib.h>

struct Structure{
    int num1;
    char symbol;
};

int main(){
    FILE *file;
    file = fopen("program.bin","wb");
    struct Structure num1,num2[5];
    num1.num1= 10;
    num1.symbol = 'B';
    fwrite(&num1,sizeof(struct Structure),1,file);  
    for(int i =0 ;i<5;i++){
        num2[i].num1 = i;
        num2[i].symbol = i+'a';
    }
    fwrite(num2,sizeof(struct Structure),5,file);
    fclose(file);
    file = fopen("program.bin","rb");
    fread(&num1,sizeof(struct Structure),1,file);
    fread(num2,sizeof(struct Structure),5,file);
    printf("structure1:%d %c\n",num1.num1,num1.symbol);
    printf("Structure2:\n");
    for(int i = 0;i<5;i++){
        printf("%d %c\n",num2[i].num1,num2[i].symbol);
    }
}