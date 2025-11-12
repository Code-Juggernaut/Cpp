#include<iostream>
#include<fstream>
using namespace std;
class point{
    private:
    int _x;
    int _y;
    int _z;
    public:
    
    void edit(){
        cout<<"enter x:";
        cin>>_x;
        cout<<"enter y:";
        cin>>_y;
        cout<<"enter z:";
        cin>>_z;
    }
    void x_set (int x){
        _x = x;
    }
    void y_set (int y){
        _y = y;
    }
    void z_set (int z){
        _z = z;
    }

    int x_get (){
        return _x;
    }
    int y_get (){
        return _y;
    }
    int z_get (){
        return _z;
    }
    void print(){
        cout<<"x"<<_x<<endl;
        cout<<"y"<<_y<<endl;
        cout<<"z"<<_z<<endl;
    }
};

class point* reallocate(class point *pointer,int (*size)){
    class point *newpointer = new class point[(*size)+1];
    for(int i = 0;i<(*size);i++){
        newpointer[i] = pointer[i];
    }
    delete []pointer;
    pointer = nullptr;
    (*size)++;
    return newpointer;

}


int main(){
    int size  =1;
    class point *pointer;
    ifstream fin("database.txt");
    fin>>size;
    pointer = new class point[size];
    int buffer[3];
    for(int i = 0;i<size;i++){
        for(int i = 0;i<3;i++){
            fin>>buffer[i];
        }
        pointer[i].x_set(buffer[0]);
        pointer[i].y_set(buffer[1]);
        pointer[i].z_set(buffer[2]);
    }
    
    pointer = reallocate(pointer,&size);
    pointer[size-1].edit();
    for(int i = 0;i<size;i++){
        pointer[i].print();
    }
    fin.close();
    ofstream fout("database.txt");
    fout<<size<<'\n';
    for(int i = 0;i<size;i++){
        fout<<pointer[i].x_get()<<" "<<pointer[i].y_get()<<" "<<pointer[i].z_get()<<'\n';
    }
    fout.close();
}