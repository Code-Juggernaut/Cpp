#include<stdio.h>
#include<string.h>
#include<iostream>
char str_base[] = "NULL\0";
char buffer[10];
int main(){
    str_base[0] = 'C';
    printf("str = %s",str_base);
    scanf("%s",buffer);
    printf("\n%s",buffer);
    fgets(buffer,sizeof(buffer),stdin);

}