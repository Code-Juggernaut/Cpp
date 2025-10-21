#include<iostream>
#include<ctime>
#include<stdlib.h>

#define array_size 4
using namespace std;

void create_array(int *array){
    srand(time(NULL));
    for(int i = 0;i<array_size;i++){
        *(array+i) = rand()%10;
    }
}
void copy_overload(int *from,int *to){
    for(int i = 0;i<array_size;i++){
        *(to+i) = *(from+i);
    }
}
void print(int *array){
    for(int i = 0;i<array_size;i++){
        cout<<*(array+i)<<" ";
    }
    cout<<'\n';
}
int main(){
    int *pointer_from = new int[array_size];
    int *pointer_to = new int[array_size];
    create_array(pointer_from);
    copy_overload(pointer_from,pointer_to);
    print(pointer_from);
    print(pointer_to);
}