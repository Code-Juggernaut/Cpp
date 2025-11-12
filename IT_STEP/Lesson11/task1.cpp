#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    char symbol= 0;
    for(int i = 0;i<255;i++){
        printf("%c",symbol);
        symbol++;
    }
}