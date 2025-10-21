#include<iostream>
#include<ctime>
#include<stdlib.h>
template<typename templ>
templ* create_memspace(int size){
    return new templ[size];
}

template<typename templ>
void init_array(templ *array,int size){
    srand(time(NULL));
    for(int i = 0;i<size;i++){
        array[i] = rand()%10-5;
    }
}

template<typename templ>
void print(templ *array,int size){
    for(int i = 0;i<size;i++){
        std::cout<<array[i]<<" ";
    }
    std::cout<<'\n';
}

template<typename templ>
void delete_array(templ *&array){
    delete[] array;
    array = NULL;
}

template<typename templ>
void add_element(templ *&array,templ symbol,int &size){
    templ *buff  = new templ[size+1];
    for(int i = 0;i<size;i++){
        buff[i] = array[i];
    }
    buff[size] = symbol;
    delete[] array;
    array = buff;
    size++;
}

template<typename templ>
void paste_element(templ *&array,templ symbol,int pos,int &size){
    templ *buff = new templ[size+1];
    for(int i = 0;i<pos;i++){
        buff[i]  =array[i];
    }
    buff[pos] = symbol;
    for(int i = pos+1;i<size+1;i++){
        buff[i] = array[i-1];
    }
    delete[] array;
    array = buff;
    size++;
}

template<typename templ>
void delete_element(templ *&array,int &size,int pos){
    templ *buff = new templ[size-1];
    for(int i = 0;i<pos;i++){
        buff[i] = array[i];
    }
    for(int i = pos+1;i<size;i++){
        buff[i-1] = array[i];
    }
    delete[] array;
    array = buff;
    size--;
}