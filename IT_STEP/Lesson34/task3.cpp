#include<iostream>
#include<new>
#include<string.h>
using namespace std;

class array_exception:public exception{
    private:
        string message;
    public:
        array_exception(size_t size,int index){
            message = "array_exception: Index "+to_string(index)+" out of bounds";
        }
        const char *what()const noexcept{
            return message.c_str();
        }
};



int get_val(int *array, size_t size,int pos){
    if(pos<0 || pos>size){
        throw array_exception(size,pos);
    }
    return array[pos];
}


int main(){
    
    size_t size = static_cast<size_t>(3);

    int *arr = new int [size]{5,10,15};

    try{
        int value  = get_val(arr,size,10);
        cout<<value;
    }
    catch(const bad_alloc &error){
        cout<<"bad array length"<<error.what();
    }
    catch(const array_exception &error){
        cout<<error.what();
    }
    catch(const exception &error){
        cout<<"Error "<<error.what();
    }
    delete[] arr;
}