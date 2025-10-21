#include"dynamic_mem.h"
template <typename templ>
bool is_simple(templ num){
    bool flag = 1;
    if(num == 1 or num == 0){
        flag = 0;
    }else{
        for(templ i = 2;i<num;i++){
            if(num%i == 0){
                flag = 0;
            }
        }
    }
    return flag;
}

template <typename templ>
templ *delete_simple_num(templ *&array,int &size){
    int pos = 0;
    while(pos<size){
        if(is_simple(array[pos]) == 1){
            delete_element(array,size,pos);
            
            std::cout<<'\n'<<"size:"<<size<<'\n';
        }else{
            pos++;
        }
    }
    
    return array;
}
int main(){
    int size = 10;
    int *pointer = create_memspace<int>(size);
    init_array(pointer,size);
    print(pointer,size);
    pointer = delete_simple_num(pointer,size);
    print(pointer,size);
    delete_array(pointer);
    std::cout<<size;
}