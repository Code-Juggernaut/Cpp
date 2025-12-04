/**
 * CAUTION: USING random()
 * If not working replace random() with rand()
 */

#include<iostream>

using namespace std;

class Invalid_index:public exception{
    private:
        string message;
    public:
    Invalid_index(int pos,int size){
        message = "Array has size: "+to_string(size-1)+" but index "+to_string(pos)+"\n";
    }
    const char *what(){
        return message.c_str();
    }
};

template <typename t>

class Array{
    private:
        t *_data;
        int _size;
    public:

    Array(t data,int size):_size(size){
        _data = new t[size];
        for(int i = 0;i<_size;i++){
            _data[i] = data[i];
        }
    }
    Array(int size):_size(size){
        _data = new t[size];
    };
    
    ~Array(){
        delete[] _data;
        _size = 0;
    }
    t operator[](int pos){
        try{
            if(pos<_size && pos>0){
                return _data[pos];
            }else{
                throw(Invalid_index(pos,_size));
            }
        }
        catch(Invalid_index &error){
            cout<<error.what();
        }
        return -1;
    }


    void generate_random(){
        for(int i = 0;i<_size;i++){
            _data[i] = static_cast<t>(random()%100);
        }
    }
    void print_array(){
        for(int i = 0;i<_size;i++){
            cout<<_data[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Array <int>arr1(10);
    arr1.generate_random();
    arr1.print_array();
    cout<<arr1[10]; // throws -1
    cout<<arr1[2];// good
}