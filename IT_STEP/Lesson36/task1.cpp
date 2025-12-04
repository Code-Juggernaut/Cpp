#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main(){
    int array[5] = {1,2,3,4,5};

    vector<int> vector1;
    cout<<vector1.max_size()<<endl;
    cout<<vector1.size()<<endl;

    vector1.clear();

    vector<int>vector2(5,4);
    cout<<vector2.capacity()<<endl<<vector1.capacity()<<endl;
    vector1.reserve(10);
    cout<<vector1.capacity()<<endl;
    vector2.resize(2);
    cout<<vector2.capacity()<<endl;
    vector<int>vector3 = vector2;
    vector<int>vector4(vector2);
    //vector<int>vector5(array[4]);
    vector<int>infine_vector;

    for(int i  =0;i<10;i++){
        infine_vector.push_back(i+1);
    }
    for(int i : infine_vector){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int>::iterator pointer(infine_vector.begin());

    while(pointer!=infine_vector.end()){
        cout<<*pointer<<" ";
        pointer++;
    }
    cout<<endl;
    pointer = infine_vector.begin();
    pointer+=2;

    infine_vector.insert(pointer,5,23);
    
    for(int i : infine_vector){
        cout<<i<<" ";
    }
    cout<<endl;


}