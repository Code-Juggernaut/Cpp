#include<iostream>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>

using namespace std;
struct student{
    uint16_t exam_stat; // n,n,n,n,n,n,0,0,0,0,0,0,0,0,0,0
    char ID[30];
    uint8_t mark; 

    void init(){
        cout<<"enter ID";
        cin>>ID;
        cout<<"\n enter exam state";
        cin>>exam_stat;
        exam_stat&=0x3FF;
        cout<<"enter mark";
        cin>>mark; 
        cout<<"completed!";
    }
    void get_data(){
        cout<<ID<<"\n"<<"exam_stat"<<((exam_stat&0x3ff)?"true":"false")<<"\n"<<"mark:"<<mark;

    }
    void get_ID(){
        cout<<ID;
    }
    uint16_t get_state(){
        return exam_stat;
    }
};

void add_struct(struct student **pointer,int *size){
    *pointer = (struct student*)realloc(*pointer,sizeof(struct student)*((*size)+1));
    
    (*pointer)[(*size)].init();
    (*size)++;
}

void print_names(struct student *pointer,int size){
    for(int i = 0;i<size;i++){
        pointer[i].get_ID();
        cout<<"\n";
    }
}

void print_owers(struct student *pointer,int size){
    for(int i = 0;i<size;i++){
        if(pointer[i].exam_stat != 0x3ff){
            pointer[i].get_ID();
            cout<<"\n";
        }
    }
}

int main(){
    int size = 1;
    struct student *pointer = (struct student*)malloc(sizeof(struct student)*size);
    pointer[size-1].init();
    add_struct(&pointer,&size);
    add_struct(&pointer,&size);
    /*add_struct(pointer,&size);
    add_struct(pointer,&size);*/
    cout<<"\nNAMES\n";
    print_names(pointer,size);
    cout<<"\nOWERS\n";
    print_owers(pointer,size);
    free(pointer);
}