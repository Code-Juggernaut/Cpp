#include"dynamic_mem.h"

int main(){
    int size = 5;
    int *pointer = create_memspace<int>(size);//chatgpt fix
    init_array(pointer,size);
    print(pointer,size);
    add_element(pointer,9,size);
    print(pointer,size);
    delete_element(pointer,size,6);
    print(pointer,size);
    paste_element(pointer,4,3,size);
    print(pointer,size);
    delete_array(pointer);
    print(pointer,size);    //null
}