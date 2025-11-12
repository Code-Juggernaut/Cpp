#include"dynamic_mem.h"


int size = 10;

template <typename templ>
void is_null(templ *array,templ *&dynamic_array,int &null_size){
    for(int i =0;i<size;i++){
        if(array[i] == 0){
            add_element(dynamic_array,array[i],null_size);
        }
    }
}
template <typename templ>
void is_plus(templ *array,templ *&dynamic_array,int &plus_size){
    for(int i =0;i<size;i++){
        if(array[i] > 0){
            add_element(dynamic_array,array[i],plus_size);
        }
    }
}
template <typename templ>
void is_minus(templ *array,templ *&dynamic_array,int &minus_size){
    for(int i =0;i<size;i++){
        if(array[i] < 0){
            add_element(dynamic_array,array[i],minus_size);
        }
    }
}
int main(){
    
    int array[size];
    int null_size  =0;
    int plus_size  =0;
    int minus_size = 0;
    int *pointer_to_array = array;
    init_array(pointer_to_array,size);
    int *pointer_to_null = new int;
    int *pointer_to_plus = new int;
    int *pointer_to_minus = new int;
    print(pointer_to_array,size);

    is_null(pointer_to_array,pointer_to_null,null_size);
    print(pointer_to_null,null_size);
    is_plus(array,pointer_to_plus,plus_size);
    print(pointer_to_plus,plus_size);
    is_minus(pointer_to_array,pointer_to_minus,minus_size);
    print(pointer_to_minus,minus_size);
}